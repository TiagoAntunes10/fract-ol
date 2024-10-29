/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:50:01 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/19 18:18:07 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

void	handle_errors(t_mlx *mlx)
{
	if (mlx != NULL)
	{
		if (mlx->img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->window != NULL)
			mlx_destroy_window(mlx->mlx, mlx->window);
		if (mlx->mlx != NULL)
		{
			mlx_destroy_display(mlx->mlx);
			free(mlx->mlx);
		}
		free(mlx);
	}
	exit(1);
}

void	show_options(int argc)
{
	if (argc < 2)
	{
		ft_printf("Select one option:\n");
		ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
		ft_printf("You can also modify the Julia set with up to 2 floats\n");
		exit(1);
	}
	else if (argc > 4)
	{
		ft_printf("Too many arguments\n\n");
		ft_printf("Select one option:\n");
		ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
		ft_printf("You can also modify the Julia set with up to 2 floats\n");
		exit(1);
	}
	ft_printf("Invalid option\n\n");
	ft_printf("Select one option:\n");
	ft_printf("1 - julia or -j\n2 - mandelbrot or -m\n");
	ft_printf("You can also modify the Julia set with up to 2 floats\n");
	exit(1);
}
