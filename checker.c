/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:55:11 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 17:24:11 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "push_swap_bonus.h"

void	swap(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "sa\n", 4) == 0)
		swap_a(deq_a);
	else if (ft_strncmp(comm, "sa\n", 4) == 0)
		swap_b(deq_b);
	else if (ft_strncmp(comm, "ss\n", 4) == 0)
		swap_all(deq_a, deq_b);
	else
		ft_error();
}

void	push(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "pa\n", 4) == 0)
		push_a(deq_a, deq_b);
	else if (ft_strncmp(comm, "pb\n", 4) == 0)
		push_b(deq_a, deq_b);
	else
		ft_error();
}

void	rrotate(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (ft_strncmp(comm, "rra\n", 5) == 0)
		rrotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rrb\n", 5) == 0)
		rrotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rrr\n", 5) == 0)
		rrotate_all(deq_a, deq_b, &i, &j);
	else
		ft_error();
}

void	rotate(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (*(comm + 1) == 'r' && *(comm + 2))
		rrotate(deq_a, deq_b, comm);
	else if (ft_strncmp(comm, "ra\n", 4) == 0)
		rotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rb\n", 4) == 0)
		rotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rr\n", 4) == 0)
		rotate_all(deq_a, deq_b, &i, &j);
	else
		ft_error();
}

void	compare_and_do_command(t_deque **deq_a, t_deque **deq_b, char **comm)
{
	int	i;

	i = 0;
	while (comm[i])
	{
		if (*comm[i] == 's')
			swap(deq_a, deq_b, *comm);
		else if (*comm[i] == 'p')
			push(deq_a, deq_b, *comm);
		else if (*comm[i] == 'r')
			rotate(deq_a, deq_b, *comm);
		else
			ft_error();
		i++;
	}
}

void	split_command(t_deque **deq_a, t_deque **deq_b, int ac, char **av)
{
	char	*command;
	char	**splited_command;

	command = ft_str_join(ac, av);
	splited_command = ft_split(command, '\n');
	deq_init(deq_a);
	deq_init(deq_b);
	compare_and_do_command(deq_a, deq_b, splited_command);
}

int	main(int ac, char **av)
{
	t_deque	*deq_a;
	t_deque	*deq_b;

	if (ac < 2)
		return (0);
	split_command(&deq_a, &deq_b, ac, av);
	return (0);
}
