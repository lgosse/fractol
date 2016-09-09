/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:50 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/27 10:46:33 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_motion_hook(int x, int y, t_fractol *fractol)
{
	if (x >= 0 && x <= WIN && y >= 0 && y <= WIN)
		if (fractol->lockmod)
		{
			fractol->initx = (double)x / WIN * 1.1 - 1;
			fractol->inity = (double)y / WIN * 1.1 - 1;
			ft_reinit_fractol(fractol);
		}
	(void)fractol;
	return (1);
}

int		ft_handle_key_hooks(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		ft_exit_fractol(fractol);
	else if (keycode == 15)
	{
		ft_init_values(fractol);
		ft_reinit_fractol(fractol);
	}
	else if (keycode == 49)
		fractol->lockmod ^= 1;
	else if (keycode == 8)
	{
		fractol->frac = (fractol->frac + 1) % 11;
		ft_init_values(fractol);
		ft_reinit_fractol(fractol);
	}
	return (1);
}

int		ft_handlemouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->zoom_x *= 1.1;
		fractol->zoom_y *= 1.1;
		fractol->deb_x += ((fractol->x2 - fractol->x1) / 20.05) * fractol->zr;
		fractol->deb_y += ((fractol->y2 - fractol->y1) / 20) * fractol->zr;
		fractol->zr /= 1.1;
		fractol->mr /= 1.1;
	}
	else if (button == 5)
	{
		fractol->zoom_x /= 1.1;
		fractol->zoom_y /= 1.1;
		fractol->zr *= 1.1;
		fractol->deb_x -= ((fractol->x2 - fractol->x1) / 20.05) * fractol->zr;
		fractol->deb_y -= ((fractol->y2 - fractol->y1) / 20) * fractol->zr;
		fractol->mr *= 1.1;
	}
	ft_reinit_fractol(fractol);
	(void)x;
	(void)y;
	return (1);
}

int		ft_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == 123)
		fractol->deb_x -= fractol->mr;
	else if (keycode == 124)
		fractol->deb_x += fractol->mr;
	else if (keycode == 125)
		fractol->deb_y += fractol->mr;
	else if (keycode == 126)
		fractol->deb_y -= fractol->mr;
	else if (keycode == 69)
		ft_getzoom(fractol, 1);
	else if (keycode == 78)
		ft_getzoom(fractol, -1);
	else if (keycode == 67 && ft_printf("iter : %d\n", fractol->imax))
		fractol->imax += fractol->itervalue;
	else if (keycode == 75 && ft_printf("iter : %d\n", fractol->imax))
		fractol->imax -= fractol->itervalue;
	else if (keycode == 24)
		fractol->color == 32 ? fractol->color = 0 : fractol->color++;
	else if (keycode == 27)
		fractol->color == -32 ? fractol->color = 0 : fractol->color--;
	else if (keycode == 116 && ft_printf("Iter aug : %d\n", fractol->itervalue))
		return (fractol->itervalue += 5);
	else if (keycode == 121 && ft_printf("Iter aug : %d\n", fractol->itervalue))
		return (fractol->itervalue -= 5);
	return (ft_reinit_fractol(fractol));
}
