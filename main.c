#include "so_long.h"

int main(int ac, char **av)
{
	void	*win;
	void	*mlx;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 256, 256, "so_long");
	mlx_loop(mlx);
}