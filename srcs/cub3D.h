/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:43:01 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 18:11:06 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 1280
# define HEIGHT 720
# define KEY_ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define EAST 0
# define SOUTH 1
# define WEST 2
# define NORTH 3

# define TILE_SIZE 32
# define FOV 60
# define SPEED_MOVE 0.1
# define SPEED_LOOK 0.06

typedef enum e_bool
{
	FALSE_E,
	TRUE_E
}	t_bool;

typedef struct s_map
{
	int		width;
	int		height;
	char	**array;
	char	*tex_path[4];
	int		floor[3];
	int		ceil[3];
}				t_map;

typedef struct s_d_vec
{
	double	x;
	double	y;
}				t_d_vec;

typedef struct s_i_vec
{
	int	x;
	int	y;
}				t_i_vec;

typedef struct s_ray
{
	t_d_vec	dir;
	t_d_vec	step_size;
	t_d_vec	start;
	t_i_vec	map;
	t_d_vec	len;
	t_i_vec	step;
	t_bool	tile_found;
	double	dist;
	t_d_vec	inter;
	t_bool	vertical;
	double	line_len;
}				t_ray;

typedef struct s_player
{
	t_d_vec	pos;
	float	angle;
}				t_player;

typedef struct s_keys
{
	int	left;
	int	right;
	int	look_left;
	int	look_right;
	int	forward;
	int	backward;
}				t_keys;

typedef struct s_draw
{
	double	angle;
	double	ca;
	double	len;
}				t_draw;

typedef struct s_img
{
	void		*img;
	char		*data_addr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_table
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_player	player;
	t_keys		keys;
	t_img		*img_ptr;
	int			prev_x;
	int			mouse_down;
}				t_table;

/************************************************************************
							parser
************************************************************************/
t_bool	parser(int argc, char **argv, t_map *parsing);
void	parser_free(t_map *parsing);
void	parser_start(t_map *parsing);
t_bool	valid_map(t_map *parsing, char **file);
int		get_height(int *mapbeg, char **file);
int		valid_char(char **file, int mapbeg);
int		get_max_len(char **file, int mapbeg);
int		parser_space(t_map *parsing);
void	replace_space(int i, t_map *parsing, char *line);
t_bool	valid_arg(int argc, char **argv);
t_bool	vaild_img(t_map *parsing, char **file);
t_bool	valid_floor(t_map *parsing, char **file);
char	**dup_start(char **argv, char **ret);
void	free_split(char **split);
int		error(char *msg, char *free_ptr);
int		return_split_free(char **split);
int		check_open_wall(char **array, int y, int x);
char	**dup_map(char **array, int height);
void	replace_void(t_map *parsing);

/************************************************************************
							utils
************************************************************************/
void	ft_return_error(const char *err_msg, int system);
double	ft_abs(double a);
double	bound_angle(double angle);
void	xpm_to_image(t_table *table);

/* gnl */
char	*get_next_line(int fd);
size_t	ft_gnl_strlen(char *str);
char	*ft_gnl_substr(char *s, size_t start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *str);

/* ft */
int		ft_isdigit(int c);
int		ft_isspace(char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	**ft_split(const char *str, char c);
void	*ft_memset(void *ptr, int value, size_t num);
int		ft_atoi(const char *str);
/************************************************************************
							hook
************************************************************************/
void	left(t_table *table);
void	right(t_table *table);
void	forward(t_table *table);
void	backward(t_table *table);
int		key_down(int keycode, void *param);
int		key_up(int keycode, void *param);
int		game_update(void *param);

/************************************************************************
							draw
************************************************************************/
void	ft_draw(t_table *table);
int		close_win(void *param);
void	look_left(t_table *table);
void	look_right(t_table *table);
double	get_ray_len(t_table *table, double angle, t_ray *r);
double	ft_abs(double a);
double	bound_angle(double angle);

/************************************************************************
							pixel
************************************************************************/
void	ft_put_pixel(t_table *table, int x, int y, int color);
int		ft_get_pixel(t_img *tex, int x, int y);

/************************************************************************
						raycasting
************************************************************************/
double	get_ray_len(t_table *table, double angle, t_ray *r);

/************************************************************************
						draw
************************************************************************/
void	xpm_to_image(t_table *table);
void	ft_draw(t_table *table);

void	draw_minimap(t_table *table);

#endif
