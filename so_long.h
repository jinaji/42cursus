/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:29:17 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/19 19:39:01 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

// # define W_KEY

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

int		get_index(char *str);
char	*ft_strndup(char *buff, int idx);
char	*delete_static(char *str);
char	*gnl_strjoin(char *str, char *buff);

t_gnl	*get_node(t_gnl **lst, int fd);
char	*get_return(char **str);
void	free_all(t_gnl **lst, int fd);
int		make_line(t_gnl **lst, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

typedef struct s_image{
	void	*character;
	void	*chest;
	void	*key;
	void	*sheet;
	void	*stone;
}				t_image;

typedef struct s_key{
	int	x;
	int	y;
}				t_key;

typedef struct s_map{
	char	**map;
	int		coll;
}				t_map;

typedef struct s_sl{
	void	*mlx;
	void	*win;
	t_map	map;
	t_key	loca;
	t_image	img;
	size_t		width;
	size_t		height;
}				t_sl;

#endif