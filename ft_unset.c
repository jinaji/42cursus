/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:47:27 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/18 01:03:52 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i])
		return (0);
	return (1);
}

void	print_env(t_key *env)
{
	t_key	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if ((ft_strcmp(tmp->key, "_")))
			;
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

t_key	*make_node(char	*key, char *value)
{
	t_key	*new;

	new = malloc(sizeof(t_key));
	if (!new)
		exit (12);
	new->key = key;
	new->value = value;
	new->next = 0;
	return (new);
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

int	check_exist(char *av, t_key *env)
{
	char	**temp;
	t_key	*tmp;
	int		i;

	temp = ft_split(av, '=');
	tmp = env->head;
	i = 0;
	while (tmp)
	{
		if (ft_strcmp(temp[0], tmp->key))
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free (tmp->value);
			free (tmp->key);
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
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
	i = 1;
	while (i < ac)
	{
		check_exist(av[i], env);
		i++;
	}
	print_env(env);
}
