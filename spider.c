/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:25:49 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:30:31 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	spider2(t_fl *t, int x, int y)
{
	t->i = 0;
	while (t->i < t->maxiter)
	{
		t->old_re = t->new_re;
		t->old_im = t->new_im;
		t->new_re = t->old_re * t->old_re - t->old_im * t->old_im + t->new_re;
		t->new_im = 2 * t->old_re * t->old_im + t->new_im;
		if ((t->new_re * t->new_re + t->new_im * t->new_im) > 16)
			break ;
		t->i++;
	}
	if (t->i >= t->maxiter)
		t->cc = 0;
	else
		t->cc = color(t->col, t);
	t->data[x + y * WID] = t->cc;
}

void	*spider(void *fl)
{
	t_fl	*t;
	int		y;
	int		x;

	t = (t_fl *)fl;
	y = 0;
	while (y < WID / R)
	{
		x = -1;
		while (++x < WID)
		{
			t->pr = (x - WID / 2.0) / (0.5 * t->zoom * WID) + t->movex;
			t->pi = (t->y - WID / 2.0) / (0.5 * t->zoom * WID) + t->movex;
			t->new_re = t->pr;
			t->new_im = t->pi;
			spider2(t, x, y);
		}
		t->y++;
		y++;
	}
	return (NULL);
}
