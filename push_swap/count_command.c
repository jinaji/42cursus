/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:37:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 16:39:26 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_a_command(t_deque **deq_a, int idx)
{
	int		cnt;
	t_node	*curr;

	cnt = 1;
	curr = (*deq_a)->front;
	while (curr->next)
	{
		if (idx > curr->idx && idx < curr->next->idx)
			break ;
		cnt++;
		curr = curr->next;
	}
	if (cnt >= ((*deq_a)->count + 1) / 2)
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}

int	get_a_command(int idx, t_deque **deq_a)
{
	int		min_idx;
	int		max_idx;

	min_idx = get_min_idx(deq_a);
	max_idx = get_max_idx(deq_a);
	if (idx < min_idx)
	{
		return (get_min_location(deq_a, min_idx));
	}
	else if (idx > max_idx)
	{
		return (get_max_location(deq_a, max_idx));
	}
	else
	{
		return (count_a_command(deq_a, idx));
	}
}

int	compare_count(int comm_a, int comm_b, int cnt_a, int cnt_b)
{
	if (comm_a < 0)
		comm_a *= -1;
	if (comm_b < 0)
		comm_b *= -1;
	if (cnt_a < 0)
		cnt_a *= -1;
	if (cnt_b < 0)
		cnt_b *= -1;
	if ((comm_a + comm_b) > (cnt_a + cnt_b))
		return (1);
	else
		return (0);
}

void	count_command(t_deque **deq_a, t_deque **deq_b, int *com_a, int *com_b)
{
	int		cnt_a;
	int		cnt_b;
	int		cnt;
	t_node	*node_b;

	cnt = 0;
	node_b = (*deq_b)->front;
	while (node_b)
	{
		cnt_a = get_a_command(node_b->idx, deq_a);
		if (cnt < (((*deq_b)->count) + 1) / 2)
			cnt_b = cnt;
		else
			cnt_b = (((*deq_b)->count) - cnt) * -1;
		if (cnt == 0 || compare_count(*com_a, *com_b, cnt_a, cnt_b))
		{
			*com_a = cnt_a;
			*com_b = cnt_b;
		}
		cnt++;
		node_b = node_b->next;
	}
}
