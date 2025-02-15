/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:00:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 10:04:19 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack_player(t_data *data, t_player *player)
{
	struct timeval	current_time;
	long			elapsed_time;
	bool can_shoot;
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - player->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - player->last_time.tv_usec) / 1000;
	 if (data->enemy->pos_x == player->pos_x || 
                     data->enemy->pos_y == player->pos_y)
			can_shoot = true;
	else
		can_shoot = false;
	if (player->is_laser_player == false && elapsed_time >= FIRE_FRAME && can_shoot == true)
	{
		data->enemy->s_pos_x = data->enemy->pos_x;
		data->enemy->s_pos_y = data->enemy->pos_y;
		player->laser_x = player->pos_x;
		player->laser_y = player->pos_y;
		player->is_laser_player = true;
	}
	++player->fire_frame;
	if (player->is_laser_player == true && player->fire_frame >= FIRE_MVE_FRAME)
	{
		if (player->is_fighting_laser == true && player->laser_dir == LEFT)
		{
			//TODO TEST
			remove_player_laser_left(data, player);
			player->is_laser_player = false;
			player->is_fighting_laser = false;
			player->laser_dir = 0;
			remove_enemy_laser_right(data, data->enemy);


		}
		else if (player->is_fighting_laser == true && player->laser_dir == RIGHT)
		{
			//TODO TEST
			remove_player_laser_right(data, player);
			player->is_laser_player = false;
			player->is_fighting_laser = false;
			player->laser_dir = 0;
			remove_enemy_laser_left(data, data->enemy);


		}
		else if (player->is_fighting_laser == true && player->laser_dir == DOWN)
		{
			//TODO TEST
			remove_player_laser_down(data, player);
			player->is_laser_player = false;
			player->is_fighting_laser = false;
			player->laser_dir = 0;
			remove_enemy_laser_up(data, data->enemy);


		}
		else if (player->is_fighting_laser == true && player->laser_dir == UP)
		{
			//TODO TEST
			remove_player_laser_up(data, player);
			player->is_laser_player = false;
			player->is_fighting_laser = false;
			player->laser_dir = 0;
			remove_enemy_laser_down(data, data->enemy);


		}
		else if (player_laser(data, player) == 1)
		{
			player->is_laser_player = false;
			player->laser_dir = 0;
		}
		gettimeofday(&current_time, NULL);
		player->last_time = current_time;
	}
}

int	player_laser(t_data *data, t_player *player)
{
	player->fire_frame = 0;
	if ((data->enemy->pos_x > player->laser_x
			&& data->enemy->s_pos_y == player->pos_y
			&& player->laser_dir != LEFT) || (player->laser_dir == RIGHT
			&& (size_t)(player->laser_x) < data->nb_row - 2))
		laser_right_player(data, player);
	else if ((data->enemy->pos_x < player->laser_x
			&& data->enemy->s_pos_y == player->pos_y
			&& player->laser_dir != RIGHT) || (player->laser_dir == LEFT
			&& player->laser_x >= 2))
		laser_left_player(data, player);
	else if ((data->enemy->pos_y > player->laser_y
			&& data->enemy->s_pos_x == player->pos_x && player->laser_dir != UP)
		|| (player->laser_dir == DOWN
			&& (size_t)(player->laser_y) < data->nb_line - 2))
		laser_down_player(data, player);
	else if ((data->enemy->pos_y < player->laser_y
			&& data->enemy->s_pos_x == player->pos_x
			&& player->laser_dir != DOWN) || (player->laser_dir == UP
			&& player->laser_y >= 2))
		laser_top_player(data, player);
	else
		return (handle_player_laser(data, player));
	return (0);
}

int	handle_player_laser(t_data *data, t_player *player)
{
	if (player->laser_dir == RIGHT)
		return (remove_player_laser_right(data, player));
	else if (player->laser_dir == LEFT)
		return (remove_player_laser_left(data, player));
	else if (player->laser_dir == DOWN)
		return (remove_player_laser_down(data, player));
	else if (player->laser_dir == UP)
		return (remove_player_laser_up(data, player));
	return (1);
}
