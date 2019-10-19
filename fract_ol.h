/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:38:04 by mroland-          #+#    #+#             */
/*   Updated: 2019/06/29 19:45:00 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# define WID 1200
# define R 4
# define ABS(number) ((number) > 0 ? (number):-(number))

typedef struct		s_fl
{
	long double		t_im;
	long double		t_re;
	int				y;
	int				*data;
	long double		c_im;
	long double		c_re;
	int				max_i;
	int				i;
	int				color;
	double			fzm;
	double			fmx;
	double			fmy;
	int				cc;
	int				col;
	double			pr;
	double			pi;
	long double		new_re;
	long double		new_im;
	long double		old_re;
	long double		old_im;
	long double		zoom;
	long double		movex;
	long double		movey;
	int				yy;
	int				xx;
	int				maxiter;
	int				coofz;
	long int		coofmove;
	char			*name;
}					t_fl;

typedef struct		s_fract
{
	char			*name;
	int				h;
	int				w;
	int				*data;
	double			pr;
	double			pi;
	int				i;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			j_im;
	double			j_re;
	double			js_im;
	double			js_re;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiter;
	void			*nim;
	int				bpp;
	int				line_size;
	int				endian;
	void			*mlx;
	void			*win;
	int				fract;
	pthread_t		*trd;
	int				cc;
	t_fl			*trd_arg;
	int				koof;
	int				yy;
	int				xx;
	long int		coofmove;
	double			coofz;
	int				k;
	int				col;
	int				flaghelp;
	char			*str_help0;
	char			*str_help1;
	char			*str_help2;
	char			*str_help3;
	char			*str_help4;
	char			*str_help5;
	char			*str_help6;
	char			*str_help7;
}					t_fract;

void				*mandelbrot(void *fl);
int					changex_y(t_fl *f, int n, t_fract *o);
int					intjoin(t_fl *tr, int k, t_fract *f);
int					makethreads(t_fract *f);
void				mandelbrot2(t_fl *t, int x, int y);
void				start(char *i);
void				*julia(void *fl);
void				julia2(t_fl *f, int x, int y);
int					mouse_move(int x, int y, t_fract *t);
void				draw(t_fract *t);
void				changefrl(t_fract *f);
int					color(int x, t_fl *f);
void				stopjulia(t_fract *f);
void				changefrl(t_fract *f);
int					keys(int key, t_fract *t);
void				arrow(int key, double x, t_fract *t);
int					closemap(t_fract *t);
void				print_help(t_fract *t);
void				print_string(t_fract *t);
int					mouses(int ms, int x, int y, t_fract *t);
void				printwin(t_fract *t);
void				start(char *i);
void				flagcheck(t_fract *t);
void				help_frame(t_fract *t);
void				help_str(t_fract *t);
void				*burningship(void *fl);
void				burningship2(t_fl *t, int x, int y);
void				*spider(void *fl);
void				spider2(t_fl *t, int x, int y);
void				zoom(int zm, t_fract *t);

#endif
