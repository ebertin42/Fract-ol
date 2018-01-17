#include "fractol.h"

void		*julia(t_all *a)
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int	i;
	int	x;
	int	y;
	float	tmp;
	int	*color;

    a->p.i.ima = mlx_new_image(a->win.mlx, WIDTH, HEIGHT);
    a->p.i.str = mlx_get_data_addr(a->p.i.ima, &a->p.i.bpp, &a->p.i.sl, &a->p.i.e);

	color = (int*)malloc(sizeof(int) * a->p.i_max);
	color = palette(a->p.select, color, a->p.i_max);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c_r = 0.285;
			c_i = 0.01;
			z_r = x / a->p.zoom + a->p.x1;
			z_i = y / a->p.zoom + a->p.y1;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < a->p.i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i != a->p.i_max)
				put_pixel_image(x, y, color[i], &a->p.i);
			y++;
		}
		x++;
	}
	mlx_clear_window(a->win.mlx, a->win.win);
    mlx_put_image_to_window(a->win.mlx, a->win.win, a->p.i.ima, 0, 0);
	free(color);
	return (a);
}
