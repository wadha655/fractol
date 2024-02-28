/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:08:01 by wahmed            #+#    #+#             */
/*   Updated: 2023/11/23 12:39:33 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 1)
		ft_putstr_fd("Please enter a fractol name\n", 1);
	else if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0))
	{
		fractol.name = av[1];
		set_fractol(&fractol);
		do_fractol(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		if (ac >= 3 && (ft_strncmp(av[1], "mandelbrot", 10) == 0))
			ft_putstr_fd("Error: Please use ./fractol mandelbrot only\n", 1);
		else if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) != 0
				&& ft_strncmp(av[1], "julia", 5) != 0))
		{
			ft_putstr_fd("Error: Incorrect fractol name.\n", 1);
		}
		else
			juliarange(ac, av);
	}
	return (0);
}
