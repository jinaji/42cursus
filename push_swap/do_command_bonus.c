/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:11:58 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/12 03:02:11 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "sa", 3) == 0)
		b_swap_a(deq_a);
	else if (ft_strncmp(comm, "sb", 3) == 0)
		b_swap_b(deq_b);
	else if (ft_strncmp(comm, "ss", 3) == 0)
		b_swap_all(deq_a, deq_b);
	else
		ft_error();
}

void	push(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "pa", 3) == 0)
		b_push_a(deq_a, deq_b);
	else if (ft_strncmp(comm, "pb", 3) == 0)
		b_push_b(deq_a, deq_b);
	else
		ft_error();
}

void	rrotate(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (ft_strncmp(comm, "rra", 4) == 0)
		b_rrotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rrb", 4) == 0)
		b_rrotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rrr", 4) == 0)
		b_rrotate_all(deq_a, deq_b, &i, &j);
	else
		ft_error();
}

void	rotate(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (*(comm + 1) == 'r' && *(comm + 2))
		rrotate(deq_a, deq_b, comm);
	else if (ft_strncmp(comm, "ra", 3) == 0)
		b_rotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rb", 3) == 0)
		b_rotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rr", 3) == 0)
		b_rotate_all(deq_a, deq_b, &i, &j);
	else
		ft_error();
}

void	compare_and_do_sort(t_deque **deq_a, t_deque **deq_b)
{
	char	*comm;

	comm = get_next_line(0);
	comm = ft_strtrim(comm, "\n");
	while (comm)
	{
		if (*comm == 's')
			swap(deq_a, deq_b, comm);
		else if (*comm == 'p')
			push(deq_a, deq_b, comm);
		else if (*comm == 'r')
			rotate(deq_a, deq_b, comm);
		else if (*comm == '\0')
			break ;
		else
			ft_error();
		comm = get_next_line(0);
		comm = ft_strtrim(comm, "\n");
	}
}
