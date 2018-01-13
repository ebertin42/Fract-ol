/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:12:29 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/06 18:44:05 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static void	free_inside(t_amere data)
{
	free(data.x);
	free(data.y);
	free(data.z);
	free(data.color);
}

static void	free_data(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	while (j < all->data->nb_line)
	{
		i = 0;
		while (i < all->data[j].point)
		{
			free(all->data[j].data[i]);
			i++;
		}
		free_inside(all->data[j]);
		j++;
	}
	free(all->data);
}

*/static void	key_rotate(int key, t_all *all)
{
	if (key == 123 || key == 65361)
		all->p.x1 *= 1.1;
	if (key == 124 || key == 65362)
		all->p.y1 *= 1.1;
	if (key == 125 || key == 65363)
		all->p.x1 *= 0.9;
	if (key == 126 || key == 65364)
		all->p.y1 *= 0.9;
	/*if (key == 0)
		all->window.rotate_z -= 0.1;
	if (key == 2)
		all->window.rotate_z += 0.1;
	*/mlx_clear_window(all->win.mlx, all->win.win);
	move(all);
}

static void	key_re(int key, t_all *a)
{
	if (key == 65450)
		if (a->p.i_max * 10 > 0)
			a->p.i_max *= 10;
	if (key == 65455)
		if (a->p.i_max / 10 > 0)
			a->p.i_max /= 10;
	if (key >= 49 && key <= 51)
		a->p.select = key - 48;
	mlx_clear_window(a->win.mlx, a->win.win);
	move(a);
}

int			key_funct(int key, void *param)
{
	t_all		*all;

	printf("%d\n", key);
	all = (t_all*)param;
	if (key == 53 || key == 65307)
	{
		//free_data(all);
		exit(0);
	}
	if ((key >= 123 && key <= 126) || (key >= 65361 && key <= 65364))
		key_rotate(key, all);
	if ((key == 65450 || key == 65455) || (key >= 49 && key <= 51))
		key_re(key, all);
	return (0);
}
