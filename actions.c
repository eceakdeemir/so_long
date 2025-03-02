/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:45:46 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/02 17:51:09 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x + 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x + 1] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("YOU WON THE GAME!\n");
			free_all(prog, 2);
			return (1);
		}
		if (map[prog->player->player_y][prog->player->player_x + 1] != 'E')
		{
			prog->player->count++;
			if (map[prog->player->player_y][prog->player->player_x + 1] == 'X')
			{
				ft_printf("YOU LOSE!\n");
				free_all(prog, 2);
			}
			map[prog->player->player_y][prog->player->player_x + 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
			return (1);
		}
	}
	return (0);
}

int	move_left(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x - 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x - 1] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("YOU WON THE GAME!\n");
			free_all(prog, 2);
			return (1);
		}
		if (map[prog->player->player_y][prog->player->player_x - 1] != 'E')
		{
			prog->player->count++;
			if (map[prog->player->player_y][prog->player->player_x - 1] == 'X')
			{
				ft_printf("YOU LOSE!\n");
				free_all(prog, 2);
			}
			map[prog->player->player_y][prog->player->player_x - 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
			return (1);
		}
	}
	return (0);
}

int	move_down(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y + 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y + 1][prog->player->player_x] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("YOU WON THE GAME!\n");
			free_all(prog, 2);
			return (1);
		}
		if (map[prog->player->player_y + 1][prog->player->player_x] != 'E')
		{
			prog->player->count++;
			if (map[prog->player->player_y + 1][prog->player->player_x] == 'X')
			{
				ft_printf("YOU LOSE!\n");
				free_all(prog, 2);
			}
			map[prog->player->player_y + 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
			return (1);
		}
	}
	return (0);
}

int	move_up(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y - 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y - 1][prog->player->player_x] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("YOU WON THE GAME!\n");
			free_all(prog, 2);
			return (1);
		}
		if (map[prog->player->player_y - 1][prog->player->player_x] != 'E')
		{
			prog->player->count++;
			if (map[prog->player->player_y - 1][prog->player->player_x] == 'X')
			{
				ft_printf("YOU LOSE!\n");
				free_all(prog, 2);
			}
			map[prog->player->player_y - 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
			return (1);
		}
	}
	return (0);
}

int	keycode_actions(int keycode, void *param)
{
	t_prog	*prog_data;
	int		flag;

	flag = 0;
	prog_data = param;
	find_character_position(prog_data);
	if (keycode == 97)
		flag += move_left(prog_data, prog_data->map);
	else if (keycode == 119)
		flag += move_up(prog_data, prog_data->map);
	else if (keycode == 115)
		flag += move_down(prog_data, prog_data->map);
	else if (keycode == 100)
		flag += move_right(prog_data, prog_data->map);
	if (flag == 1)
		ft_itoa(prog_data->player->count, prog_data->player->count_str);
	if (keycode == 65307)
		free_all(prog_data, 2);
	return (0);
}
