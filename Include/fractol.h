/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:17:34 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/19 18:21:45 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "../libft/ft_printf.h"
# include "set.h"

void			show_options(int argc);
void			handle_errors(t_mlx *mlx);
t_mlx			*create_struct(void);
t_mlx			*open_window(char **argv, int argc);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int colour);
void			push_img(t_mlx *mlx);
void			get_c(char **argv, int argc, t_mlx *mlx);
long double		ft_atod(char *str, int neg);
unsigned int	colours(unsigned int r, unsigned int g, unsigned int b);

#endif
