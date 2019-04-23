/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:22 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/19 12:52:23 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDHT		1000
# define HEIGHT		600
# define MENU		500
# define TITTLE		"FRACTOL"
# define THREADS	8

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define ESC				53
# define PLUS				24
# define MINUS 				27
# define UP					126
# define DOWN				125
# define LEFT				123
# define RIGHT				124
# define MOUSE_SCROLL_UP	5
# define MOUSE_SCROLL_DOWN	4
# define MOUSE_KEY_LEFT		1
# define PAGE_UP			116
# define PAGE_DOWN			121
# define ONE				18
# define TWO				19
# define THREE				20
# define FOUR				21
# define FIVE				23
# define SIX				22
# define SEVEN				26
# define EIGHT				28

typedef struct	s_fract
{
	double	movex;
	double	movey;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	c_re;
	double	c_im;
	double	z_im;
	double	z_re;
	double	x_coeff;
	double	y_coeff;
}				t_fract;

typedef struct	s_ptr
{
	int		max_i;
	int		start;
	int		b;
	int		end;
	void	*mlx;
	void	*win;
	void	*img;
	char	*simg;
	char	*fractol;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_fract	m;
}				t_ptr;

void			ft_threads(t_ptr *ptr);
void			ft_set(int key, t_ptr *ptr);
void			ft_check_fractol(char *str, t_ptr *ptr);
void			ft_fractals(t_ptr *ptr);
void			ft_usage(t_ptr *ptr);
void			ft_init_julia(t_ptr *ptr);
void			ft_julia(t_ptr *ptr);
void			ft_zero_complex(t_ptr *ptr);
void			ft_pixel_put(t_ptr *ptr, int x, int y, int rgb);
void			ft_init_fractol(t_ptr *ptr, char *str);
void			ft_iterations(int key, t_ptr *ptr);
void			ft_move(int key, t_ptr *ptr);
void			ft_explorer(t_ptr *ptr);
void			ft_color(int key, t_ptr *ptr);
int				arrows(int key);
int				get_color(int color, t_ptr *ptr);
int				ft_exit(t_ptr *ptr);
int				ft_mouse_julia(int x, int y, t_ptr *ptr);
int				ft_mouse_move(int key, int x, int y, t_ptr *ptr);
int				ft_iter_mandelbrot(t_ptr *ptr);
int				ft_iter_burningship(t_ptr *ptr);
int				ft_iter_tricorn(t_ptr *ptr);
int				ft_iter_celtic(t_ptr *ptr);
int				ft_iter_buffalo(t_ptr *ptr);
int				ft_iter_heart(t_ptr *ptr);
int				ft_iter_mandelbar(t_ptr *ptr);

#endif
