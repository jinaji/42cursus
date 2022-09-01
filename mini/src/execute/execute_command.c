/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:10:03 by gulee             #+#    #+#             */
/*   Updated: 2022/09/01 00:46:02 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ex_command(t_node *node)
{
	get_redir();
	if (!ft_strcmp(node->data, "echo"))
		ft_echo(node);
	else if (!ft_strcmp(node->data, "cd"))
		ft_cd(node);
	else if (!ft_strcmp(node->data, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(node->data, "export"))
		ft_export(node);
	else if (!ft_strcmp(node->data, "unset"))
		ft_unset(node);
	else if (!ft_strcmp(node->data, "env"))
		ft_env(node);
	else if (!ft_strcmp(node->data, "exit"))
		ft_exit(node);
	else
		not_minishell(node, 0);
	close_redir();
}
