/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:48:55 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/22 18:14:08 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "fractol.h"

# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

int		keypress_bonus(int keysym, t_mlx *mlx);
int		zoom_press_bonus(int keysym, int x, int y, t_mlx *mlx);
void	julia_bonus(char **argv, int argc);
void	mandel_bonus(char **argv, int argc);
void	tricorn(char **argv, int argc);
void	newton(char **argv, int argc);

#endif
