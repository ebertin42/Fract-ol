#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <stdio.h>
typedef struct		s_window
{
	void		*mlx;
	void		*win;
}			t_window;

typedef struct		s_params
{
	int		i_max;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		zoom;
	int		select;
}			t_params;

typedef struct		s_all
{
	t_window	win;
	t_params	p;
}			t_all;

int			main(int argc, char **argv);
int			key_funct(int key, void *params);
void			*move(t_all *all);
int			*palette(int select, int *color, int i_max);
