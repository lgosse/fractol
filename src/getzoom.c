/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getzoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:02:19 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:49 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_getcolornewton(t_fractol *fractol, double x, double y)
{
	int		color;

	if (x > 0)
	{
		color = 0x00FFFF << (fractol->color % 3);
	}
	else if ((x < -0.3) && (y > 0))
	{
		color = 0xFFFF00 << (fractol->color % 3);
	}
	else
	{
		color = 0xFF00FF << (fractol->color % 3);
	}
	return (color);
}

int		ft_getcolor(t_fractol *fractol, int color)
{
	unsigned int		left;
	unsigned int		right;
	int					i;
	unsigned int		tmp;

	left = 0x800000;
	right = 1;
	i = -1;
	if (fractol->color > 0)
	{
		while (fractol->color && ++i < fractol->color)
		{
			tmp = color;
			color = (color << 1);
			(tmp & left) ? (color |= right) : 0;
		}
	}
	else if (fractol->color < 0)
		while (fractol->color && --i > fractol->color)
		{
			tmp = color;
			color = (color >> 1);
			(tmp & right) ? (color |= left) : 0;
		}
	return (color);
}

void	ft_getmove(t_fractol *fractol, int pm)
{
	if (pm == -1)
		fractol->deb_x -= fractol->mr;
	if (pm == 1)
		fractol->deb_x += fractol->mr;
	if (pm == -2)
		fractol->deb_y += fractol->mr;
	if (pm == 2)
		fractol->deb_y -= fractol->mr;
}

void	ft_getzoom(t_fractol *fractol, int pm)
{
	if (pm == 1 && fractol->zr < 500000)
	{
		fractol->zoom_x *= 1.1;
		fractol->zoom_y *= 1.1;
		fractol->deb_x += ((fractol->x2 - fractol->x1) / 20.05) * fractol->zr;
		fractol->deb_y += ((fractol->y2 - fractol->y1) / 20) * fractol->zr;
		fractol->zr /= 1.1;
		fractol->mr /= 1.1;
	}
	else if (pm == -1)
	{
		fractol->zoom_x /= 1.1;
		fractol->zoom_y /= 1.1;
		fractol->zr *= 1.1;
		fractol->deb_x -= ((fractol->x2 - fractol->x1) / 20.05) * fractol->zr;
		fractol->deb_y -= ((fractol->y2 - fractol->y1) / 20) * fractol->zr;
		fractol->mr *= 1.1;
	}
}
