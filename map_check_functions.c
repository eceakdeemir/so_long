/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:46:03 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/02 13:10:37 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name_check(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if (i <= 4)
		return (0);
	if (map_name[i - 4] != '.' || map_name[i - 3] != 'b'
		|| map_name[i - 2] != 'e' || map_name[i - 1] != 'r')
	{
		ft_printf("ERROR: map name is not correct\n");
		return (0);
	}
	return (1);
}

int	is_map_rectangular(t_prog *prog)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
			x++;
		if (prog->map[y][x - 1] == '\n')
			x--;
		if (x != (prog->map_x))
			return (0);
		y++;
	}
	return (1);
}

int	is_map_line_one(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prog->map_y)
	{
		if ((prog->map[i][0] == '1') && (prog->map[i][prog->map_x - 1] == '1'))
			i++;
		else
			return (0);
	}
	while (j < prog->map_x)
	{
		if ((prog->map[0][j] == '1') && (prog->map[prog->map_y - 1][j] == '1'))
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_number_error(t_prog *prog)
{
	int	collect;
	int	exit;
	int	person;

	collect = counter_check_map(prog, 'C');
	exit = counter_check_map(prog, 'E');
	person = counter_check_map(prog, 'P');
	if (collect <= 0)
		return (-1);
	else if (exit != 1 || person != 1)
		return (0);
	return (1);
}

int	check_exit(t_prog *prog)
{
	int	collection_number;

	collection_number = counter_check_fake_map(prog, 'C');
	if (prog->fake_map[prog->exit->exit_y + 1][prog->exit->exit_x] == 'A'
		&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y][prog->exit->exit_x + 1] == 'A'
			&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y - 1][prog->exit->exit_x] == 'A'
			&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y][prog->exit->exit_x - 1] == 'A'
			&& collection_number == 0)
		return (1);
	return (0);
}
