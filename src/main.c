/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:51:19 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/19 12:51:21 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_key(int key, t_ptr *ptr)
{
	if (key == ESC)
	{
		free(ptr);
		exit(EXIT_SUCCESS);
	}
	if (key == PLUS || key == MINUS)
		ft_iterations(key, ptr);
	if (key == arrows(key))
		ft_move(key, ptr);
	if (key == PAGE_UP || key == PAGE_DOWN)
		ft_color(key, ptr);
	if (key >= 18 && key <= 28 && key != 24 && key != 25 && key != 27)
		ft_set(key, ptr);
	return (0);
}

void	ft_check_fractol(char *str, t_ptr *ptr)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Julia") == 0)
	{
		mlx_hook(ptr->win, 6, 0, ft_mouse_julia, ptr);
		ft_init_julia(ptr);
	}
	else if (ft_strcmp(str, "Tricorn") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Burningship") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Celtic") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Buffalo") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Heart") == 0)
		ft_init_fractol(ptr, str);
	else if (ft_strcmp(str, "Mandelbar") == 0)
		ft_init_fractol(ptr, str);
	else
		ft_usage(ptr);
}

void	ft_init_fractol(t_ptr *ptr, char *str)
{
	ptr->m.movex = 0.0;
	ptr->m.movey = 0.0;
	ptr->m.re_min = -2.5;
	ptr->m.im_min = -1.2;
	ptr->m.im_max = 1.2;
	ptr->m.re_max = 1.1;
	ptr->max_i = 50;
	ptr->b = 8;
	ptr->fractol = str;
	ft_threads(ptr);
}

t_ptr	*ft_init(void)
{
	t_ptr	*ptr;

	if (!(ptr = (t_ptr*)malloc(sizeof(t_ptr))))
		exit(EXIT_FAILURE);
	ptr->mlx = mlx_init();
	ptr->img = mlx_new_image(ptr->mlx, WIDHT, HEIGHT);
	ptr->simg = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel,
		&ptr->size_line, &ptr->endian);
	ptr->win = mlx_new_window(ptr->mlx, WIDHT + MENU, HEIGHT, TITTLE);
	return (ptr);
}

int		main(int ac, char **av)
{
	t_ptr		*ptr;
	char		*str;
	pthread_t	thread[1];

	if (ac == 3)
	{
		str = ft_strjoin("./fractol ", av[2]);
		pthread_create(&thread[0], NULL, (void *)system, str);
	}
	if (ac >= 2 && ac < 4)
	{
		ptr = ft_init();
		ft_check_fractol(av[1], ptr);
		mlx_hook(ptr->win, 2, 0, ft_key, ptr);
		mlx_hook(ptr->win, 17, 0, ft_exit, ptr);
		mlx_hook(ptr->win, 4, 0, ft_mouse_move, ptr);
		mlx_loop(ptr->mlx);
	}
	else
		ft_putendl("Usage: ./fractol [fractol name]");
	pthread_join(thread[0], NULL);
	return (0);
}
