/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:56 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/09 23:07:13 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_deque **deq_a, t_deque **deq_b)
{
	t_node	*tmp;

	if (is_deq_empty(*deq_b))
		return ;
	tmp = delete_deq_front(deq_b);
	insert_deq_front(deq_a, tmp);
	write (1, "pa\n", 3);
}

void	push_b(t_deque **deq_a, t_deque **deq_b)
{
	t_node	*tmp;

	if (is_deq_empty(*deq_a))
		return ;
	tmp = delete_deq_front(deq_a);
	insert_deq_front(deq_b, tmp);
	write (1, "pb\n", 3);
}
