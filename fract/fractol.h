/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahmed <wahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:07:51 by wahmed            #+#    #+#             */
/*   Updated: 2023/11/24 12:33:41 by wahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 500
# define WIDTH 500

# define BLACK 0x000000
# define PINK 0xFFC0CB
# define PURPLE 0x800080
# define ORANGE 0xFFA500
# define CYAN 0x00FFFF
# define BROWN 0xA52A2A
# define LIGHT_GRAY 0xD3D3D3
# define GREEN 0x008000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define DARK_GRAY 0x808080
# define WHITE 0xFFFFFF

# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define ESC_KEY 53
# define PLUS 24
# define MINUS 27
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define R 15
# define LOCK 37

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	int		bbpix;
	int		sz_line;
	int		end;
	void	*img;
	char	*addr;

}			t_img;

typedef struct s_fractol
{
	char	*name;
	t_img	img;
	void	*mlx;
	void	*win;
	int		iteration;
	int		visible;
	double	escape_val;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color;
	int		mouse_lock;
}			t_fractol;

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		atoi_db(char *s);
void		toggle_menu(t_fractol *fractol);

void		set_data(t_fractol *fractol);
void		set_fractol(t_fractol *fractol);

int			close_press(t_fractol *fractol);
int			mouse_press(int keycode, int x, int y, t_fractol *fractol);
int			key_press(int keycode, t_fractol *fractol);
int			julia_path(int x, int y, void *param);

double		map(double n, double nmin, double nmax, double omax);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void		put_pixil(int x, int y, t_img *img, int color);
void		do_fractol(t_fractol *fractol);
void		julia_args(void);
void		juliarange(int ac, char **av);
#endif