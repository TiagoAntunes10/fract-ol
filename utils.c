/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:35:27 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 18:22:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/fractol.h"

void	get_c(char **argv, int argc, t_mlx *mlx)
{
	if (argc >= 3)
	{
		if (*argv[2] == '-')
			mlx->c_real = ft_atod(argv[2] + 1, 1);
		else
			mlx->c_real = ft_atod(argv[2], 0);
	}
	if (argc > 3)
	{
		if (*argv[3] == '-')
			mlx->c_ima = ft_atod(argv[3] + 1, 1);
		else
			mlx->c_ima = ft_atod(argv[3], 0);
	}
	if (errno == -1)
	{
		ft_printf("Invalid float\n");
		handle_errors(mlx);
	}
}

static unsigned int	*get_hex(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	*hex;
	int				i;

	hex = malloc(sizeof(unsigned int) * 6);
	i = 0;
	while (i < 2)
	{
		hex[i] = r % 16;
		r /= 16;
		i++;
	}
	while (i < 4)
	{
		hex[i] = g % 16;
		g /= 16;
		i++;
	}
	while (i < 6)
	{
		hex[i] = b % 16;
		b /= 16;
		i++;
	}
	return (hex);
}

static int	ft_power(int base, int exp)
{
	int	result;

	if (exp > 0)
		result = base;
	else if (exp < 0)
		result = 1 / base;
	if (exp == 0)
		return (1);
	else if (exp > 0)
		result *= ft_power(base, exp - 1);
	else if (exp < 0)
		result *= ft_power(base, exp + 1);
	return (result);
}

unsigned int	colours(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	colour;
	int				i;
	int				j;
	unsigned int	*hex;

	if (r > 255 || g > 255 || b > 255)
	{
		errno = -1;
		return (0);
	}
	hex = get_hex(r, g, b);
	i = 5;
	j = 0;
	colour = 0;
	while (i >= 0)
	{
		colour += hex[i] * ft_power(16, j);
		j++;
		i--;
	}
	free(hex);
	return (colour);
}

t_mlx	*create_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->win_height = 600;
	mlx->win_length = 1067;
	mlx->line_lenght = 0;
	mlx->bits_per_pixel = 0;
	mlx->endian = 0;
	mlx->zoom = 1;
	mlx->zoom_level = 0;
	mlx->c_real = 1;
	mlx->c_real_beg = -2.5;
	mlx->c_real_end = 1.5;
	mlx->c_ima = 0;
	mlx->c_ima_beg = 1.7;
	mlx->c_ima_end = -1.7;
	return (mlx);
}
