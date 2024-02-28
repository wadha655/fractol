/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:39:03 by wahmed            #+#    #+#             */
/*   Updated: 2023/11/23 10:39:09 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_args(void)
{
	ft_putstr_fd("julia args should be 4\n", 1);
	ft_putstr_fd("./fractol,julia,<value(1)> <value(2)>\n", 1);
}

void	juliarange(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0))
	{
		fractol.name = av[1];
		fractol.julia_x = atoi_db(av[2]);
		fractol.julia_y = atoi_db(av[3]);
		if ((atoi_db(av[2]) <= 2.0 && atoi_db(av[2]) >= -2.0)
			&& (atoi_db(av[3]) <= 2.0 && atoi_db(av[3]) >= -2.0))
		{
			set_fractol(&fractol);
			do_fractol(&fractol);
			mlx_loop(fractol.mlx);
		}
		else
		{
			ft_putstr_fd("Error,range is 2 num between 2 and -2\n", 1);
		}
	}
	julia_args();
}
