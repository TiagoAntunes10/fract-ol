/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:59 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 21:39:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"
#include "./Include/bonus.h"

static int	mandel_render_start(t_mlx *mlx)
{
	mlx->c_real = mlx->c_real_beg;
	mlx->x = 0;
	while (mlx->x < mlx->win_length)
	{
		mlx->c_real += (-mlx->c_real_beg + mlx->c_real_end) / mlx->zoom
			/ mlx->win_length;
		mlx->c_ima = mlx->c_ima_beg;
		mlx->y = 0;
		while (mlx->y < mlx->win_height)
		{
			check_set(mlx, 0, 0);
			mlx->c_ima -= (-mlx->c_ima_end + mlx->c_ima_beg) / mlx->zoom
				/ mlx->win_height;
			mlx->y++;
		}
		mlx->x++;
	}
	if (mlx->window != NULL)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	return (0);
}

void	mandel_bonus(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &mandel_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press_bonus, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress_bonus, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
}
