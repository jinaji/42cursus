/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:47:25 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/21 21:21:20 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_key	*make_node(char	*key, char *value)
{
	t_key	*new;

	new = malloc(sizeof(t_key));
	if (!new)
		exit (12);
	new->key = key;
	new->value = value;
	new->next = 0;
	new->prev = 0;
	return (new);
}

char	**mini_split(char *str, char c)
{
	char	**tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	tmp = (char **)malloc(sizeof(char *) * 3);
	if (!tmp)
		exit (12);
	tmp[0] = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp[0])
		exit (12);
	while (i < len)
	{
		tmp[0][i] = str[i];
		i++;
	}
	tmp[0][i] = 0;
	len = ft_strlen(str) - len;
	tmp[1] = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp[1])
		exit (12);
	while (str[i])
		tmp[1][j++] = str[++i];
	tmp[2] = 0;
	return (tmp);
}

void	make_envlist(t_key	**env, char **dup_envp)
{
	t_key	*temp;
	t_key	*new;
	char	**tmp;
	int		i;

	i = 0;
	(*env) = malloc(sizeof(t_key));
	(*env)->head = (*env);
	temp = *env;
	while (dup_envp[i])
	{
		tmp = ft_split(dup_envp[i], '=');
		if (!tmp)
			exit (12);
		new = make_node(tmp[0], tmp[1]);
		(*env)->tail = new;
		temp->next = new;
		new->prev = temp;
		temp = temp->next;
		i++;
	}
	temp = (*env)->head;
	(*env)->head = temp->next;
	temp->next = 0;
	temp->prev = 0;
	free (temp);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char) str2[i]);
		i++;
	}
	if (str2[i])
		return ((unsigned char)str1[i] - (unsigned char) str2[i]);
	return (0);
}

void	print_export(t_key *env)
{
	t_key	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if ((!ft_strcmp(tmp->key, "_")))
			;
		else if (!ft_strcmp(tmp->value, "donotprint"))
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

int	check_exist(char *key, char *value, t_key *env)
{
	t_key	*tmp;
	int		i;

	tmp = env->head;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			if (!ft_strcmp(value, "donotprint"))
				return (1);
			else if (ft_strcmp(tmp->value, "donotprint"))
				free (tmp->value);
			if (value || !ft_strcmp(tmp->value, "donotprint"))
				tmp->value = value;
			else
				tmp->value = ft_strdup("");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_strdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_position(t_key *env, char *str)
{
	int		i;
	t_key	*tmp;

	i = 1;
	tmp = env->head;
	if (ft_strcmp(tmp->key, str) < 0)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, str) > 0 && ft_strcmp(tmp->next->key, str) < 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	add_node(t_key *env, t_key *new, int pos)
{
	t_key	*tmp;

	tmp = env->head;
	while (pos--)
		tmp = tmp->next;
	tmp->next->prev = new;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next = new;
}

void	check_argu(int ac, char **av, t_key *env)
{
	t_key	*new;
	char	**tmp;
	int		i;
	int		pos;

	i = 1;
	while (i < ac)
	{
		if (is_strdigit(av[i]))
			printf("shellname: export: %snot a valid identifier\n", av[i]);
		else if (ft_strchr(av[i], '=') && av[i][0] != '=')
		{
			tmp = mini_split(av[i], '=');
			if (!tmp)
				exit (12);
			if (check_exist(tmp[0], tmp[1], env))
				;
			else
			{
				new = make_node(tmp[0], tmp[1]);
				pos = get_position(env, tmp[0]);
				add_node(env, new, pos);
			}
		}
		else if (!ft_strchr(av[i], '='))
		{
			if (check_exist(av[i], "donotprint", env))
				;
			else
			{
				new = make_node(av[i], "donotprint");
				pos = get_position(env, tmp[0]);
				add_node(env, new, pos);
			}
		}
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_key	*env;
	char	**dup_envp;
	char	**exp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	dup_envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		dup_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	dup_envp[i] = 0;
	make_envlist(&env, dup_envp);
	if (ac == 1)
		print_export(env);
	else
		check_argu(ac, av, env);
	print_export(env);
}

// cc -g -o export ft_export.c libft/ft_strlen.c libft/ft_split.c libft/ft_strchr.c  libft/ft_strdup.c libft/ft_isdigit.c