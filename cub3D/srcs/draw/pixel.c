/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:36:55 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 17:37:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_put_pixel(t_table *table, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		index = (x * table->bpp / 8) + (y * table->size_line);
		table->data_addr[index] = color;
		table->data_addr[++index] = color >> 8;
		table->data_addr[++index] = color >> 16;
	}
}

int	ft_get_pixel(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
