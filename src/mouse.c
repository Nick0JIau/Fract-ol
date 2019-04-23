/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:49:01 by ntrusevi          #+#    #+#             */
/*   Updated: 2019/01/26 13:49:02 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			ft_digit(int old, int new)
{
	if (old < new)
		return (1);
	else if (old > new)
		return (-1);
	return (0);
}

int			ft_mouse_julia(int x, int y, t_ptr *ptr)
{
	static int	old_x = 0;
	static int	old_y = 0;
	int			new_x;
	int			new_y;

	new_x = ft_digit(old_x, x);
	new_y = ft_digit(old_y, y);
	ptr->m.c_re += new_x * (x - WIDHT / 2.5) / (WIDHT / 0.011) * 10;
	ptr->m.c_im += new_y * (y - HEIGHT / 2.5) / (HEIGHT / 0.011) * 10;
	old_x = x;
	old_y = y;
	ft_threads(ptr);
	return (0);
}

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		ft_interpol(t_ptr *ptr, double mr, double mi, double inter)
{
	ptr->m.re_min = interpolate(mr, ptr->m.re_min, inter);
	ptr->m.im_min = interpolate(mi, ptr->m.im_min, inter);
	ptr->m.re_max = interpolate(mr, ptr->m.re_max, inter);
	ptr->m.im_max = interpolate(mi, ptr->m.im_max, inter);
}

int			ft_mouse_move(int key, int x, int y, t_ptr *ptr)
{
	double	mousere;
	double	mouseim;
	double	inter;

	y = HEIGHT - y;
	if (key == MOUSE_SCROLL_DOWN)
	{
		inter = 1.0 / 1.1;
		mousere = (double)x / (WIDHT / (ptr->m.re_max - ptr->m.re_min))
		+ ptr->m.re_min;
		mouseim = (double)y / (HEIGHT / (ptr->m.im_max - ptr->m.im_min))
		+ ptr->m.im_min;
		ft_interpol(ptr, mousere, mouseim, inter);
	}
	else if (key == MOUSE_SCROLL_UP)
	{
		inter = 1.0 * 1.1;
		mousere = (double)x / (WIDHT / (ptr->m.re_max - ptr->m.re_min))
		+ ptr->m.re_min;
		mouseim = (double)y / (HEIGHT / (ptr->m.im_max - ptr->m.im_min))
		+ ptr->m.im_min;
		ft_interpol(ptr, mousere, mouseim, inter);
	}
	ft_threads(ptr);
	return (0);
}
