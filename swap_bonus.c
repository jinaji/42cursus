/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:50:07 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/11 14:02:08 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	b_swap_a(t_deque **deq_a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = delete_deq_front(deq_a);
	tmp2 = delete_deq_front(deq_a);
	insert_deq_front(deq_a, tmp1);
	insert_deq_front(deq_a, tmp2);
}

void	b_swap_b(t_deque **deq_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = delete_deq_front(deq_b);
	tmp2 = delete_deq_front(deq_b);
	insert_deq_front(deq_b, tmp1);
	insert_deq_front(deq_b, tmp2);
}

void	b_swap_all(t_deque **deq_a, t_deque **deq_b)
{
	b_swap_a(deq_a);
	b_swap_b(deq_b);
}
