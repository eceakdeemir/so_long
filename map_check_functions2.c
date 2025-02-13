#include "so_long.h"

int	counter_check_map(t_prog *prog, char a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	counter_check_fake_map(t_prog *prog, char a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (prog->fake_map[i])
	{
		j = 0;
		while (prog->fake_map[i][j])
		{
			if (prog->fake_map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_control(t_prog *prog)
{
	char	**a;
	int		i;
	int		j;

	a = prog->map;
	i = 0;
	j = 0;
	while (i < prog->map_y)
	{
		j = 0;
		while (j < prog->map_x)
		{
			if (!(a[i][j] == '1' || a[i][j] == '0' || a[i][j] == 'E'
				|| a[i][j] == 'C' || a[i][j] == 'X' || a[i][j] == 'P'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_is_true(t_prog *prog, char *map_name)
{
	int	player_x;
	int	player_y;

	player_x = prog->player->player_x;
	player_y = prog->player->player_y;
	if (!(map_name_check(map_name) && is_map_line_one(prog)
			&& is_map_rectangular(prog) && map_control(prog)
			&& flood_fill(prog, player_x, player_y)))
	{
		free_all(prog, 1);
		exit(1);
	}
	if (check_number_error(prog) != 1)
	{
		free_all(prog, 1);
		exit(1);
	}
}
