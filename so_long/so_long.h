/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:29:17 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:32:32 by jinkim2          ###   ########seoul.kr  */
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

# define W_KEY	13
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2
# define ESC_KEY	53

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
	void	*cha;
	void	*col;
	void	*key;
	void	*tile;
	void	*wall;
	int		width;
	int		height;
	int		size;
}				t_image;

typedef struct s_key{
	int	x;
	int	y;
	int	move;
}				t_key;

typedef struct s_map{
	int		coll;
	int		pos;
	int		exit;
	int		curc;
	int		exit_loca_x;
	int		exit_loca_y;
}				t_map;

typedef struct s_sl{
	void	*mlx;
	void	*win;
	t_map	map;
	t_key	loc;
	t_image	img;
	int		width;
	int		height;
	char	**m;
}				t_sl;

void	move_w(t_sl *s);
void	move_s(t_sl *s);
void	move_a(t_sl *s);
void	move_d(t_sl *s);
int		get_move(int key, t_sl *s);

void	image_to_window(t_sl *s, int w, int h);
void	put_image(t_sl *s);
void	init_image(t_sl *s);

char	*make_map(t_sl *s, int fd);
void	check_wall(char **map, int height, int width);
void	check_content(char *str, t_sl *s);
char	**is_valid_map(char *map, t_sl *s);

void	ft_error(char *str);
int		ft_strcmp(char *str, char *str2);
void	get_xy(t_sl *s);
void	game_clear(void);
int		exit_game(void);

#endif