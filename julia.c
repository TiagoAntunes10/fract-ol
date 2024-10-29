/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:41 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 22:30:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

static int	julia_render_start(t_mlx *mlx)
{
	long double	z_x;
	long double	z_y;

	mlx->x = 0;
	while (mlx->x < mlx->win_length)
	{
		z_x = (mlx->x * (3.5 / mlx->win_length) + mlx->c_real_beg + 0.2)
			/ mlx->zoom;
		mlx->y = 0;
		while (mlx->y < mlx->win_height)
		{
			z_y = (mlx->y * (3.5 / mlx->win_height) - 0.75 + mlx->c_ima_end)
				/ mlx->zoom;
			check_set(mlx, z_x, z_y);
			mlx->y++;
		}
		mlx->x++;
	}
	if (mlx->window != NULL)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

void	julia(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &julia_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press_julia, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
}
