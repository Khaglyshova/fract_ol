/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:30:44 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:28:55 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		color(int x, t_fl *f)
{
	int red;
	int green;
	int blue;

	red = 0;
	green = (15 * f->i) % 255;
	blue = 2 * f->i;
	if (x == 1)
	{
		red = (255 - f->i * 2.5);
		blue = (f->i * 3) % 255;
		green = 255 - f->i * 4.8;
	}
	if (x == 2)
	{
		red = (66 * f->i) % 255;
		blue = 7 * f->i;
		green = 6 * f->i;
	}
	return ((red << 16) | (green << 8) | blue);
}

void	print_string(t_fract *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10, 13143295, "name:");
	mlx_string_put(t->mlx, t->win, 120, 10, 13143295, t->name);
	mlx_string_put(t->mlx, t->win, 10, 30, 13143295, "zoom:");
	mlx_string_put(t->mlx, t->win, 120, 30, 13143295, ft_ltoa(t->zoom));
	mlx_string_put(t->mlx, t->win, 10, 50, 13143295, "iteration:");
	mlx_string_put(t->mlx, t->win, 120, 50, 13143295, ft_itoa(t->maxiter));
	mlx_string_put(t->mlx, t->win, 10, 70, 13143295, "For help press H");
}

void	print_help(t_fract *t)
{
	help_frame(t);
	help_str(t);
	mlx_string_put(t->mlx, t->win, 240, 10, 4194381, t->str_help0);
	mlx_string_put(t->mlx, t->win, 240, 30, 4194381, t->str_help1);
	mlx_string_put(t->mlx, t->win, 240, 50, 4194381, t->str_help2);
	mlx_string_put(t->mlx, t->win, 240, 70, 4194381, t->str_help3);
	mlx_string_put(t->mlx, t->win, 240, 90, 4194381, t->str_help4);
	mlx_string_put(t->mlx, t->win, 240, 110, 4194381, t->str_help6);
	mlx_string_put(t->mlx, t->win, 240, 130, 4194381, t->str_help7);
	mlx_string_put(t->mlx, t->win, 240, 150, 4194381, t->str_help5);
}

void	help_str(t_fract *t)
{
	t->str_help0 = "Enter   change fractol";
	t->str_help1 = "1|2     change color";
	t->str_help2 = "Space   stop Julia";
	t->str_help3 = "Scroll  zoom";
	t->str_help4 = "Arrows  move";
	t->str_help5 = "ESC     close fractol";
	t->str_help6 = "R       refresh fractol";
	t->str_help7 = "H       hide the help window";
}

void	help_frame(t_fract *t)
{
	int x;
	int y;

	y = 8;
	while (y < 172)
	{
		x = 230;
		while (x < 600)
		{
			if (x == 305 || x == 230 || y == 8 || x == 599 || y == 171)
				mlx_pixel_put(t->mlx, t->win, x, y, 4194381);
			else
				mlx_pixel_put(t->mlx, t->win, x, y, 16772838);
			x++;
		}
		y++;
	}
}
