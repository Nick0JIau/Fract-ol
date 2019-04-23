/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:17:41 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/19 15:17:43 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_pixel_put(t_ptr *ptr, int x, int y, int rgb)
{
	int	i;

	i = 0;
	if (x >= 0 && x <= WIDHT && y >= 0 && y <= HEIGHT)
	{
		i = (x * 4) + (y * ptr->size_line);
		ptr->simg[i] = rgb;
		ptr->simg[++i] = rgb >> ptr->b;
		ptr->simg[++i] = rgb >> ptr->b * 2;
	}
}

int		get_color(int color, t_ptr *ptr)
{
	unsigned int	rgb;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (color == ptr->max_i)
		return (0);
	r = color * 5;
	g = color * 2;
	b = color * 10;
	rgb = (r << 16) + (g << 8) + b;
	return (rgb);
}

void	ft_zero_complex(t_ptr *ptr)
{
	ptr->m.z_re = 0;
	ptr->m.z_im = 0;
}

int		ft_check_iteration(t_ptr *ptr)
{
	if (ft_strcmp(ptr->fractol, "Mandelbrot") == 0)
		return (ft_iter_mandelbrot(ptr));
	else if (ft_strcmp(ptr->fractol, "Tricorn") == 0)
		return (ft_iter_tricorn(ptr));
	else if (ft_strcmp(ptr->fractol, "Burningship") == 0)
		return (ft_iter_burningship(ptr));
	else if (ft_strcmp(ptr->fractol, "Celtic") == 0)
		return (ft_iter_celtic(ptr));
	else if (ft_strcmp(ptr->fractol, "Buffalo") == 0)
		return (ft_iter_buffalo(ptr));
	else if (ft_strcmp(ptr->fractol, "Heart") == 0)
		return (ft_iter_heart(ptr));
	else if (ft_strcmp(ptr->fractol, "Mandelbar") == 0)
		return (ft_iter_mandelbar(ptr));
	return (0);
}

void	ft_fractals(t_ptr *ptr)
{
	int x;
	int y;
	int i;

	ptr->m.x_coeff = (ptr->m.re_max - ptr->m.re_min) / WIDHT;
	ptr->m.y_coeff = (ptr->m.im_min - ptr->m.im_max) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = ptr->start - 1;
		ptr->m.c_im = (y * ptr->m.y_coeff) + ptr->m.im_max + ptr->m.movey;
		while (++x < ptr->end)
		{
			ptr->m.c_re = (x * ptr->m.x_coeff) + ptr->m.re_min
			+ ptr->m.movex;
			ft_zero_complex(ptr);
			i = -1;
			while (++i < ptr->max_i)
				if (ft_check_iteration(ptr) == 0)
					break ;
			ft_pixel_put(ptr, x, y, get_color(i, ptr));
		}
	}
}
