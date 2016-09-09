/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:10:40 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_burningship(t_fractol *fractol, double tab[10], int imax)
{
	double		nb[5];
	int			i;

	i = 0;
	nb[1] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[2] = tab[1] / tab[5] + tab[8] + tab[9];
	nb[3] = 0;
	nb[4] = 0;
	while (nb[3] * nb[3] + nb[4] * nb[4] < 4 && i < imax)
	{
		nb[0] = nb[3];
		nb[3] = nb[3] * nb[3] - nb[4] * nb[4] + nb[1];
		nb[4] = 2 * FT_ABS(nb[4] * nb[0]) + nb[2];
		i++;
	}
	if (i < imax)
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, (((i * 255) / imax * 4) << 16)));
	else
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, 0xFFBB00));
}

void	ft_mandytree(t_fractol *fractol, double tab[10], int imax)
{
	double	nb[5];
	int		i;

	i = 0;
	nb[3] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[4] = tab[1] / tab[5] + tab[8] + tab[9];
	nb[1] = tab[2];
	nb[2] = tab[3];
	while ((nb[3] * nb[3] + nb[4] * nb[4]) < 4 && i < imax)
	{
		nb[0] = nb[3];
		nb[3] = nb[3] * nb[3] - nb[4] * nb[4] + nb[1];
		if (i % 2)
			nb[4] = 2 * nb[4] * nb[0] + nb[2];
		else
			nb[4] = 2 * fabs(nb[4] * nb[0]) + nb[2];
		i++;
	}
	if (i != 50)
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, ((i * 0xFD02FF) / imax)));
}
