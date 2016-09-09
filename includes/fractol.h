/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:43:20 by lgosse            #+#    #+#             */
/*   Updated: 2016/07/19 09:55:47 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define WIN 1000

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sline;
	int			endian;
}				t_img;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_parse		*parse;
	int			frac;
	void		(*tab[11])(struct s_fractol *, double[10], int);
	int			imax;
	int			itervalue;
	int			lockmod;
	int			color;
	double		initx;
	double		inity;
	double		mr;
	double		zr;
	double		zoom_x;
	double		zoom_y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		deb_x;
	double		deb_y;
}				t_fractol;

/*
** Exit functions
*/

void			ft_exit_fractol(t_fractol *fractol);
void			ft_exit_give_usage(t_fractol *fractol);

/*
** Predicate
*/

int				ft_check_parse(char *arg, t_fractol *fractol);

/*
** Initialization functions
*/

void			ft_init_fractol(t_fractol *fractol, char *name);
void			ft_init_values(t_fractol *fractol);
void			ft_init_first_values(t_fractol *fractol);
int				ft_reinit_fractol(t_fractol *fractol);

/*
** Hooks
*/

int				ft_handlemouse(int button, int x, int y, t_fractol *fractol);
int				ft_keypress(int keycode, t_fractol *fractol);
int				ft_handle_key_hooks(int keycode, t_fractol *fractol);
int				ft_motion_hook(int x, int y, t_fractol *fractol);
void			ft_getzoom(t_fractol *fractol, int pm);
void			ft_getmove(t_fractol *fractol, int pm);
int				ft_getcolor(t_fractol *fractol, int color);
int				ft_getcolornewton(t_fractol *fractol, double x, double y);
int				ft_getspeccolor(t_fractol *fractol, int i);

/*
** Fractals
*/

void			ft_algo(t_fractol *fractol);
void			ft_mandelbrot(t_fractol *fractol, double tab[10], int i);
void			ft_julia(t_fractol *fractol, double tab[10], int imax);
void			ft_burningship(t_fractol *fractol, double tab[10], int imax);
void			ft_mandelbrotp3(t_fractol *fractol, double tab[10], int imax);
void			ft_juliap3(t_fractol *fractol, double tab[10], int imax);
void			ft_newton(t_fractol *fractol, double tab[10], int imax);
void			ft_truc(t_fractol *fractol, double tab[10], int imax);
void			ft_mandelbrotpdclr(t_fractol *fractol, double tab[10],
	int imax);
void			ft_birdofprey(t_fractol *fractol, double tab[10], int imax);
void			ft_druid(t_fractol *fractol, double tab[10], int imax);
void			ft_mandytree(t_fractol *fractol, double tab[10], int imax);

void			ft_pixel_put_to_image(t_fractol *fractol, int x, int y,
					int color);

#endif
