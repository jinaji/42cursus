/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:38:08 by gulee             #+#    #+#             */
/*   Updated: 2022/09/05 13:42:15 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token	*last_get(t_token *token)
{
	while (token)
	{
		if (!token->next)
			break ;
		token = token->next;
	}
	return (token);
}

void	token_add(t_token_table *token_table, t_token *new_token)
{
	t_token	*tmp;

	if (!token_table || !new_token)
		return ;
	if (new_token->type == SQUOTE_E)
		new_token->data = ft_strtrim(new_token->data, "\'");
	else if (new_token->type == DQUOTE_E)
		new_token->data = ft_strtrim(new_token->data, "\"");
	if (!token_table->head && token_table->token_count == 0)
		token_table->head = new_token;
	else
	{
		tmp = last_get(token_table->head);
		tmp->next = new_token;
	}
	token_table->token_count += 1;
}

t_token	*token_get(t_token_table *list, int end)
{
	t_token	*token;
	int		index;

	index = 0;
	if (!list || end >= list->token_count)
		return (NULL);
	token = list->head;
	while (index < end)
	{
		token = token->next;
		++index;
	}
	return (token);
}
