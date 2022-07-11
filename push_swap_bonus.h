/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:28:12 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/07 19:26:55 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

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

// argu_check_bonus
void		is_str_digit(char *str);
int			get_all_len(char **av);
char		*ft_str_join(int ad, char **av);
int			ft_atol(char *str);
int			argument_check(int ad, char **av, t_deque **deq_a);

// checker
void		ft_error(void);
void		add_new_node(int val, t_deque **deq);
void		indexing_argument(t_deque **deq_a);
void		swap(t_deque **deq_a, t_deque **deq_b, char *comm);
void		push(t_deque **deq_a, t_deque **deq_b, char *comm);
void		rrotate(t_deque **deq_a, t_deque **deq_b, char *comm);
void		rotate(t_deque **deq_a, t_deque **deq_b, char *comm);
void		compare_and_do_sort(t_deque **deq_a, t_deque **deq_b);
int			get_all_len(char **av);
char		*ft_str_join(int ad, char **av);
void		split_command(t_deque **deq_a, t_deque **deq_b, int ac, char **av);
int			main(int ad, char **av);

// count command bonus
int			count_a_command(t_deque **deq_a, int idx);
int			get_a_command(int idx, t_deque **deq_a);
int			compare_count(int comm_a, int comm_b, int cnt_a, int cnt_b);
void		count_command(t_deque **deq_a, t_deque **deq_b, int *com_a, int *com_b);

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

// sort_bonus
void		sort_with_pivot(t_deque **deq_a, t_deque **deq_b);
int			get_first_index(t_deque **deq_a);
void		sort_last(t_deque **deq_a);
void		sort_init(t_deque **deq_a, t_deque **deq_b);
void		get_sort(t_deque **deq_a, t_deque **deq_b);

// sort_utils_bonus
int			is_sorted(t_deque **deq);
int			get_min_idx(t_deque **deq_a);
int			get_max_idx(t_deque **deq_a);
int			get_min_location(t_deque **deq_a, int min_idx);
int			get_max_location(t_deque **deq_a, int max_idx);

// sort_three_bonus
int			get_case_three(int val1, int val2, int val3);
void		get_three_sort(t_deque **deq_a, int flag);
void		sort_three(t_deque **deq_a, t_deque **deq_b);

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