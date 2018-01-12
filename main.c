#include "fractol.h"
int		main(int argc, char **argv)
{
	t_all		all;
	t_params	p;
	(void)argc;
	t_window	win;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1600, 900, "Fractol");
	p.i_max = ft_atoi(argv[1]);
	
	p.x1 = -2.1;
	p.x2 = 0.6;
	p.y1 = -1.2;
	p.y2 = 1.2;
	p.zoom = 400;
	p.select = 1;
	float		image_x = p.x2 - p.x1;
			image_x = image_x * p.zoom;
	float		image_y = p.y2 - p.y1;
			image_y = image_y * p.zoom;
		
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int	i;
	int	x;
	int	y;
	float	tmp;
	int	*color;
	
	color = (int*)malloc(sizeof(int) * p.i_max);
	color = palette(p.select, color, p.i_max);
	x = 0;
	while (x < 1600)
	{
		y = 0;	
		while (y < 900)
		{
			c_r = x / p.zoom + p.x1;
			c_i = y / p.zoom + p.y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < p.i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == p.i_max)
				(void)i;//mlx_pixel_put(win.mlx, wiin.win, x + 10, y + 10, 0xFFFFFF);
			else
				mlx_pixel_put(win.mlx, win.win, x + 10, y + 10, color[i]);
			y++;
		}
		x++;
	}
	all.win = win;
	all.p = p;
	free(color);
	mlx_key_hook(win.win, key_funct, &all);
	mlx_loop(win.mlx);
	return (0);
}
