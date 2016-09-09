/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   druid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:29:05 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:46 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_druid(t_fractol *fractol, double tab[10], int imax)
{
	double	nb[5];
	double	tmp;
	int		i;

	i = 0;
	nb[3] = tab[0] / tab[4] + tab[6] + tab[7];
	nb[4] = tab[1] / tab[5] + tab[8] + tab[9];
	nb[1] = tab[2];
	nb[2] = tab[3];
	while (nb[3] * nb[3] + nb[4] * nb[4] < 4 && i < imax)
	{
		tmp = nb[3] * nb[4];
		if (i % 2)
			nb[3] = fabs(nb[3] * nb[3] - nb[4] * nb[4]) + nb[1];
		else
			nb[3] = nb[3] * nb[3] - nb[4] * nb[4] + nb[1];
		nb[4] = tmp + tmp + nb[2];
		i++;
	}
	if (i != 50)
		ft_pixel_put_to_image(fractol, tab[0], tab[1],
			ft_getcolor(fractol, ((i * 0xFD02FF) / imax)));
}
