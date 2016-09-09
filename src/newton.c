/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:23:31 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:52 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_newton(t_fractol *fractol, double tab[10], int imax)
{
	double	nb[5];
	int		i;
	double	xx;
	double	yy;
	double	d;

	i = 0;
	nb[3] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[4] = tab[1] / tab[5] + tab[8] + tab[9];
	while (i < imax)
	{
		xx = nb[3] * nb[3];
		yy = nb[4] * nb[4];
		d = 3 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
		d = d == 0 ? 0.000001 : d;
		nb[0] = nb[3];
		nb[3] = (2.0 / 3.0) * nb[3] + (xx - yy) / d;
		nb[4] = (2.0 / 3.0) * nb[4] - 2.0 * nb[0] * nb[4] / d;
		i++;
	}
	ft_pixel_put_to_image(fractol, tab[0], tab[1],
		ft_getcolornewton(fractol, nb[3], nb[4]));
}
