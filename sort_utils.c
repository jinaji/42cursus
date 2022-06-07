/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/07 21:54:07 by jinkim2          ###   ########seoul.kr  */
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

	cnt = 0;
	curr = (*deq_a)->front;
	while (curr)
	{
		if (curr->idx == max_idx)
			break ;
		cnt++;
		curr = curr->next;
	}
	cnt += 1;
	if (cnt >= (((*deq_a)->count + 1) / 2))
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}

int	count_a_command(t_deque **deq_a, int idx)
{
	int		cnt;
	int		a_idx;
	t_node	*curr;

	cnt = 0;
	curr = (*deq_a)->front;
	while (curr->next)
	{
		a_idx = curr->idx;
		if (idx < a_idx)
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
		return (get_min_location(deq_a, min_idx));
	else if (idx > max_idx)
		return (get_max_location(deq_a, max_idx));
	else
		return (count_a_command(deq_a, idx));
}

/*
int	get_a_command(int idx, t_deque **deq_a)
{
	int		a_idx;
	int		count;
	t_node	*curr;

	count = 0;
	curr = (*deq_a)->front;
	while (count < (*deq_a)->count)
	{
		a_idx = curr->idx;
		if (idx < a_idx)
			break ;
		count++;
		curr = curr->next;
	}
	if (count >= ((*deq_a)->count + 1) / 2)
		count = ((*deq_a)->count - count) * -1;
	return (count);
}
*/
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
	printf ("count command %d %d\n", *com_a, *com_b);
}
