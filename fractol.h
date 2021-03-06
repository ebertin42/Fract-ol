/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:38 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 17:51:25 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <stdio.h>
# define WIDTH 900
# define HEIGHT 600
typedef struct		s_window
{
	void		*mlx;
	void		*win;
}					t_window;

typedef struct		s_image
{
	void			*ima;
	char			*str;
	int				bpp;
	int				sl;
	int				e;
}					t_image;

typedef struct		s_params
{
	int			i_max;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom;
	int			select;
	int			fractal;
	t_image		i;
}					t_params;

typedef struct		s_julia
{
	float						c_r;
	float						c_i;
}									t_julia;

typedef struct		s_all
{
	t_window	win;
	t_params	p;
	t_julia		j;
}									t_all;

int			main(int argc, char **argv);
int			key_funct(int key, void *params);
void		*move(t_all *all);
int			*palette(int select, int *color, int i_max);
int			mouse_funct(int key, int x, int y, t_all *a);
void		put_pixel_image(int x, int y, int color, t_image *i);
void		*julia(t_all *all);
void		*m_julia(t_all *a, int x_h, int y_h);
void		*k_julia(t_all *a);
