/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:31:37 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/09 23:10:25 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_deq_empty(t_deque *deq)
{
	if (deq->count == 0)
		return (1);
	return (0);
}

void	deq_init(t_deque **deq)
{
	(*deq) = (t_deque *)malloc(sizeof(t_deque));
	if (!(*deq))
		return ;
	(*deq)->count = 0;
	(*deq)->front = 0;
	(*deq)->rear = 0;
}

void	free_deque(t_deque **deq)
{
	t_node	*tmp;

	tmp = (*deq)->front;
	while (tmp)
	{
		free (tmp);
		tmp = tmp->next;
	}
	free (*deq);
	exit (1);
}
