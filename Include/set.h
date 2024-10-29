/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:23 by tialbert          #+#    #+#             */
/*   Updated: 2024/05/23 08:37:28 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H

# define SET_H

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	float		win_height;
	float		win_length;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			x;
	int			y;
	long double	c_real;
	long double	c_real_beg;
	long double	c_real_end;
	long double	c_ima_beg;
	long double	c_ima_end;
	long double	c_ima;
	float		zoom;
	int			zoom_level;
}				t_mlx;

int		mandel_render_hook(t_mlx *mlx);
void	check_set(t_mlx *mlx, long double x, long double y);
void	mandel(char **argv, int argc);
void	julia(char **argv, int argc);
int		zoom_press(int keysym, int x, int y, t_mlx *mlx);
int		zoom_press_julia(int keysym, int x, int y, t_mlx *mlx);
int		xpress(t_mlx *mlx);
int		keypress(int keysym, t_mlx *mlx);

#endif
