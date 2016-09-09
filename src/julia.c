/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:18:33 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:51 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_fractol *fractol, double tab[10], int imax)
{
	double	nb[5];
	int		i;

	i = 0;
	nb[1] = tab[2];
	nb[2] = tab[3];
	nb[3] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[4] = tab[1] / tab[5] + tab[8] + tab[9];
	while ((nb[3] * nb[3] + nb[4] * nb[4]) < 4 && i < imax)
	{
		nb[0] = nb[3];
		nb[3] = nb[3] * nb[3] - nb[4] * nb[4] + nb[1];
		nb[4] = 2 * nb[4] * nb[0] + nb[2];
		i++;
	}
	if (i != imax)
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, ((i * 0xFFFFFF) / imax)));
}

void	ft_juliap3(t_fractol *fractol, double tab[10], int imax)
{
	double	nb[5];
	int		i;

	i = 0;
	nb[1] = tab[2];
	nb[2] = tab[3];
	nb[3] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[4] = tab[1] / tab[5] + tab[8] + tab[9];
	while ((nb[3] * nb[3] + nb[4] * nb[4]) < 4 && i < imax)
	{
		nb[0] = nb[3];
		nb[3] = nb[3] * nb[3] * nb[3] - 3 * nb[3] * nb[4] * nb[4] + nb[1];
		nb[4] = 3 * nb[0] * nb[0] * nb[4] - nb[4] * nb[4] * nb[4] + nb[2];
		i++;
	}
	if (i != imax)
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, ((i * 0xFD02FF) / imax)));
}
