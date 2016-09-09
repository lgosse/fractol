/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:53:39 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/27 11:14:58 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_exit_give_usage(t_fractol *fractol)
{
	ft_free_parse(fractol->parse);
	free(fractol);
	ft_printf("usage : ./fractol [fractal-type]\n");
	ft_printf("fractal-types : \n%s%s%s%s%s%s%s%s%s%s%s%@", "julia\n",
	"mandelbrot\n", "mandelbrotp3\n", "juliap3\n", "mandelbrotpdclr\n",
	"galaxia\n", "druid\n", "newton\n", "birdofprey\n", "mandytree\n",
	"burningship\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img->img);
	free(fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol);
	exit(EXIT_SUCCESS);
}
