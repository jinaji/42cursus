/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:54 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/06 16:02:46 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node{
	int				idx;
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque{
	int				count;
	struct s_node	*front;
	struct s_node	*rear;
}	t_deque;

// argu_check
void	is_str_digit(char *str);
int		get_all_len(char **av);
char	*ft_str_join(int ac, char **av);
int		ft_atoll(char *str);
int		argument_check(int ad, char **av, t_deque **deq_a);

// main
void	ft_error(void);
void	add_new_node(int val, t_deque **deq);
void	indexing_argument(t_deque **deq_a);
int		main(int ac, char **av);

// sort
void	sort_with_pivot(t_deque **deq_a, t_deque **deq_b);
int		get_min_location(t_deque **deq_a);
void	sort_last(t_deque **deq_a);
void	sort_init(t_deque **deq_a, t_deque **deq_b);
void	get_sort(t_deque **deq_a, t_deque **deq_b);

// deque utils
int		is_deq_empty(t_deque *deq);
void	deq_init(t_deque **deq);
void	free_deque(t_deque **deq);

// deque
void	insert_deq_front(t_deque **deq, t_node *new);
void	insert_deq_rear(t_deque **deq, t_node *new);
t_node	*delete_deq_front(t_deque **deq);
t_node	*delete_deq_rear(t_deque **deq);

//push
void	push_a(t_deque **deq_a, t_deque **deq_b);
void	push_b(t_deque **deq_a, t_deque **deq_b);

//swap
void	swap_a(t_deque **deq_a);
void	swap_b(t_deque **deq_b);
void	swap_all(t_deque **deq_a, t_deque **deq_b);

//rotate
void	rotate_a(t_deque **deq_a, int *comm_a);
void	rotate_b(t_deque **deq_b, int *comm_b);
void	rotate_all(t_deque **deq_a, t_deque **deq_b, int *comm_a, int *comm_b);

//rrotate
void	rrotate_a(t_deque **deq_a, int *comm_a);
void	rrotate_b(t_deque **deq_b, int *comm_b);
void	rrotate_all(t_deque **deq_a, t_deque **deq_b, int *comm_a, int *comm_b);

// sort_three
int		get_case_three(int val1, int val2, int val3);
void	get_three_sort(t_deque **deq_a, int flag);
void	sort_three(t_deque **deq_a, t_deque **deq_b);

// sort_utils
int		is_sorted(t_deque **deq);
int		get_a_command(int idx, t_deque **deq_a);
int		get_rr_count(int i, int j);
int		compare_count(int comm_a, int comm_b, int cnt_a, int cnt_b);
void	count_command(t_deque **deq_a, t_deque **deq_b, int *com_a, int *com_b);

#endif