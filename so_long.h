/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:29:17 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/18 20:54:09 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>

// # define W_KEY

typedef struct s_image{
	char	*character;
	char	*chest;
	char	*key;
	char	*sheet;
	char	*stone;
}				t_image;

typedef struct s_key{
	int	x;
	int	y;
}				t_key;

typedef struct s_sl{
	void	*mlx;
	void	*win;
	t_image	img;
	int		width;
	int		height;
}				t_sl;

#endif