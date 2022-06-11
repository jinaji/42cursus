/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:36 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 00:34:15 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
	if (is_sorted(&deq_a))
		return (0);
	get_sort(&deq_a, &deq_b);
}
