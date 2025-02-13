/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:35:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/13 16:38:25 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *data)
{
	data->img->img[0] = "img_file/floor2.xpm";
	data->img->img[1] = "img_file/wall2.xpm";
	data->img->img[2] = "img_file/player.xpm";
	data->img->img[3] = "img_file/object.xpm";
	data->img->img[4] = "img_file/exit_close.xpm";
	data->img->img[5] = "img_file/exit_open.xpm";
	data->img->img[6] = "img_file/player_in_exit.xpm";
	data->img->img[7] = "img_file/player_left_exit.xpm";
	data->img->img[8] = "img_file/player_left.xpm";
	data->img->img[9] = "img_file/player_down.xpm";
	data->img->img[10] = "img_file/player_d_exit.xpm";
	data->img->img[11] = "img_file/player_top.xpm";
	data->img->img[12] = "img_file/player_top_exit.xpm";
	data->img->img[13] = "img_file/exit_fire.xpm";
	data->img->img[14] = "img_file/trail_fire.xpm";
	data->img->img[15] = "img_file/landing_spaceship.xpm";
	data->img->img[16] = "img_file/explosion.xpm";
	init_img_player(data);
}

void	init_move_count(t_data *data)
{
	data->img->move[0] = "img_file/nb_zero.xpm";
	data->img->move[1] = "img_file/nb_one.xpm";
	data->img->move[2] = "img_file/nb_two.xpm";
	data->img->move[3] = "img_file/nb_three.xpm";
	data->img->move[4] = "img_file/nb_four.xpm";
	data->img->move[5] = "img_file/nb_five.xpm";
	data->img->move[6] = "img_file/nb_six.xpm";
	data->img->move[7] = "img_file/nb_seven.xpm";
	data->img->move[8] = "img_file/nb_eight.xpm";
	data->img->move[9] = "img_file/nb_nine.xpm";
}

void	init_img_player(t_data *data)
{
	data->player->img[0] = "img_file/player_death_right.xpm";
	data->player->img[1] = "img_file/player_death_left.xpm";
	data->player->img[2] = "img_file/pl_dead_r_exit.xpm";
	data->player->img[3] = "img_file/pl_dead_l_exit.xpm";
}
