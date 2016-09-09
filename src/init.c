/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 12:11:02 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:50:04 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_reinit_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img->img);
	if (!(fractol->img->img = mlx_new_image(fractol->mlx, WIN,
		WIN)))
		ft_exit_malloc_error();
	fractol->img->data = mlx_get_data_addr(fractol->img->img,
		&fractol->img->bpp, &fractol->img->sline, &fractol->img->endian);
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_algo(fractol);
	return (1);
}

void	ft_init_values(t_fractol *fractol)
{
	fractol->initx = 0;
	fractol->inity = 0;
	fractol->imax = 50;
	fractol->itervalue = 20;
	fractol->zr = 1 / 1.1;
	fractol->mr = 0.05;
	fractol->color = 0;
	fractol->lockmod = 0;
	fractol->deb_x = 0;
	fractol->deb_y = 0;
	ft_init_first_values(fractol);
	fractol->zoom_x = WIN / (fractol->x2 - fractol->x1);
	fractol->zoom_y = WIN / (fractol->y2 - fractol->y1);
	fractol->tab[0] = &ft_mandelbrot;
	fractol->tab[1] = &ft_julia;
	fractol->tab[2] = &ft_burningship;
	fractol->tab[3] = &ft_mandelbrotp3;
	fractol->tab[4] = &ft_juliap3;
	fractol->tab[5] = &ft_newton;
	fractol->tab[6] = &ft_truc;
	fractol->tab[7] = &ft_mandelbrotpdclr;
	fractol->tab[8] = &ft_birdofprey;
	fractol->tab[9] = &ft_druid;
	fractol->tab[10] = &ft_mandytree;
}

void	ft_init_fractol(t_fractol *fractol, char *name)
{
	if (!(fractol->mlx = mlx_init()) ||
		!(fractol->win = mlx_new_window(fractol->mlx, WIN, WIN,
		name)) || !(fractol->img = (t_img *)malloc(sizeof(t_img))) ||
		!(fractol->img->img = mlx_new_image(fractol->mlx, WIN,
		WIN)))
		ft_exit_malloc_error();
	fractol->img->data = mlx_get_data_addr(fractol->img->img,
		&fractol->img->bpp, &fractol->img->sline, &fractol->img->endian);
}
