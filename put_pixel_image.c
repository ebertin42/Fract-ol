/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:51:34 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 17:51:31 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_image(int x, int y, int color, t_image *i)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	i->str[(x * 4) + (WIDTH * 4 * y)] = b;
	i->str[(x * 4) + (WIDTH * 4 * y) + 1] = g;
	i->str[(x * 4) + (WIDTH * 4 * y) + 2] = r;
	i->str[(x * 4) + (WIDTH * 4 * y) + 3] = 0;
}

