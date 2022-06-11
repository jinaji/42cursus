/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:28:12 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/11 14:32:17 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node_{
	int					fd;
	char				*str;
	struct s_node_		*next;
}				t_node_;

typedef struct s_node{
	int				idx;
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_deque{
	int				count;
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// checker
void		ft_error(void);
void		swap(t_deque **deq_a, t_deque **deq_b, char *comm);
void		push(t_deque **deq_a, t_deque **deq_b, char *comm);
void		rrotate(t_deque **deq_a, t_deque **deq_b, char *comm);
void		rotate(t_deque **deq_a, t_deque **deq_b, char *comm);
void		compare_and_do_sort(t_deque **deq_a, t_deque **deq_b, char **comm);
int			get_all_len(char **av);
char		*ft_str_join(int ad, char **av);
void		split_command(t_deque **deq_a, t_deque **deq_b, int ac, char **av);
int			main(int ad, char **av);

// deque_bonus
void		insert_deq_front(t_deque **deq, t_node *new);
void		insert_deq_rear(t_deque **deq, t_node *new);
t_node		*delete_deq_front(t_deque **deq);
t_node		*delete_deq_rear(t_deque **deq);

// deque_utils_bonus
int			is_deq_empty(t_deque *deq);
void		deq_init(t_deque **deq);
void		free_deque(t_deque **deq);

// push_bonus
void		b_push_a(t_deque **deq_a, t_deque **deq_b);
void		b_push_b(t_deque **deq_a, t_deque **deq_b);

// rotate_bonus
void		b_rotate_a(t_deque **deq_a, int *comm_a);
void		b_rotate_b(t_deque **deq_b, int *comm_b);
void		b_rotate_all(t_deque **deq_a, t_deque **deq_b, int *a, int *b);

// rrotate_bonus
void		b_rrotate_a(t_deque **deq_a, int *comm_a);
void		b_rrotate_b(t_deque **deq_b, int *comm_b);
void		b_rrotate_all(t_deque **deq_a, t_deque **deq_b, int *a, int *b);

// sort_utils_bonus
int			is_sorted(t_deque **deq);

// swap_bonus
void		b_swap_a(t_deque **deq_a);
void		b_swap_b(t_deque **deq_b);
void		b_swap_all(t_deque **deq_a, t_deque **deq_b);

// get_next_line
int			get_index(char *str);
char		*ft_strndup(char *buff, int idx);
char		*delete_static(char *str);
char		*gnl_strjoin(char *str, char *buff);

t_node_		*getnode(t_node_ **lst, int fd);
char		*get_return(char **str);
void		free_all(t_node_ **lst, int fd);
int			make_line(t_node_ **lst, int fd, char *buff, char **tmp);
char		*get_next_line(int fd);

#endif