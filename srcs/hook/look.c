#include "../cub3D.h"

void	look_left(t_table *table)
{
	table->player.angle = bound_angle(table->player.angle - SPEED_LOOK);
}

void	look_right(t_table *table)
{
	table->player.angle = bound_angle(table->player.angle + SPEED_LOOK);
}
