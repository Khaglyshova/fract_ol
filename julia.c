/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:25:35 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:26:50 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia2(t_fl *f, int x, int y)
{
	double	xtemp;

	f->pi = (f->y - WID / 2.0) * 4.0 / WID / f->zoom + f->movey;
	f->pr = (x - WID / 2.0) * 4.0 / WID / f->zoom + f->movex;
	f->i = 0;
	while ((f->pr * f->pr + f->pi * f->pi) < 4 && f->i < f->maxiter)
	{
		xtemp = f->pr * f->pr - f->pi * f->pi;
		f->pi = 2 * f->pr * f->pi + f->new_im;
		f->pr = xtemp + f->new_re;
		f->i++;
	}
	if (f->i == f->maxiter)
		f->cc = 0;
	else
		f->cc = color(f->col, f);
	f->data[x + y * WID] = f->cc;
}

void	*julia(void *fl)
{
	t_fl	*f;
	int		x;
	int		y;

	f = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = 0;
		while (x < WID)
		{
			julia2(f, x, y);
			x++;
		}
		y++;
		f->y++;
	}
	return (NULL);
}

int		mouse_move(int x, int y, t_fract *t)
{
	t->j_re = (x - WID / 2.0) * 4.0 / WID;
	t->j_im = (y - WID / 2.0) * 4.0 / WID;
	draw(t);
	return (0);
}

void	stopjulia(t_fract *f)
{
	if (f->k == 1)
		f->k = 0;
	else
	{
		f->js_re = f->j_re;
		f->js_im = f->j_im;
		f->k = 1;
	}
}
