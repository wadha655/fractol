/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:06:56 by wahmed            #+#    #+#             */
/*   Updated: 2023/11/23 18:18:12 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixil(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->sz_line) + (x * (img->bbpix / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	pixel_handel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_val)
		{
			color = map(i, YELLOW, PURPLE, fractol->iteration);
			put_pixil(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	put_pixil(x, y, &fractol->img, BLACK);
}

void	do_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_handel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
