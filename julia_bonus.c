/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:41 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/23 08:52:01 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"
#include "./Include/bonus.h"

static void	move_in(t_mlx *mlx, int x, int y)
{
	long double	step_real;
	long double	step_ima;
	long double	move_real;
	long double	move_ima;

	step_real = (mlx->c_real_end - mlx->c_real_beg) / mlx->win_length;
	step_ima = (mlx->c_ima_beg - mlx->c_ima_end) / mlx->win_height;
	move_real = (x - mlx->win_length / 2) * step_real * 0.4 / mlx->zoom;
	move_ima = (mlx->win_height / 2 - y) * step_ima * 0.4 / mlx->zoom;
	mlx->c_real_beg = (mlx->c_real_beg + move_real);
	mlx->c_ima_end = (mlx->c_ima_end - move_ima);
}

static void	move_out(t_mlx *mlx, int x, int y)
{
	long double	step_real;
	long double	step_ima;
	long double	move_real;
	long double	move_ima;

	step_real = (mlx->c_real_end - mlx->c_real_beg) / mlx->win_length;
	step_ima = (mlx->c_ima_beg - mlx->c_ima_end) / mlx->win_height;
	move_real = (x - mlx->win_length / 2) * step_real * 0.1 / mlx->zoom;
	move_ima = (mlx->win_height / 2 - y) * step_ima * 0.1 / mlx->zoom;
	mlx->c_real_beg = (mlx->c_real_beg - move_real);
	mlx->c_ima_end = (mlx->c_ima_end + move_ima);
}

int	zoom_press_bonus_julia(int keysym, int x, int y, t_mlx *mlx)
{
	if (keysym == 4)
	{
		mlx->zoom *= 1.1;
		move_in(mlx, x, y);
		mlx->zoom_level++;
	}
	else if (keysym == 5 && mlx->zoom_level > 0)
	{
		mlx->zoom /= 1.1;
		move_out(mlx, x, y);
		mlx->zoom_level--;
	}
	return (0);
}

static int	julia_render_start(t_mlx *mlx)
{
	long double	z_x;
	long double	z_y;

	mlx->x = 0;
	while (mlx->x < mlx->win_length)
	{
		z_x = (mlx->x * (3.5 / mlx->win_length)) / mlx->zoom
			+ mlx->c_real_beg;
		mlx->y = 0;
		while (mlx->y < mlx->win_height)
		{
			z_y = (mlx->y * (3.5 / mlx->win_height)) / mlx->zoom
				+ mlx->c_ima_end;
			check_set(mlx, z_x, z_y);
			mlx->y++;
		}
		mlx->x++;
	}
	if (mlx->window != NULL)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

void	julia_bonus(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &julia_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press_bonus_julia, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress_bonus, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
}
