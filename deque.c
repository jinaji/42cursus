/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:42:41 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/09 18:04:20 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_deq_front(t_deque **deq, t_node *new)
{
	if (!(*deq))
		return ;
	if ((*deq)->count == 0)
	{
		(*deq)->front = new;
		(*deq)->rear = new;
	}
	else
	{
		(*deq)->front->prev = new;
		new->next = (*deq)->front;
		(*deq)->front = new;
	}
	(*deq)->count++;
}

void	insert_deq_rear(t_deque **deq, t_node *new)
{
	if (!(*deq))
		return ;
	if ((*deq)->count == 0)
	{
		(*deq)->front = new;
		(*deq)->rear = new;
	}
	else
	{
		(*deq)->rear->next = new;
		new->prev = (*deq)->rear;
		(*deq)->rear = new;
	}
	(*deq)->count++;
}

t_node	*delete_deq_front(t_deque **deq)
{
	t_node	*tmp;

	if (!(*deq) || is_deq_empty(*deq))
		return (0);
	tmp = (*deq)->front;
	(*deq)->front = (*deq)->front->next;
	tmp->next = 0;
	if ((*deq)->count == 1)
		(*deq)->rear = 0;
	else
		(*deq)->front->prev = 0;
	(*deq)->count--;
	return (tmp);
}

t_node	*delete_deq_rear(t_deque **deq)
{
	t_node	*tmp;

	if (!(*deq) || is_deq_empty(*deq))
		return (0);
	tmp = (*deq)->rear;
	(*deq)->rear = (*deq)->rear->prev;
	tmp->prev = 0;
	if ((*deq)->count == 1)
		(*deq)->front = 0;
	else
		(*deq)->rear->next = 0;
	(*deq)->count--;
	return (tmp);
}
