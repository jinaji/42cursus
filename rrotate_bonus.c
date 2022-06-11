/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:03:37 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/11 14:23:43 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_rrotate_a(t_deque **deq_a, int *comm_a)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_a);
	insert_deq_front(deq_a, tmp);
	*comm_a += 1;
}

void	b_rrotate_b(t_deque **deq_b, int *comm_b)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_b);
	insert_deq_front(deq_b, tmp);
	*comm_b += 1;
}

void	b_rrotate_all(t_deque **deq_a, t_deque **deq_b, int *a, int *b)
{
	t_node	*tmp;

	tmp = delete_deq_rear(deq_a);
	insert_deq_front(deq_a, tmp);
	tmp = delete_deq_rear(deq_b);
	insert_deq_front(deq_b, tmp);
	*a += 1;
	*b += 1;
}
