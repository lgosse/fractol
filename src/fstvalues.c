/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstvalues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:42:20 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:42:31 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_init_first_values4(t_fractol *fractol)
{
	if (fractol->frac == 3)
	{
		fractol->x1 = -1.45;
		fractol->x2 = 1.45;
		fractol->y1 = -1.2;
		fractol->y2 = 1.2;
	}
	else if (fractol->frac == 8)
	{
		fractol->initx = -0.8988;
		fractol->inity = -0.3411;
		fractol->x1 = -1;
		fractol->x2 = 1;
		fractol->y1 = -1;
		fractol->y2 = 1;
	}
	else if (fractol->frac == 10)
	{
		fractol->initx = -0.6865;
		fractol->inity = -0.5237;
		fractol->x1 = -1;
		fractol->x2 = 1;
		fractol->y1 = -1;
		fractol->y2 = 1;
	}
}

static void	ft_init_first_values3(t_fractol *fractol)
{
	if (fractol->frac == 6)
	{
		fractol->initx = -0.2685;
		fractol->inity = -0.4764;
		fractol->x1 = -0.7;
		fractol->x2 = 1.3;
		fractol->y1 = -0.9;
		fractol->y2 = 1.1;
	}
	else if (fractol->frac == 7 || fractol->frac == 9)
	{
		fractol->initx = -0.2641;
		fractol->inity = -0.6843;
		fractol->x1 = -1.2;
		fractol->x2 = 0.8;
		fractol->y1 = -1;
		fractol->y2 = 1;
		fractol->itervalue = 50;
	}
	else
		ft_init_first_values4(fractol);
}

static void	ft_init_first_values2(t_fractol *fractol)
{
	if (fractol->frac == 2)
	{
		fractol->x1 = -1;
		fractol->x2 = 1.7;
		fractol->y1 = -1;
		fractol->y2 = 2;
		fractol->deb_x = -0.987793;
		fractol->deb_y = -1.2755;
		fractol->imax = 30;
	}
	else if (fractol->frac == 5)
	{
		fractol->x1 = -1.5;
		fractol->x2 = 1.5;
		fractol->y1 = -1.5;
		fractol->y2 = 1.5;
	}
	else
		ft_init_first_values3(fractol);
}

void		ft_init_first_values(t_fractol *fractol)
{
	if (fractol->frac == 0)
	{
		fractol->x1 = -2.1;
		fractol->x2 = 0.6;
		fractol->y1 = -1.2;
		fractol->y2 = 1.2;
	}
	else if (fractol->frac == 1 || fractol->frac == 4)
	{
		fractol->initx = -0.7589;
		fractol->inity = -0.0753;
		fractol->x1 = -1.5;
		fractol->x2 = 1.5;
		fractol->y1 = -1.5;
		fractol->y2 = 1.5;
	}
	else
		ft_init_first_values2(fractol);
}
