/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:18:03 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/05 20:27:33 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	check_command(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (!tmp->right)
		tmp->type = CMD_E;
	while (tmp)
	{
		if (tmp->type == PIPE_E && tmp->right)
		{
			tmp->right->type = CMD_E;
			table_get()->cmd_cnt++;
		}
		if (tmp->type == PIPE_E && tmp->left)
		{
			tmp->left->type = CMD_E;
			table_get()->cmd_cnt++;
		}
		tmp = tmp->left;
	}
}

void	init_fd(t_table *table)
{
	int		i;

	i = 0;
	table->fd = (int **)malloc(sizeof(int *) * table->cmd_cnt);
	if (!table->fd)
	{
		error_print("init fd error in pre_execute");
		exit (12);
	}
	while (table->cmd_cnt > i)
	{
		table->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!table->fd[i])
		{
			error_print("init fd error in pre_execute");
			exit (12);
		}
		i++;
	}
}

char	*cut_pipe(t_node *tmp)
{
	char	*temp;
	char	*temp2;

	temp = 0;
	while (tmp)
	{
		if (tmp->type == CMD_E)
		{
			while (tmp->left)
			{
				temp2 = temp;
				temp = ft_strjoin(tmp->data, tmp->left->data);
				free (temp2);
				tmp->left = tmp->left->left;
			}
			break ;
		}
		tmp = tmp->left;
	}
	return (temp);
}

void	pre_execute(t_table *table)
{
	t_node	*tmp;
	int		i;

	check_command(table->tree->root);
	init_fd(table);
	i = 0;
	tmp = table->tree->root;
	table->cmd_op = (char ***)malloc(sizeof(char **) * table->cmd_cnt);
	if (!table->cmd_op)
	{
		error_print("cmd_op allocate fail in pre_execute");
		exit (12);
	}
	while (i < table->cmd_cnt && tmp)
	{
		if (tmp->type == CMD_E)
		{
			table->cmd_op[i] = get_option(tmp);
			i++;
		}
		tmp = tmp->left;
	}
}

// 여기서 커맨드랑 옵션 합치고 ... 패스 있는지 확인하고 ... 