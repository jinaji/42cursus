/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 01:08:23 by gulee             #+#    #+#             */
/*   Updated: 2022/09/02 16:08:58 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	t_env	*env_last(t_env	*env)
{
	t_env	*tmp;

	if (!env)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	set_env(char **env)
{
	t_table	*table;
	int		index;
	t_env	*tmp;
	t_env	*last;

	table = table_get();
	table->env = init_env(env[0]);
	index = 0;
	while (env[index])
	{
		tmp = init_env(env[index]);
		last = env_last(table->env);
		last->next = tmp;
		++index;
	}
}

char	*env_get(char *key)
{
	t_env	*cur;
	t_table	*table;

	table = table_get();
	cur = table->env;
	while (cur)
	{
		if (!ft_strcmp(cur->key, key))
			return (cur->value);
		cur = cur->next;
	}
	return ("");
}
