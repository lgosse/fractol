/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 12:16:02 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/26 17:28:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_check_parse(char *arg, t_fractol *fractol)
{
	if (ft_strequ("mandelbrot", arg) && (fractol->frac = 0) + 1)
		return (1);
	else if (ft_strequ("julia", arg) && (fractol->frac = 1))
		return (1);
	else if (ft_strequ("burningship", arg) && (fractol->frac = 2))
		return (1);
	else if (ft_strequ("mandelbrotp3", arg) && (fractol->frac = 3))
		return (1);
	else if (ft_strequ("juliap3", arg) && (fractol->frac = 4))
		return (1);
	else if (ft_strequ("newton", arg) && (fractol->frac = 5))
		return (1);
	else if (ft_strequ("galaxia", arg) && (fractol->frac = 6))
		return (1);
	else if (ft_strequ("mandelbrotpdclr", arg) && (fractol->frac = 7))
		return (1);
	else if (ft_strequ("birdofprey", arg) && (fractol->frac = 8))
		return (1);
	else if (ft_strequ("druid", arg) && (fractol->frac = 9))
		return (1);
	else if (ft_strequ("mandytree", arg) && (fractol->frac = 10))
		return (1);
	return (0);
}
