/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:37:47 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 17:53:47 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw(t_fract *t)
{
	mlx_clear_window(t->mlx, t->win);
	ft_bzero(t->data, WID * WID * 4);
	makethreads(t);
	mlx_put_image_to_window(t->mlx, t->win, t->nim, 0, 0);
	print_string(t);
	if (t->flaghelp == 1)
		print_help(t);
}

void	printwin(t_fract *t)
{
	mlx_put_image_to_window(t->mlx, t->win, t->nim, 0, 0);
	print_string(t);
	mlx_hook(t->win, 2, 0, keys, t);
	mlx_hook(t->win, 4, 0, mouses, t);
	mlx_hook(t->win, 6, 0, mouse_move, t);
	mlx_loop(t->mlx);
}

void	start(char *i)
{
	t_fract *t;

	t = (t_fract*)malloc(sizeof(t_fract));
	t->i = ft_strlen(i);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WID, WID, "FRACTOL");
	t->nim = mlx_new_image(t->mlx, WID, WID);
	t->data = (int*)mlx_get_data_addr(t->nim, &t->bpp,
	&t->line_size, &t->endian);
	t->coofz = 1;
	t->zoom = 0.5;
	t->movex = (t->i == 5) ? 0 : -0.5;
	t->movey = 0;
	t->maxiter = 128;
	t->koof = 0;
	t->coofmove = 10;
	t->cc = 1;
	t->col = 0;
	t->trd = (pthread_t *)malloc(sizeof(pthread_t) * R);
	t->trd_arg = (t_fl*)malloc(R * sizeof(t_fl));
	t->name = i;
	t->flaghelp = 0;
	makethreads(t);
	printwin(t);
}

int		main(int ac, char **av)
{
	char *i;

	if (ac != 2)
	{
		ft_putstr("usage : ./fractol [fractals]\nfractals:\nMandelbrot");
		ft_putstr("\nJulia\nBurningShip\nSpider\n");
		exit(0);
	}
	if (ft_strcmp(av[1], "Mandelbrot") != 0 && ft_strcmp(av[1], "Julia") !=
	0 && ft_strcmp(av[1], "BurningShip") != 0 && ft_strcmp(av[1], "Spider"))
	{
		ft_putstr("usage : ./fractol [fractals]\nfractals:\nMandelbrot");
		ft_putstr("\nJulia\nBurningShip\nSpider\n");
		exit(0);
	}
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		i = "Mandelbrot";
	if (ft_strcmp(av[1], "Julia") == 0)
		i = "Julia";
	if (ft_strcmp(av[1], "BurningShip") == 0)
		i = "BurningShip";
	if (ft_strcmp(av[1], "Spider") == 0)
		i = "Spider";
	start(i);
	return (0);
}
