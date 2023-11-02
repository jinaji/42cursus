/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:39:04 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/04 20:47:49 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_deque **deq_a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = delete_deq_front(deq_a);
	tmp2 = delete_deq_front(deq_a);
	insert_deq_front(deq_a, tmp1);
	insert_deq_front(deq_a, tmp2);
	write (1, "sa\n", 3);
}

void	swap_b(t_deque **deq_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = delete_deq_front(deq_b);
	tmp2 = delete_deq_front(deq_b);
	insert_deq_front(deq_b, tmp1);
	insert_deq_front(deq_b, tmp2);
	write (1, "sb\n", 3);
}

void	swap_all(t_deque **deq_a, t_deque **deq_b)
{
	swap_a(deq_a);
	swap_b(deq_b);
	write (1, "ss\n", 3);
}
