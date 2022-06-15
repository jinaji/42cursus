/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:17 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/16 01:19:52 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_with_pivot(t_deque **deq_a, t_deque **deq_b)
{
	int	pivot1;
	int	pivot2;
	int	count;
	int	i;

	pivot1 = ((*deq_a)->count) / 3;
	pivot2 = (((*deq_a)->count) * 2) / 3;
	count = (*deq_a)->count - 3;
	while (count)
	{
		i = 1;
		if ((*deq_a)->front->idx < pivot1)
		{
			push_b(deq_a, deq_b);
			rotate_b(deq_b, &i);
		}
		else if ((*deq_a)->front->idx < pivot2)
			push_b(deq_a, deq_b);
		else
			rotate_a(deq_a, &i);
		count--;
	}
}

int	get_first_index(t_deque **deq_a)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = (*deq_a)->front;
	while (curr)
	{
		if (curr->idx == 0)
			break ;
		curr = curr->next;
		count++;
	}
	if (count > ((*deq_a)->count) / 2)
		count = ((*deq_a)->count - count) * -1;
	return (count);
}

void	sort_last(t_deque **deq_a)
{
	int	first_idx;

	if (is_sorted(deq_a))
		return ;
	first_idx = get_first_index(deq_a);
	while (first_idx)
		rotate_a(deq_a, &first_idx);
}

void	sort_init(t_deque **deq_a, t_deque **deq_b)
{
	int	comm_a;
	int	comm_b;

	sort_with_pivot(deq_a, deq_b);
	while ((*deq_a)->count > 3)
		push_b(deq_a, deq_b);
	sort_three(deq_a, deq_b);
	while ((*deq_b)->count)
	{
		comm_a = 0;
		comm_b = 0;
		count_command(deq_a, deq_b, &comm_a, &comm_b);
		b_rotate_all(deq_a, deq_b, &comm_a, &comm_b);
		push_a(deq_a, deq_b);
	}
	sort_last(deq_a);
}

void	get_sort(t_deque **deq_a, t_deque **deq_b)
{
	if ((*deq_a)->count == 2)
	{
		if ((*deq_a)->front->idx > (*deq_a)->front->next->idx)
			swap_a(deq_a);
	}
	deq_init(deq_b);
	if ((*deq_a)->count == 3)
		sort_three(deq_a, deq_b);
	else
		sort_init (deq_a, deq_b);
}
