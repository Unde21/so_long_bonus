/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:19:50 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:01:39 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (load_img_map(data, data->img) != 0)
		return (-1);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_image_to_win(data, x, y);
			x++;
		}
		y++;
	}
	if (load_img_move(data, data->img) != 0)
	{
		ft_destroy_mlx(data);
		return (-1);
	}
	put_floor_score_board(data);
	return (0);
}

void	put_floor_score_board(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_row)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			i * 64, (data->nb_line) * 64);
		++i;
	}
}

void	put_image_to_win(t_data *data, size_t x, size_t y)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, x * 64, y * 64);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->wall, x * 64, y * 64);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->player, x * 64, y * 64);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->object, x * 64, y * 64);
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->spaceship_close, x * 64, y * 64);
		data->spaceship->pos_x = x;
		data->spaceship->pos_y = y;
	}
}
