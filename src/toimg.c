/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toimg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 17:58:49 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put_to_image(t_fractol *fractol, int x, int y, int color)
{
	int			i;
	char		*data;

	i = 0;
	data = fractol->img->data + y * fractol->img->sline + x *
		(fractol->img->bpp / 8);
	if (!fractol->img->endian)
	{
		data[i++] = (char)color;
		data[i++] = (char)(color >> 8);
		data[i] = (char)(color >> 16);
	}
	else
	{
		data[i++] = (char)(color >> 16);
		data[i++] = (char)(color >> 8);
		data[i] = (char)color;
	}
}
