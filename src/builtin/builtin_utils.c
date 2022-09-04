/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:48:04 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/03 12:17:07 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_key(char *str);
char	*get_env(char *str);
char	**get_av(t_node *head, int *ac);
char	*ft_strndup(char *str, int len);

char	*get_key(char *str) // 못 찾으면 0
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	if ((size_t)i == ft_strlen(str))
		return (ft_strdup(str));
	tmp = ft_strndup(str, i);
	if (!tmp)
		exit (12);
	return (tmp);
}

char	*get_env(char *str)
{
	t_env	*env;

	if (!str)
		return (0);
	env = (table_get())->env;
	while (env)
	{
		if (ft_strcmp(env->key, str))
			return (env->value);
		env = env->next;
	}
	return (0);
}

char	*av_join(char *str1, char *str2)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = (int)ft_strlen(str1) + (int)ft_strlen(str2);
	tmp = (char *)malloc(sizeof(char) * len + 2);
	if (!tmp)
		exit (12);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	tmp[i] = ' ';
	i++;
	while (str2[j])
		tmp[i++] = str2[j++];
	tmp[i] = '\0';
	free (str1);
	return (tmp);
}

char	**get_av(t_node *head, int *ac)
{
	t_node	*tmp;
	char	**av;
	char	*str;
	int		i;

	tmp = head;
	i = 0;
	str = ft_strdup("");
	while (tmp)
	{
		str = av_join(str, tmp->data);
		tmp = tmp->left;
	}
	av = ft_split(str, ' ');
	while (av[i])
		i++;
	*ac = i;
	return (av);
	// int		i;
	// char	**tmp;

	// if (!str)
	// 	return (0);
	// i = 1;
	// tmp = ft_split(str, ' ');
	// if (!tmp)
	// 	exit (12);
	// while (tmp[i])
	// 	i++;
	// *ac = i + 1;
	// return (tmp);
}

char	*ft_strndup(char *str, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		exit (12);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
