#include "../cub3D.h"

int	close_win(void *param)
{
	(void)param;
	exit(0);
}

static void	key_action(t_table *table)
{
	if (table->keys.forward)
		forward(table);
	if (table->keys.backward)
		backward(table);
	if (table->keys.left)
		left(table);
	if (table->keys.right)
		right(table);
	if (table->keys.look_left)
		look_left(table);
	if (table->keys.look_right)
		look_right(table);
}

int	key_up(int keycode, void *param)
{
	t_table	*table;

	table = (t_table *)param;
	if (keycode == ARROW_LEFT)
		table->keys.look_left = 0;
	else if (keycode == ARROW_RIGHT)
		table->keys.look_right = 0;
	else if (keycode == W)
		table->keys.forward = 0;
	else if (keycode == A)
		table->keys.left = 0;
	else if (keycode == S)
		table->keys.backward = 0;
	else if (keycode == D)
		table->keys.right = 0;
	return (0);
}

int	key_down(int keycode, void *param)
{
	t_table	*table;

	table = (t_table *)param;
	if (keycode == KEY_ESC)
		close_win(NULL);
	else if (keycode == ARROW_LEFT)
		table->keys.look_left = 1;
	else if (keycode == ARROW_RIGHT)
		table->keys.look_right = 1;
	else if (keycode == W)
		table->keys.forward = 1;
	else if (keycode == A)
		table->keys.left = 1;
	else if (keycode == S)
		table->keys.backward = 1;
	else if (keycode == D)
		table->keys.right = 1;
	return (0);
}

int	game_update(void *param)
{
	t_table		*table;

	table = (t_table *)param;
	ft_draw(table);
	key_action(table);
	return (0);
}
