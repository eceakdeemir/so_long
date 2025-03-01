/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:45:46 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/01 15:59:07 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x + 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x + 1] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			free_all(prog, 2);
		}
		if (map[prog->player->player_y][prog->player->player_x + 1] != 'E')
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			if (map[prog->player->player_y][prog->player->player_x + 1] == 'X')
				free_all(prog, 2);
			map[prog->player->player_y][prog->player->player_x + 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_left(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x - 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x - 1] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			free_all(prog, 2);
		}
		if (map[prog->player->player_y][prog->player->player_x - 1] != 'E')
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			if (map[prog->player->player_y][prog->player->player_x - 1] == 'X')
				free_all(prog, 2);
			map[prog->player->player_y][prog->player->player_x - 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_down(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y + 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y + 1][prog->player->player_x] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			free_all(prog, 2);
		}
		if (map[prog->player->player_y + 1][prog->player->player_x] != 'E')
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			if (map[prog->player->player_y + 1][prog->player->player_x] == 'X')
				free_all(prog, 2);
			map[prog->player->player_y + 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_up(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y - 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y - 1][prog->player->player_x] == 'E'
			&& prog->count_collect == 0)
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			free_all(prog, 2);
		}
		if (map[prog->player->player_y - 1][prog->player->player_x] != 'E')
		{
			prog->player->count++;
			ft_printf("Step Count: %d\n", prog->player->count);
			if (map[prog->player->player_y - 1][prog->player->player_x] == 'X')
				free_all(prog, 2);
			map[prog->player->player_y - 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

int	keycode_actions(int keycode, void *param)
{
	t_prog	*prog_data;

	prog_data = param;
	find_character_position(prog_data);
	if (keycode == 97)
		move_left(prog_data, prog_data->map);
	if (keycode == 119)
		move_up(prog_data, prog_data->map);
	if (keycode == 115)
		move_down(prog_data, prog_data->map);
	if (keycode == 100)
		move_right(prog_data, prog_data->map);
	if (keycode == 65307)
		free_all(prog_data, 2);
	return (0);
}
