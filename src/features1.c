/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:44:03 by ntrusevi          #+#    #+#             */
/*   Updated: 2019/01/24 15:44:05 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_set(int key, t_ptr *ptr)
{
	char	*str;

	str = NULL;
	if (key == ONE)
		str = "Mandelbrot";
	if (key == TWO)
		str = "Julia";
	if (key == THREE)
		str = "Tricorn";
	if (key == FOUR)
		str = "Burningship";
	if (key == FIVE)
		str = "Celtic";
	if (key == SIX)
		str = "Buffalo";
	if (key == SEVEN)
		str = "Heart";
	if (key == EIGHT)
		str = "Mandelbar";
	mlx_clear_window(ptr->mlx, ptr->win);
	ft_check_fractol(str, ptr);
}

int		ft_exit(t_ptr *ptr)
{
	free(ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_usage(t_ptr *ptr)
{
	free(ptr);
	ft_putendl("\nUsage:	./fractol (fractol name)");
	ft_putendl("\nFractal's: Mandelbrot\n	Julia\n 	Tricorn");
	ft_putendl("	Burningship\n	Celtic\n	Buffalo\n	Heart");
	ft_putendl("	Mandelbar");
	exit(EXIT_FAILURE);
}

void	ft_string(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 1000, 0, 16777215, "Usage:");
	mlx_string_put(ptr->mlx, ptr->win, 1000, 40, 16777215, "ESC to exit");
	mlx_string_put(ptr->mlx, ptr->win, 1000, 60, 16777215, "ARROWS to move");
	mlx_string_put(ptr->mlx, ptr->win, 1000, 80, 16777215,
		"+ / - for change iterations");
	mlx_string_put(ptr->mlx, ptr->win, 1000, 100, 16777215,
		"Press 1-8 for change fractol");
	mlx_string_put(ptr->mlx, ptr->win, 1000, 120, 16777215,
		"Press PAGE_UP or PAGE_DOWN for change color");
	mlx_string_put(ptr->mlx, ptr->win, 500, 0, 16777215,
		ptr->fractol);
	mlx_string_put(ptr->mlx, ptr->win, 1000, 150, 16777215, "Fractol's:");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 170, 16777215, "1. Mandelbrot");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 190, 16777215, "2. Julia");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 210, 16777215, "3. Tricorn");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 230, 16777215, "4. Burningship");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 250, 16777215, "5. Celtic");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 270, 16777215, "6. Buffalo");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 290, 16777215, "7. Heart");
	mlx_string_put(ptr->mlx, ptr->win, 1100, 310, 16777215, "8. Mandelbar");
}

void	ft_threads(t_ptr *ptr)
{
	pthread_t	threads[THREADS];
	t_ptr		ptrs[THREADS];
	int			i;
	int			x;

	x = 0;
	i = -1;
	while (++i < THREADS)
	{
		ptrs[i] = *ptr;
		ptrs[i].start = x;
		x += WIDHT / THREADS;
		ptrs[i].end = x;
		pthread_create(&threads[i], NULL, (void *)ft_explorer,
			(void *)&ptrs[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	ft_string(ptr);
}
