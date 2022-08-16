/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:47:25 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/16 13:35:06 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	**export_strdup(char **dup_envp)
{
	
}

int	main(int ac, char **av, char **envp)
{
	char	**dup_envp;
	char	**exp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	dup_envp = (char **)malloc(sizeof(char *) * (i + 1));
	while (envp[i])
	{
		dup_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (ac == 2)
		exp = export_strdup(dup_envp);
}
