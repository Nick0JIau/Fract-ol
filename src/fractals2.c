/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:39:09 by ntrusevi          #+#    #+#             */
/*   Updated: 2019/01/26 17:39:11 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_iter_mandelbrot(t_ptr *ptr)
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

int		ft_iter_celtic(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = (2.0 * ptr->m.z_re * ptr->m.z_im) + ptr->m.c_im;
	ptr->m.z_re = fabs(z_re_sq - z_im_sq) + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

int		ft_iter_buffalo(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = -2.0 * fabs(ptr->m.z_re * ptr->m.z_im) + ptr->m.c_im;
	ptr->m.z_re = fabs(z_re_sq - z_im_sq) + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

int		ft_iter_heart(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = fabs(ptr->m.z_re) * ptr->m.z_im * 2.0 + ptr->m.c_im;
	ptr->m.z_re = z_re_sq - z_im_sq + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}

int		ft_iter_mandelbar(t_ptr *ptr)
{
	double	z_re_sq;
	double	z_im_sq;

	z_re_sq = ptr->m.z_re * ptr->m.z_re;
	z_im_sq = ptr->m.z_im * ptr->m.z_im;
	ptr->m.z_im = ptr->m.z_re * ptr->m.z_im * -2.0 + ptr->m.c_im;
	ptr->m.z_re = fabs(z_re_sq - z_im_sq) + ptr->m.c_re;
	if (z_im_sq + z_re_sq > 4)
		return (0);
	return (1);
}
