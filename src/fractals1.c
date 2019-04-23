/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:22:05 by ntrusevi          #+#    #+#             */
/*   Updated: 2019/01/17 13:22:07 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_iter_burningship(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = -2.0 * fabs(ptr->m.z_re * ptr->m.z_im) + ptr->m.c_im;
	ptr->m.z_re = z_re_sq - z_im_sq + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

int		ft_iter_tricorn(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = -2.0 * ptr->m.z_re * ptr->m.z_im + ptr->m.c_im;
	ptr->m.z_re = z_re_sq - z_im_sq + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

int		ft_iter_julia(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = (2.0 * ptr->m.z_re * ptr->m.z_im) + ptr->m.c_im;
	ptr->m.z_re = z_re_sq - z_im_sq + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

void	ft_julia(t_ptr *ptr)
{
	int x;
	int y;
	int i;

	ptr->m.x_coeff = ptr->m.re_max - ptr->m.re_min;
	ptr->m.y_coeff = ptr->m.im_min - ptr->m.im_max;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDHT)
		{
			ptr->m.z_re = 1.5 * (x - WIDHT / 2.0) / (0.5 * ptr->m.x_coeff *
				WIDHT) + ptr->m.movex;
			ptr->m.z_im = (y - HEIGHT / 2.0) / (0.5 * ptr->m.y_coeff * HEIGHT)
			+ ptr->m.movey;
			i = -1;
			while (++i < ptr->max_i)
				if (ft_iter_julia(ptr) == 0)
					break ;
			ft_pixel_put(ptr, x, y, get_color(i, ptr));
		}
	}
}

void	ft_init_julia(t_ptr *ptr)
{
	ptr->m.c_re = -0.7;
	ptr->m.c_im = 0.27015;
	ptr->m.movex = 0;
	ptr->m.movey = 0;
	ptr->m.re_min = 0.0;
	ptr->m.im_min = 0.0;
	ptr->m.im_max = 1.0;
	ptr->m.re_max = 1.0;
	ptr->max_i = 50;
	ptr->b = 8;
	ptr->fractol = "Julia";
	ft_threads(ptr);
}
