/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:55 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/07 15:16:25 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_case_three(int val1, int val2, int val3)
{
	if ((val1 > val2) && (val2 > val3) && (val1 > val3))
		return (1);
	else if ((val1 > val2) && (val2 < val3) && (val1 > val3))
		return (2);
	else if ((val1 < val2) && (val2 > val3) && (val1 > val3))
		return (3);
	else if ((val1 > val2) && (val2 < val3) && (val1 < val3))
		return (4);
	else if ((val1 < val2) && (val2 > val3) && (val1 < val3))
		return (5);
	else
		return (0);
}

void	get_three_sort(t_deque **deq_a, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		b_swap_a(deq_a);
		b_rrotate_a(deq_a, &i);
	}
	if (flag == 2)
		b_rotate_a(deq_a, &i);
	if (flag == 3)
		b_rrotate_a(deq_a, &i);
	if (flag == 4)
		b_swap_a(deq_a);
	if (flag == 5)
	{
		b_swap_a(deq_a);
		b_rotate_a(deq_a, &i);
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
	while (count > 4)
	{
		b_push_a(deq_a, deq_b);
		count--;
	}
	val1 = ((*deq_a)->front)->val;
	val2 = ((*deq_a)->front)->next->val;
	val3 = ((*deq_a)->front)->next->next->val;
	flag = get_case_three(val1, val2, val3);
	get_three_sort(deq_a, flag);
}
