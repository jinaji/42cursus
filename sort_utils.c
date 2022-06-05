/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/05 19:59:41 by jinkim2          ###   ########seoul.kr  */
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

int	get_a_command(int idx, t_deque **deq_a)
{
	int		a_idx;
	int		count;
	t_node	*curr;

	count = 0;
	curr = (*deq_a)->front;
	while (curr)
	{
		a_idx = curr->idx;
		if (idx < a_idx)
			break ;
		count++;
		curr = curr->next;
	}
	if (count > ((*deq_a)->count) / 2)
		count = ((*deq_a)->count - count) * -1;
	return (count);
}

int	get_rr_count(int i, int j)
{
	int	ret;

	ret = i - j;
	if (ret < 0)
		ret *= -1;
	return (ret);
}

int	compare_count(int comm_a, int comm_b, int cnt_a, int cnt_b)
{
	int	comm;
	int	cnt;

	if (comm_a < 0)
		comm_a *= -1;
	if (comm_b < 0)
		comm_b *= -1;
	if (cnt_a < 0)
		cnt_a *= -1;
	if (cnt_b < 0)
		cnt_b *= -1;
	comm = get_rr_count(comm_a, comm_b);
	cnt = get_rr_count(cnt_a, cnt_b);
	if ((comm_a + comm_b - comm) > (cnt_a + cnt_b - cnt))
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
	while (cnt < (*deq_b)->count)
	{
		cnt_a = get_a_command(node_b->idx, deq_a);
		if (cnt < ((*deq_b)->count) / 2)
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
