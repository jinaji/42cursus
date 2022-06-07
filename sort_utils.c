/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/07 13:39:07 by jinkim2          ###   ########seoul.kr  */
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

int	get_min_idx(t_deque **deq_a, int *min_idx)
{
	int		cnt;
	t_node	*tmp;

	tmp = (*deq_a)->front;
	*min_idx = tmp->idx;
	cnt = 0;
	while (tmp)
	{
		if (*min_idx > tmp->idx)
			*min_idx = tmp->idx;
		tmp = tmp->next;
		cnt++;
	}
	if (cnt > ((*deq_a)->count + 1) / 2)
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}

int	get_max_idx(t_deque **deq_a, int *max_idx)
{
	int		cnt;
	t_node	*tmp;

	tmp = (*deq_a)->front;
	*max_idx = tmp->idx;
	cnt = 0;
	while (tmp)
	{
		if (*max_idx < tmp->idx)
			*max_idx = tmp->idx;
		tmp = tmp->next;
		cnt++;
	}
	if (cnt > ((*deq_a)->count + 1) / 2)
		cnt = ((*deq_a)->count - cnt) * -1;
	return (cnt);
}

int	get_a_command(int idx, t_deque **deq_a)
{
	int 	count;
	int		count1;
	int		count2;
	int		a_idx;
	int		min_idx;
	int		max_idx;
	t_node	*curr;

	count = 0;
	curr = (*deq_a)->front;
	count1 = get_min_idx(deq_a, &min_idx);
	count2 = get_max_idx(deq_a, &max_idx);
	if (idx < min_idx)
		return (count1);
	else if (idx > max_idx)
		return (count2);
	else
	{
		count = 0;
		while (curr)
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
}

/*
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
	if (count >= ((*deq_a)->count + 1) / 2)
		count = ((*deq_a)->count - count) * -1;
	return (count);
}이거 왜 문제였냐면 ... 그냥 맨 위에거랑 비교해서 작으면 넘겨가지고 섞여있는 상태면 중구난방으로 됐음 
그래서 제일 작은 값이랑 제일 큰 값 잡아서 어케어케 잘 하고싶은데 맘대로 안되는중
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
	while (cnt < (*deq_b)->count)
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
