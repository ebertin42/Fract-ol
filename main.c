/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:12 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 17:56:45 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_all		all;
	t_params	p;
	(void)argc;
	t_window	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, "Fractol");
	p.i.ima = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	p.i.str = mlx_get_data_addr(p.i.ima, &p.i.bpp, &p.i.sl, &p.i.e);

	p.i_max = ft_atoi(argv[1]);
	p.x1 = -2.1;
	p.x2 = 0.6;
	p.y1 = -1.2;
	p.y2 = 1.2;
	p.zoom = 200;
	p.select = 1;

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
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
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
			
			if (i != p.i_max)
				put_pixel_image(x, y, color[i], &p.i);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(win.mlx, win.win, p.i.ima, 0, 0);
	all.win = win;
	all.p = p;
	free(color);
	mlx_key_hook(win.win, key_funct, &all);
	mlx_mouse_hook(win.win, mouse_funct, &all);
	mlx_loop(win.mlx);
	return (0);
}
