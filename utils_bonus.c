/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:55:36 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 22:14:19 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fractol.h"
#include "Include/bonus.h"

static int	key_move(int keysym, t_mlx *mlx)
{
	if (keysym == KEY_DOWN)
	{
		mlx->c_ima_beg -= 0.1 / mlx->zoom;
		mlx->c_ima_end -= 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_UP)
	{
		mlx->c_ima_beg += 0.1 / mlx->zoom;
		mlx->c_ima_end += 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_LEFT)
	{
		mlx->c_real_beg -= 0.1 / mlx->zoom;
		mlx->c_real_end -= 0.1 / mlx->zoom;
	}
	else if (keysym == KEY_RIGHT)
	{
		mlx->c_real_beg += 0.1 / mlx->zoom;
		mlx->c_real_end += 0.1 / mlx->zoom;
	}
	return (0);
}

int	keypress_bonus(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		handle_errors(mlx);
	else
		key_move(keysym, mlx);
	return (0);
}

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
	mlx->c_real_end = (mlx->c_real_end + move_real);
	mlx->c_ima_beg = (mlx->c_ima_beg + move_ima);
	mlx->c_ima_end = (mlx->c_ima_end + move_ima);
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
	mlx->c_real_end = (mlx->c_real_end - move_real);
	mlx->c_ima_beg = (mlx->c_ima_beg - move_ima);
	mlx->c_ima_end = (mlx->c_ima_end - move_ima);
}

int	zoom_press_bonus(int keysym, int x, int y, t_mlx *mlx)
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
