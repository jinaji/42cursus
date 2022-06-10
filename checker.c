/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:55:11 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 16:47:56 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "push_swap_bonus.h"

int	compare_and_do_command(t_deque **deq_a, t_deque **deq_b, char **comm)
{
	int	i;
	int	num;

	i = 0;
	while (comm[i])
	{
		num = 1;
		if (ft_strncmp(comm[i], "sa\n", 4) == 0)
			swap_a(deq_a);
		else if (ft_strncmp(comm[i], "sa\n", 4) == 0)
			swap_b(deq_b);
		else if (ft_strncmp(comm[i], "pa\n", 4) == 0)
			push_a(deq_a, deq_b);
		else if (ft_strncmp(comm[i], "pb\n", 4) == 0)
			push_b(deq_a, deq_b);
		else if (ft_strncmp(comm[i], "ra\n", 4) == 0)
			rotate_a(deq_a, &num); // swap rotate push 나누기
	}
}

int	main(int ac, char **av)
{
	t_deque	*deq_a;
	t_deque	*deq_b;
	char	**command;
	int		i;

	if (ac < 2)
		return (0);
	i = 0;
	while (ac > i)
		command[i++] = get_next_line(0);
	compare_and_do_command(&deq_a, &deq_b, command);
	return (0);
}
