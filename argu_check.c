/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argu_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:52:52 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/08 18:28:20 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit (1);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	return ;
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
	int		cnt;
	int		value;
	char	*tmp;
	char	**splited_av;

	i = 0;
	cnt = 0;
	tmp = ft_str_join(ac, av);
	splited_av = ft_split(tmp, ' ');
	while (splited_av[cnt])
		cnt++;
	while (cnt > i)
	{
		is_str_digit(splited_av[i]);
		value = ft_atoll(splited_av[i]);
		add_new_node(value, deq_a);
		free (splited_av[i]);
		i++;
	}
	indexing_argument(deq_a);
	free (splited_av);
	return (i);
}
