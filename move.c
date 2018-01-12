#include "fractol.h"

void		*move(t_all *a)
{
	float	image_x = a->p.x2 - a->p.x1;
		image_x = image_x * a->p.zoom;
	float	image_y = a->p.y2 - a->p.y1;
		image_y = image_y * a->p.zoom;
		
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int	i;
	int	x;
	int	y;
	float	tmp;
	int	*color;

	color = (int*)malloc(sizeof(int) * a->p.i_max);
	color = palette(a->p.select, color, a->p.i_max);
	x = 0;
	while (x < 1600)
	{
		y = 0;	
		while (y < 900)
		{
			c_r = x / a->p.zoom + a->p.x1;
			c_i = y / a->p.zoom + a->p.y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < a->p.i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == a->p.i_max)
				(void)i;//mlx_pixel_put(a->win.mlx, a->win.win, x + 10, y + 10, 0xFFFFFF);
			else
				mlx_pixel_put(a->win.mlx, a->win.win, x + 10, y + 10, color[i]);
			y++;
		}
		x++;
	}
	free(color);
	return (a);
}
