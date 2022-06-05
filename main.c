/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:36 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/05 15:57:04 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	return ;
}

void	add_new_node(int val, t_deque **deq)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	ft_memset(new, 0, sizeof(t_node));
	new->val = val;
	if ((*deq)->count == 0)
	{
		(*deq)->front = new;
		(*deq)->front->prev = 0;
		(*deq)->rear = new;
	}
	else
	{
		new->prev = (*deq)->rear;
		(*deq)->rear = new;
	}
	(*deq)->count++;
}

void	indexing_argument(t_deque **deq_a)
{
	t_node	*curr;
	t_node	*cmp;

	curr = (*deq_a)->front;
	while (curr->next)
	{
		cmp = curr->next;
		while (cmp->next)
		{
			if (cmp->val == cmp->next->val)
				exit (1);
			if (cmp->val > cmp->next->val)
				cmp->idx++;
			else
				cmp->next->idx++;
			cmp = cmp->next;
		}
		curr = curr->next;
	}
}

int	get_all_len(char **av)
{
	int	i;
	int	j;

	i = 0;
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
	i = 0;
	idx = 0;
	j = 0;
	while (ac > idx)
	{
		while (av[idx])
			tmp[j++] = av[idx][i++];
		tmp[j] = ' ';
		j++;
		idx++;
	}
	return (tmp);
}

int	ft_atoll(char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && 13 >= str[i]) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while ('9' >= str[i] && str[i] >= '0')
	{
		r = (r * 10) + (str[i] - 48) * s;
		i++;
	}
	if (-2147483648 > r || r > 2147483647)
		ft_error();
	return (r);
}

int	argument_check(int ac, char **av, t_deque **deq_a)
{
	int		i;
	int		value;
	char	*tmp;
	char	**splited_av;
	t_node	*curr;

	i = 0;
	tmp = ft_str_join(ac, av);
	splited_av = ft_split(tmp, ' ');
	while (ac > i)
	{
		is_str_digit(splited_av[i]);
		value = ft_atoll(splited_av[i]);
		add_new_node(value, deq_a);
		free (splited_av[i]);
		i++;
	}
	curr = (*deq_a)->front;
	while (curr)
	{
		indexing_argument(deq_a);
		curr = curr->next;
	}
	free (splited_av);
	return (i);
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
