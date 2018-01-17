/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebertin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:47:49 by ebertin           #+#    #+#             */
/*   Updated: 2018/01/15 15:47:51 by ebertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int   mouse_funct(int key, int x, int y, t_all *a)
{
  (void)x;
  (void)y;
/*  if (key == 1)
{
  if (a->p.pause == 0)
    a->p.pause = 1;
  else
    a->p.pause = 0;
}*/
printf("%d\n", key);
printf("%d\n", x);
printf("%d\n", y);
if (key == 4)
{
  a->p.zoom *= 1.1;
  a->p.x1 /= 1.1;
  a->p.y1 /= 1.1;
  /*a->p.x1 = a->p.x1 - x / WIDTH / 2;
  a->p.y1 = a->p.y1 - y / HEIGHT / 2;*/
  /*a->p.x1 = (a->p.x1 + ((WIDTH - (WIDTH / 1.1)) / 2) +
      (x - WIDTH / 2) * (1 - (1 / 1.1))) * 1.1;
  a->p.y1 = (a->p.y1 + ((HEIGHT - (HEIGHT / 1.1)) / 2) +
      (y - HEIGHT / 2) * (1 - (1 / 1.1))) * 1.1;*/
}
if (key == 5)
{
  a->p.zoom /= 1.1;
  a->p.x1 *= 1.1;
  a->p.y1 *= 1.1;
  /*a->p.x1 = a->p.x1 / 1.1 - ((WIDTH - (WIDTH / 1.1)) / 2) / 1.1*/
}
/*printf("%f\n", a->p.x1);
printf("%f\n", a->p.y1);
printf("%f\n", a->p.zoom);*/
if (a->p.fractal == 1)
  move(a);
else
  julia(a);
return (0);
}
