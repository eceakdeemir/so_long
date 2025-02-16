#include "so_long.h"

void	move_right(t_prog *prog, char **map)
{
	prog->count_collect = counter_check_map(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x + 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x + 1] == 'E'
			&& prog->count_collect == 0)
		{
			free_all(prog, 2);
			exit(1);
		}
		if (map[prog->player->player_y][prog->player->player_x + 1] != 'E')
		{
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
			free_all(prog, 2);
			exit(1);
		}
		if (map[prog->player->player_y][prog->player->player_x - 1] != 'E')
		{
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
			free_all(prog, 2);
			exit(1);
		}
		if (map[prog->player->player_y + 1][prog->player->player_x] != 'E')
		{
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
			free_all(prog, 2);
			exit(1);
		}
		if (map[prog->player->player_y - 1][prog->player->player_x] != 'E')
		{
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
	{
		free_all(prog_data, 2);
		exit(1);
	}
	condition_image(prog_data->map, prog_data);
	return (1);
}
