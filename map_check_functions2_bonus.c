/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_functions2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:46:06 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 14:03:28 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			{
				ft_printf("ERROR: map is not correct\n");
				return (0);
			}
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
	if (!(is_map_line_one(prog) && is_map_rectangular(prog)
			&& map_control(prog) && check_number_error(prog)))
	{
		ft_printf("ERROR: map failed\n");
		free_all(prog, 1);
	}
	if (!flood_fill(prog, player_x, player_y))
	{
		ft_printf("ERROR: map failed\n");
		free_all(prog, 1);
	}
}

int	hook_func(void *param)
{
	t_prog		*prog;
	static int	i;

	prog = (t_prog *)param;
	if (i != 800)
	{
		condition_person_image(prog, i);
		condition_enemy_image(prog, i);
		condition_collect_image(prog, i);
	}
	else
		i = 0;
	i++;
	condition_image(prog->map, prog->mlx->mlx, prog, prog->mlx->mlx_window);
	return (0);
}
