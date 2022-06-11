/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 00:55:11 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/11 14:31:24 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft/libft.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	swap(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "sa", 3) == 0)
		b_swap_a(deq_a);
	else if (ft_strncmp(comm, "sb", 3) == 0)
		b_swap_b(deq_b);
	else if (ft_strncmp(comm, "ss", 3) == 0)
		b_swap_all(deq_a, deq_b);
	else
		ft_error();
}

void	push(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	if (ft_strncmp(comm, "pa", 3) == 0)
		b_push_a(deq_a, deq_b);
	else if (ft_strncmp(comm, "pb", 3) == 0)
		b_push_b(deq_a, deq_b);
	else
		ft_error();
}

void	rrotate(t_deque **deq_a, t_deque **deq_b, char *comm)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (ft_strncmp(comm, "rra", 4) == 0)
		b_rrotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rrb", 4) == 0)
		b_rrotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rrr", 4) == 0)
		b_rrotate_all(deq_a, deq_b, &i, &j);
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
	else if (ft_strncmp(comm, "ra", 3) == 0)
		b_rotate_a(deq_a, &i);
	else if (ft_strncmp(comm, "rb", 3) == 0)
		b_rotate_b(deq_b, &i);
	else if (ft_strncmp(comm, "rr", 3) == 0)
		b_rotate_all(deq_a, deq_b, &i, &j);
	else
		ft_error();
}

void	compare_and_do_sort(t_deque **deq_a, t_deque **deq_b, char **comm)
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

int	get_all_len(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
			j++;
		i++;
	}
	return (j);
}

char	*ft_str_join(int ac, char **av)
{
	char	*tmp;
	int		i;
	int		j;
	int		idx;
	int		len;

	len = get_all_len(av);
	tmp = (char *)malloc(sizeof(char) * (len + ac));
	if (!tmp)
		return (0);
	idx = 1;
	j = 0;
	while (ac > idx)
	{
		i = 0;
		while (av[idx][i])
			tmp[j++] = av[idx][i++];
		if (idx != ac - 1)
		{
			tmp[j] = ' ';
			j++;
		}
		idx++;
	}
	return (tmp);
}

void	split_command(t_deque **deq_a, t_deque **deq_b, int ac, char **av)
{
	int		i;
	char	*command;
	char	**splited_command;

	i = 0;
	command = ft_str_join(ac, av);
	splited_command = ft_split(command, '\n');
	while (*splited_command[i])
	{
		splited_command[i] = ft_strtrim(splited_command[i], "\n");
		i++;
	}
	deq_init(deq_a);
	deq_init(deq_b);
	compare_and_do_sort(deq_a, deq_b, splited_command);
}

int	main(int ac, char **av)
{
	t_deque	*deq_a;
	t_deque	*deq_b;

	if (ac < 2)
		return (0);
	split_command(&deq_a, &deq_b, ac, av);
	if ((deq_b->count == 0) && (is_sorted(&deq_a)))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
