/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:06:54 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/11 14:21:06 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_push_a(t_deque **deq_a, t_deque **deq_b)
{
	t_node	*tmp;

	if (is_deq_empty(*deq_b))
		return ;
	tmp = delete_deq_front(deq_b);
	insert_deq_front(deq_a, tmp);
}

void	b_push_b(t_deque **deq_a, t_deque **deq_b)
{
	t_node	*tmp;

	if (is_deq_empty(*deq_a))
		return ;
	tmp = delete_deq_front(deq_a);
	insert_deq_front(deq_b, tmp);
}
