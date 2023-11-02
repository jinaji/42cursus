/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:02:34 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/16 01:20:19 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_rotate_a(t_deque **deq_a, int *comm_a)
{
	t_node	*tmp;

	if ((*deq_a)->count == 1)
		return ;
	while (*comm_a)
	{
		if (*comm_a < 0)
			b_rrotate_a(deq_a, comm_a);
		else
		{
			tmp = delete_deq_front(deq_a);
			insert_deq_rear(deq_a, tmp);
			*comm_a -= 1;
		}
	}
}

void	b_rotate_b(t_deque **deq_b, int *comm_b)
{
	t_node	*tmp;

	if ((*deq_b)->count == 1)
		return ;
	while (*comm_b)
	{
		if (*comm_b < 0)
			b_rrotate_b(deq_b, comm_b);
		else
		{
			tmp = delete_deq_front(deq_b);
			insert_deq_rear(deq_b, tmp);
			*comm_b -= 1;
		}
	}
}

void	b_rotate_all(t_deque **deq_a, t_deque **deq_b, int *a, int *b)
{
	t_node	*tmp;

	while (*a && *b && *a > 0 && *b > 0)
	{
		tmp = delete_deq_front(deq_a);
		insert_deq_rear(deq_a, tmp);
		tmp = delete_deq_front(deq_b);
		insert_deq_rear(deq_b, tmp);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && *a < 0 && *b < 0)
		b_rrotate_all(deq_a, deq_b, a, b);
	if (*a)
		b_rotate_a(deq_a, a);
	if (*b)
		b_rotate_b(deq_b, b);
}
