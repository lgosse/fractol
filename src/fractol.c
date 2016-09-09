/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:44:52 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:47 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_algo(t_fractol *fractol)
{
	double	tab[10];
	void	(*func)(t_fractol *, double[10], int);
	int		imax;

	func = fractol->tab[fractol->frac];
	imax = fractol->imax;
	tab[0] = -1;
	tab[2] = fractol->initx;
	tab[3] = fractol->inity;
	tab[4] = fractol->zoom_x;
	tab[5] = fractol->zoom_y;
	tab[6] = fractol->x1;
	tab[7] = fractol->deb_x;
	tab[8] = fractol->y1;
	tab[9] = fractol->deb_y;
	while (++tab[0] < WIN)
	{
		tab[1] = -1;
		while (++tab[1] < WIN)
			func(fractol, tab, imax);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		ft_exit_malloc_error();
	if (!(fractol->parse = ft_parse(ac, av, "")))
		ft_exit_malloc_error();
	if (ac > 1 && ft_check_parse(fractol->parse->args->content, fractol))
	{
		ft_init_fractol(fractol, fractol->parse->args->content);
		ft_init_values(fractol);
		mlx_hook(fractol->win, 6, 1L << 8, &ft_motion_hook, fractol);
		mlx_hook(fractol->win, 2, 1 << 9, &ft_keypress, fractol);
		mlx_key_hook(fractol->win, &ft_handle_key_hooks, fractol);
		mlx_mouse_hook(fractol->win, &ft_handlemouse, fractol);
		ft_algo(fractol);
		mlx_loop(fractol->mlx);
	}
	else
		ft_exit_give_usage(fractol);
	return (1);
}
