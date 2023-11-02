/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:20:51 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/04 12:57:34 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(char *key, t_env *env);
int		ft_unset(t_node *head);

void	delete_node(char *key, t_env *env)
{
	t_env	*tmp;
	t_env	*temp;

	tmp = env;
	if (!ft_strcmp(key, tmp->key))
	{
		tmp->key = 0;
		tmp->value = 0;
		table_get()->env = env->next;
		tmp->next = 0;
		free (tmp);
		return ;
	}
	while (ft_strcmp(tmp->next->key, key))
		tmp = tmp->next;
	if (!tmp->next)
		return ;
	tmp->next->key = 0;
	tmp->next->value = 0;
	temp = tmp->next;
	tmp->next = tmp->next->next;
	free (temp);
}

void	unset_check_exist(char *av, t_env *env)
{
	if (get_env(av))
		delete_node(av, env);
}

int	ft_unset(t_node *head)
{
	char	**av;
	int		ac;
	int		i;
	t_env	*env;

	env = table_get()->env;
	av = get_av(head, &ac);
	i = 1;
	while (i < ac)
	{
		unset_check_exist(av[i], env);
		i++;
	}
	return (0);
}
