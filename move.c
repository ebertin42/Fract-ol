/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:33 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 17:56:39 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*move(t_all *a)
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
			if (i != a->p.i_max)
				put_pixel_image(x, y, color[i], &a->p.i);
			y++;
		}
		x++;
	}
    mlx_put_image_to_window(a->win.mlx, a->win.win, a->p.i.ima, 0, 0);
	free(color);
	return (a);
}
