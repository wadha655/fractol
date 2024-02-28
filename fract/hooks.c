/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:07:35 by wahmed            #+#    #+#             */
/*   Updated: 2023/11/25 13:34:52 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_press(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	exit(0);
}

int	mouse_press(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_UP)
	{
		fractol->zoom *= 0.70;
	}
	else if (keycode == MOUSE_DOWN)
	{
		fractol->zoom *= 1.80;
	}
	if ((ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		|| (ft_strncmp(fractol->name, "julia", 5) == 0))
	{
		do_fractol(fractol);
	}
	return (0);
}

static void	key_check(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		close_press(fractol);
	else if (keycode == LEFT)
		fractol->shift_x += 2.0 * fractol->zoom;
	else if (keycode == RIGHT)
		fractol->shift_x -= 2.0 * fractol->zoom;
	else if (keycode == UP)
		fractol->shift_y -= 2.0 * fractol->zoom;
	else if (keycode == DOWN)
		fractol->shift_y += 2.0 * fractol->zoom;
	else if (keycode == PLUS)
		fractol->iteration += 1;
	else if (keycode == MINUS)
		fractol->iteration -= 1;
	else if (keycode == LOCK)
		fractol->mouse_lock = !fractol->mouse_lock;
	else if (keycode == R)
		set_data(fractol);
}

int	key_press(int keycode, t_fractol *fractol)
{
	key_check(keycode, fractol);
	if ((ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		|| (ft_strncmp(fractol->name, "julia", 5) == 0))
	{
		do_fractol(fractol);
	}
	return (0);
}

int	julia_path(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if ((ft_strncmp(fractol->name, "julia", 5) == 0) && !fractol->mouse_lock)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			fractol->julia_x = (map(x, -2, +2, WIDTH) * fractol->zoom)
				+ fractol->shift_x;
			fractol->julia_y = (map(y, -2, +2, HEIGHT) * fractol->zoom)
				+ fractol->shift_y;
			do_fractol(fractol);
		}
	}
	return (0);
}
