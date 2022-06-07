/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:42 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/06 23:21:17 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_deque **deq_a, int *comm_a)
{
	t_node	*tmp;

	while (*comm_a)
	{
		if (*comm_a < 0)
			rrotate_a(deq_a, comm_a);
		else
		{
			tmp = delete_deq_front(deq_a);
			insert_deq_rear(deq_a, tmp);
			*comm_a -= 1;
			write (1, "ra\n", 3);
		}
	}
}

void	rotate_b(t_deque **deq_b, int *comm_b)
{
	t_node	*tmp;

	while (*comm_b)
	{
		if (*comm_b < 0)
			rrotate_b(deq_b, comm_b);
		else
		{
			tmp = delete_deq_front(deq_b);
			insert_deq_rear(deq_b, tmp);
			*comm_b -= 1;
			write (1, "rb\n", 3);
		}
	}
}

void	rotate_all(t_deque **deq_a, t_deque **deq_b, int *comm_a, int *comm_b)
{
	t_node	*tmp;

	while (*comm_a && *comm_b && *comm_a > 0 && *comm_b > 0)
	{
		tmp = delete_deq_front(deq_a);
		insert_deq_rear(deq_a, tmp);
		tmp = delete_deq_front(deq_b);
		insert_deq_rear(deq_b, tmp);
		*comm_a -= 1;
		*comm_b -= 1;
		write (1, "rra\n", 4);
	}
	while (*comm_a && *comm_b && *comm_a < 0 && *comm_b < 0)
		rrotate_all(deq_a, deq_b, comm_a, comm_b);
}
