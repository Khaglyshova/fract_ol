/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:44:28 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:12:09 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		mouses(int ms, int x, int y, t_fract *t)
{
	int zm;

	if (ms == 1)
	{
		t->movex += ((x - WID / 2.0) / (0.5 * t->zoom * WID));
		t->movey += ((y - WID / 2.0) / (0.5 * t->zoom * WID));
	}
	if (ms == 5)
	{
		t->zoom *= 1.25;
		zm = t->zoom;
		while ((zm / t->coofmove) > 0)
		{
			t->coofmove *= 10;
			zm /= 10;
			t->coofz++;
		}
		t->maxiter += (t->coofz * 1.5);
	}
	if (ms == 4)
		zoom(1, t);
	draw(t);
	return (0);
}

void	zoom(int zm, t_fract *t)
{
	if (t->zoom / 1.5 >= 0.25)
	{
		t->zoom /= 1.5;
		zm = t->zoom;
		while ((zm / t->coofmove) > 0)
		{
			t->coofmove /= 10;
			zm *= 10;
			t->coofz--;
		}
		t->maxiter -= (t->coofz / 1.5);
	}
}

int		keys(int key, t_fract *t)
{
	if (key == 124 || key == 125)
		arrow(key, 0.25, t);
	if (key == 123 || key == 126)
		arrow(key, -0.25, t);
	if (key == 53)
		closemap(t);
	if (key == 69 || key == 24)
		arrow(key, 1, t);
	if (key == 78 || key == 27)
		arrow(key, -20, t);
	if (key == 15)
		arrow(key, 0, t);
	if (key == 18)
		arrow(key, -1, t);
	if (key == 19)
		arrow(key, 1, t);
	if (key == 49 && t->i == 5)
		stopjulia(t);
	if (key == 36)
		changefrl(t);
	if (key == 4)
		flagcheck(t);
	draw(t);
	return (0);
}

void	arrow(int key, double x, t_fract *t)
{
	char *i;

	if (key == 126 || key == 125)
		t->movey += x / t->coofmove;
	else if (key == 124 || key == 123)
		t->movex += x / t->coofmove;
	else if ((key == 69 || key == 78 || key == 27 ||
				key == 24) && t->maxiter > 20)
		t->maxiter += x;
	else if (key == 15)
	{
		i = t->name;
		free(t);
		start(i);
	}
	else if (key == 18 || key == 19)
	{
		t->col += x;
		if (t->col < 0)
			t->col = 2;
		if (t->col > 2)
			t->col = 0;
	}
}

void	flagcheck(t_fract *t)
{
	if (t->flaghelp == 1)
		t->flaghelp = 0;
	else
		t->flaghelp = 1;
}
