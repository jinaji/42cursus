/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:44 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/06 23:23:04 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_deque **deq_a, int *comm_a)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_a);
	insert_deq_front(deq_a, tmp);
	write (1, "rra\n", 4);
	*comm_a += 1;
}

void	rrotate_b(t_deque **deq_b, int *comm_b)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_b);
	insert_deq_front(deq_b, tmp);
	write (1, "rrb\n", 4);
	*comm_b += 1;
}

void	rrotate_all(t_deque **deq_a, t_deque **deq_b, int *comm_a, int *comm_b)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_a);
	insert_deq_front(deq_a, tmp);
	tmp = delete_deq_rear(deq_b);
	insert_deq_front(deq_b, tmp);
	*comm_a += 1;
	*comm_b += 1;
	write (1, "rrr\n", 4);
}
