/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:08:25 by wahmed            #+#    #+#             */
/*   Updated: 2023/12/19 19:55:40 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("malloc problem");
	exit(1);
}

void	set_data(t_fractol *fractol)
{
	fractol->escape_val = 4.0;
	fractol->iteration = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	key_hook(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_press, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, mouse_press, fractol);
	mlx_hook(fractol->win, 17, 1L << 17, close_press, fractol);
	mlx_hook(fractol->win, 6, 1L << 6, julia_path, fractol);
}

void	set_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
	{
		malloc_error();
	}
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (fractol->win == NULL)
	{
		free(fractol->win);
		malloc_error();
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		free(fractol->mlx);
		malloc_error();
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bbpix, &fractol->img.sz_line,
			&fractol->img.end);
	key_hook(fractol);
	set_data(fractol);
}
