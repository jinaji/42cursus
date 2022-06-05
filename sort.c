/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:38 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/05 19:59:16 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_with_pivot(t_deque **deq_a, t_deque **deq_b)
{
	int	pivot1;
	int	pivot2;
	int	count;
	int	i;

	pivot1 = ((*deq_a)->count) / 3;
	pivot2 = pivot1 * 2;
	count = (*deq_a)->count;
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

int	get_min_location(t_deque **deq_a)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = (*deq_a)->front;
	while (curr)
	{
		if (curr->idx == 1)
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
	int	min_location;

	if (is_sorted(deq_a))
		return ;
	min_location = get_min_location(deq_a);
	while (min_location)
	{
		if (is_sorted(deq_a))
			return ;
		rotate_a(deq_a, &min_location);
	}
}	

void	sort_init(t_deque **deq_a, t_deque **deq_b)
{
	int	comm_a;
	int	comm_b;

	sort_with_pivot(deq_a, deq_b);
	sort_three(deq_a, deq_b);
	while ((*deq_b)->count)
	{
		comm_a = 0;
		comm_b = 0;
		count_command(deq_a, deq_b, &comm_a, &comm_b);
		rotate_all(deq_a, deq_b, &comm_a, &comm_b);
		rotate_a(deq_a, &comm_a);
		rotate_b(deq_b, &comm_b);
		push_a(deq_a, deq_b);
	}
	sort_last(deq_a);
}

void	get_sort(t_deque **deq_a, t_deque **deq_b)
{
	if ((*deq_a)->count == 2)
	{
		if ((*deq_a)->front->idx < (*deq_a)->front->next->idx)
			swap_a(deq_a);
	}
	deq_init(deq_b);
	if ((*deq_a)->count == 3)
		sort_three(deq_a, deq_b);
	else
		sort_init (deq_a, deq_b);
}
