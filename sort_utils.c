/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 00:38:44 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque **deq)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (is_deq_empty(*deq))
		return (0);
	tmp1 = (*deq)->front;
	tmp2 = (*deq)->front->next;
	while (tmp2)
	{
		if (tmp1->val > tmp2->val)
			return (0);
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	return (1);
}

int	get_min_idx(t_deque **deq_a)
{
	int		min_idx;
	t_node	*curr;

	curr = (*deq_a)->front;
	min_idx = curr->idx;
	while (curr)
	{
		if (curr->idx < min_idx)
			min_idx = curr->idx;
		curr = curr->next;
	}
	return (min_idx);
}

int	get_max_idx(t_deque **deq_a)
{
	int		max_idx;
	t_node	*curr;

	curr = (*deq_a)->front;
	max_idx = curr->idx;
	while (curr)
	{
		if (curr->idx > max_idx)
			max_idx = curr->idx;
		curr = curr->next;
	}
	return (max_idx);
}

int	get_min_location(t_deque **deq_a, int min_idx)
{
	t_node	*curr;
	int		cnt;

	cnt = 0;
	curr = (*deq_a)->front;
	while (curr)
	{
		if (curr->idx == min_idx)
			break ;
		cnt++;
		curr = curr->next;
	}
	if (cnt >= (((*deq_a)->count + 1) / 2))
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}

int	get_max_location(t_deque **deq_a, int max_idx)
{
	t_node	*curr;
	int		cnt;

	cnt = 1;
	curr = (*deq_a)->front;
	while (curr)
	{
		if (curr->idx == max_idx)
			break ;
		cnt++;
		curr = curr->next;
	}
	if (cnt >= (((*deq_a)->count + 1) / 2))
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}
