/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:20:23 by jinkim2           #+#    #+#             */
/*   Updated: 2022/10/03 18:20:25 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	look_left(t_table *table)
{
	table->player.angle = bound_angle(table->player.angle - SPEED_LOOK);
}

void	look_right(t_table *table)
{
	table->player.angle = bound_angle(table->player.angle + SPEED_LOOK);
}
