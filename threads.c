/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:05:43 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:13:08 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	changefrl(t_fract *f)
{
	if (f->i == 10)
	{
		f->name = "Julia";
		f->k = 0;
		f->i = 5;
		f->movex = 0;
	}
	else if (f->i == 5)
	{
		f->name = "BurningShip";
		f->i = 11;
		f->movex = -0.5;
	}
	else if (f->i == 11)
	{
		f->name = "Spider";
		f->i = 6;
	}
	else if (f->i == 6)
	{
		f->name = "Mandelbrot";
		f->i = 10;
	}
}

int		changex_y(t_fl *f, int n, t_fract *o)
{
	f->data = (int*)malloc(((WID * WID) / R) * sizeof(int));
	f->i = 0;
	f->col = o->col;
	f->zoom = o->zoom;
	f->movex = o->movex;
	f->movey = o->movey;
	if (o->i == 5)
	{
		f->new_re = o->j_re;
		f->new_im = o->j_im;
		if (o->k == 1)
		{
			f->new_re = o->js_re;
			f->new_im = o->js_im;
		}
	}
	f->coofz = o->coofz;
	f->coofmove = o->coofmove;
	f->cc = o->cc;
	f->maxiter = o->maxiter;
	f->y = WID / R * n;
	o->maxiter = f->maxiter;
	f->name = o->name;
	return (1);
}

int		intjoin(t_fl *tr, int k, t_fract *f)
{
	int i;

	i = 0;
	while (i < (WID * WID / R))
	{
		f->data[k] = tr->data[i];
		k++;
		i++;
	}
	free(tr->data);
	return (k);
}

int		makethreads(t_fract *f)
{
	int rc;
	int k;
	int n;

	n = 0;
	k = 0;
	while (n < R)
	{
		changex_y(&f->trd_arg[n], n, f);
		if (f->i == 10)
			rc = pthread_create(&(f->trd[n]), NULL, mandelbrot, &f->trd_arg[n]);
		if (f->i == 5)
			rc = pthread_create(&(f->trd[n]), NULL, julia, &f->trd_arg[n]);
		if (f->i == 11)
			rc = pthread_create(&f->trd[n], NULL, burningship, &f->trd_arg[n]);
		if (f->i == 6)
			rc = pthread_create(&f->trd[n], NULL, spider, &f->trd_arg[n]);
		n++;
	}
	while (n--)
		pthread_join(f->trd[n], NULL);
	n = -1;
	while (n++ < (R - 1))
		k = intjoin(&f->trd_arg[n], k, f);
	return (1);
}

int		closemap(t_fract *t)
{
	(void)t;
	exit(0);
	return (0);
}
