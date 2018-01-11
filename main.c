#include "fractol.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window	win;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1600, 900, "Fractol");
	int	i_max = ft_atoi(argv[1]);
	
	float	x1 = -2.1;
	float	x2 = 0.6;
	float	y1 = -1.2;
	float	y2 = 1.2;
	float	zoom = 380;

	float	image_x = x2 - x1;
		image_x = image_x * zoom;
	float	image_y = y2 - y1;
		image_y = image_y * zoom;
		
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int	i;
	int	x;
	int	y;
	float	tmp;
	
	int	color[i_max];
	i = 0;
	while (i < i_max)
	{
		color[i] = i * 255 * i_max;
		i++;		
	}
	
	x = 0;
	while (x < image_x)
	{
		y = 0;	
		while (y < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == i_max)
				(void)i;//mlx_pixel_put(win.mlx, win.win, x + 10, y + 10, 0xFFFFFF);
			else
				mlx_pixel_put(win.mlx, win.win, x + 10, y + 10, color[i]);
			y++;
		}
		x++;
	}
	mlx_loop(win.mlx);
	return (0);
}
