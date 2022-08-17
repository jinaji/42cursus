/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:47:25 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/17 15:43:33 by jinkim2          ###   ########seoul.kr  */
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
		temp = temp->next;
		i++;
	}
	temp = (*env)->head;
	(*env)->head = temp->next;
	temp->next = 0;
	free (temp);
}

void	print_env(t_key *env)
{
	t_key	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if ((!ft_strncmp(tmp->key, "_", 1)) && (!tmp->key[1]))
			;
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	check_argu(int ac, char **av, t_key *env)
{
	t_key	*new;
	char	**tmp;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], '=') && ft_strncmp(av[i], "=", 1))
		{
			tmp = ft_split(av[i], '=');
			if (!tmp)
				exit (12);
			new = make_node(tmp[0], tmp[1]);
			env->tail->next = new;
			env->tail = new;
		}
		i++; // ㄷㅟ에 추추가  되되는는데  있있는는거  확확인인하하고  넣넣는는거  해해야야됨  ... 
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
	make_envlist(&env, dup_envp);
	if (ac == 1)
		print_env(env);
	else
		check_argu(ac, av, env);

	print_env(env);
}
