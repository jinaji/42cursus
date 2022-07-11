/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:55:11 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/12 03:03:57 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	add_new_node(int val, t_deque **deq)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		free_deque(deq);
	ft_memset(new, 0, sizeof(t_node));
	new->val = val;
	if ((*deq)->count == 0)
	{
		(*deq)->front = new;
		(*deq)->rear = new;
	}
	else
	{
		new->prev = (*deq)->rear;
		(*deq)->rear->next = new;
		(*deq)->rear = new;
	}
	(*deq)->count++;
}

void	indexing_argument(t_deque **deq_a)
{
	t_node	*curr;
	t_node	*cmp;

	curr = (*deq_a)->front;
	while (curr)
	{
		cmp = curr->next;
		while (cmp)
		{
			if (curr->val == cmp->val)
				ft_error();
			if (curr->val > cmp->val)
				curr->idx++;
			else
				cmp->idx++;
			cmp = cmp->next;
		}
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_deque	*deq_a;
	t_deque	*deq_b;

	if (ac < 2)
		return (0);
	deq_init(&deq_a);
	argument_check(ac, av, &deq_a);
	deq_init(&deq_b);
	compare_and_do_sort(&deq_a, &deq_b);
	if ((deq_b->count == 0) && (is_sorted(&deq_a)))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
