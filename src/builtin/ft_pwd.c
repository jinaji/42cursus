/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:35:03 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/01 15:03:59 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(void);

int	ft_pwd(void)
{
	char	buf[1024];

	if (!getcwd(buf, 1024))
		printf("%s\n", env_get("PWD"));
	else
		printf("%s\n", getcwd(buf, 1024));
	return (0);
}
