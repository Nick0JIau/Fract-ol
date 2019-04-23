/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:39:16 by ntrusevi          #+#    #+#             */
/*   Updated: 2019/01/21 16:39:18 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		arrows(int key)
{
	if (key == UP)
		return (key);
	else if (key == DOWN)
		return (key);
	else if (key == LEFT)
		return (key);
	else if (key == RIGHT)
		return (key);
	return (0);
}

void	ft_move(int key, t_ptr *ptr)
{
	if (key == UP || key == DOWN)
	{
		key == UP ? (ptr->m.movey += 0.0001) : (ptr->m.movey -= 0.0001);
		ft_threads(ptr);
	}
	if (key == LEFT || key == RIGHT)
	{
		key == LEFT ? (ptr->m.movex -= 0.0001) : (ptr->m.movex += 0.0001);
		ft_threads(ptr);
	}
}

void	ft_iterations(int key, t_ptr *ptr)
{
	if (key == PLUS)
	{
		ptr->max_i += 10;
		ft_threads(ptr);
	}
	if (key == MINUS && ptr->max_i >= 50)
	{
		ptr->max_i -= 10;
		ft_threads(ptr);
	}
}

void	ft_explorer(t_ptr *ptr)
{
	if (ft_strcmp(ptr->fractol, "Julia") == 0)
		ft_julia(ptr);
	else
		ft_fractals(ptr);
}

void	ft_color(int key, t_ptr *ptr)
{
	key == PAGE_UP ? (ptr->b += 1) : (ptr->b -= 1);
	ft_threads(ptr);
}
