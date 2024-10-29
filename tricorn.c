/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:08:03 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/23 08:56:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/fractol.h"
#include "Include/bonus.h"

static void	check_set_tri(t_mlx *mlx, long double x, long double y)
{
	int			i;
	int			max_ite;
	int			colour;
	long double	r;
	long double	temp;

	i = 0;
	r = 2;
	max_ite = 100;
	while ((x * x + y * y) < r * r && i < max_ite)
	{
		temp = x * x - (y * y) + mlx->c_real;
		y = -2 * x * y + mlx->c_ima;
		x = temp;
		i++;
	}
	colour = colours(i % 9 * 6, i % 8 * 4, i % 9 * 5);
	if (errno == -1)
		handle_errors(mlx);
	my_mlx_pixel_put(mlx, mlx->x, mlx->y, colour);
}

static int	tri_render_start(t_mlx *mlx)
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
			check_set_tri(mlx, 0, 0);
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

void	tricorn(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = open_window(argv, argc);
	mlx_loop_hook(mlx->mlx, &tri_render_start, mlx);
	mlx_mouse_hook(mlx->window, &zoom_press_bonus, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, &keypress_bonus, mlx);
	mlx_hook(mlx->window, ClientMessage, StructureNotifyMask, &xpress, mlx);
	mlx_loop(mlx->mlx);
}
