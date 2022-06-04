/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:38 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/05 01:28:13 by jinkim2          ###   ########seoul.kr  */
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
	while (tmp2->next)
	{
		if (tmp1->val > tmp2->val)
			return (0);
		tmp1 = tmp2;
		tmp2 = tmp2->next;
	}
	return (1);
}

int	get_case_three(int val1, int val2, int val3)
{
	if ((val1 > val2) && (val2 > val3) && (val1 > val3)) // 321
		return (1);
	else if ((val1 > val2) && (val2 < val3) && (val1 > val3)) // 312
		return (2);
	else if ((val1 < val2) && (val2 > val3) && (val1 > val3)) // 231
		return (3);
	else if ((val1 > val2) && (val2 < val3) && (val1 < val3)) // 213
		return (4);
	else if ((val1 < val2) && (val2 > val3) && (val1 < val3)) // 132
		return (5);
	return (0);
}

void	get_three_sort(t_deque **deq_a, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		swap_a(deq_a);
		rrotate_a(deq_a, &i);
	}
	if (flag == 2)
		rotate_a(deq_a, &i);
	if (flag == 3)
		rrotate_a(deq_a, &i);
	if (flag == 4)
		swap_a(deq_a);
	if (flag == 5)
	{
		swap_a(deq_a);
		rrotate_a(deq_a, &i);
	}
}

void	sort_three(t_deque **deq_a, t_deque **deq_b)
{
	int		count;
	int		val1;
	int		val2;
	int		val3;
	int		flag;

	if (is_sorted(deq_a))
		return ;
	count = (*deq_a)->count;
	while (count > 3)
	{
		push_a(deq_a, deq_b);
		count--;
	}
	val1 = ((*deq_a)->front)->val;
	val2 = ((*deq_a)->front)->next->val;
	val3 = ((*deq_a)->front)->next->next->val;
	flag = get_case_three(val1, val2, val3);
	get_three_sort(deq_a, flag);
}

int	get_a_command(int idx, t_deque **deq_a) // idx는 b에서 가지고 온 idx
{
	int		a_idx; // idx랑 가장 가까운 인덱스
	int		count; // 명령 횟수 
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

int	compare_count(int *comm_a, int *comm_b, int cnt_a, int cnt_b)
{
	if (*comm_a < 0)
		*comm_a *= -1;
	if (*comm_b < 0)
		*comm_b *= -1;
	if (cnt_a < 0)
		cnt_a *= -1;
	if (cnt_b < 0)
		cnt_b *= -1;
	if ((*comm_a + *comm_b) > cnt_a + cnt_b)
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
		if (cnt == 0 || compare_count(com_a, com_b, cnt_a, cnt_b))
		{
			*com_a = cnt_a;
			*com_b = cnt_b;
		}
		cnt++;
		node_b = node_b->next;
	}
}

void	sort_with_pivot(t_deque **deq_a, t_deque **deq_b) // 큰 중 작
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

	min_location = get_min_location(deq_a);
	if (is_sorted(deq_a))
		return ;
	while (min_location)
		rotate_a(deq_a, &min_location);
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
	else if ((*deq_a)->count == 3)
		sort_three(deq_a, deq_b);
	else
		sort_init (deq_a, deq_b);
}
