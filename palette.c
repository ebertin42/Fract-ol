/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:57 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 15:48:03 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*palette(int select, int *color, int i_max)
{
	int i;

	i = 0;
	if (select == 1)
		while (++i < i_max)
			color[i] = 0x0000FF << i >> 10;
	if (select == 2)
		while (++i < i_max)
			color[i] = i * 255 * i_max;
	if (select == 3)
		while (++i < i_max)
			color[i] = 0x0000FF << i;
	return (color);
}
