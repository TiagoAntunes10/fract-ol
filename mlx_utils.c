/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:41:43 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 22:28:59 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

t_mlx	*open_window(char **argv, int argc)
{
	t_mlx	*mlx;

	mlx = create_struct();
	get_c(argv, argc, mlx);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		handle_errors(mlx);
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_length,
			mlx->win_height, "Fract-ol");
	if (mlx->window == NULL)
		handle_errors(mlx);
	push_img(mlx);
	return (mlx);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int colour)
{
	int	pixel;

	pixel = (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
	*(unsigned *)(pixel + mlx->addr) = colour;
}

void	push_img(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_length, mlx->win_height);
	if (mlx->img == NULL)
		handle_errors(mlx);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_lenght, &mlx->endian);
}

void	check_set(t_mlx *mlx, long double x, long double y)
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
		y = 2 * x * y + mlx->c_ima;
		x = temp;
		i++;
	}
	colour = colours(i % 9 * 6, i % 8 * 4, i % 9 * 5);
	if (errno == -1)
		handle_errors(mlx);
	my_mlx_pixel_put(mlx, mlx->x, mlx->y, colour);
}
