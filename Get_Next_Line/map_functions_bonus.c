/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:46:09 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 13:55:04 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_prog *prog, int x, int y)
{
	if (x < 0 || x >= prog->map_x || y < 0 || y >= prog->map_y)
		return (0);
	if (prog->fake_map[y][x] == '1' ||
		prog->fake_map[y][x] == 'A' || prog->fake_map[y][x] == 'X')
		return (0);
	if (prog->fake_map[y][x] == 'E')
		return (1);
	prog->fake_map[y][x] = 'A';
	flood_fill(prog, x, y - 1);
	flood_fill(prog, x, y + 1);
	flood_fill(prog, x - 1, y);
	flood_fill(prog, x + 1, y);
	return (check_exit(prog));
}

void	count_map_x_y(char **map, t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	prog->map_x = ft_strlen(map[0]) - 1;
	prog->map_y = i;
}

void	map_read_helper(char *map_name, char **map)
{
	int	fd;
	int	i;

	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("ERROR: map can't open\n");
		exit(1);
	}
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
}

char	**map_read(char *map_name)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd <= 0)
		map_read_helper(map_name, map);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
	{
		free(map);
		return (NULL);
	}
	close(fd);
	map_read_helper(map_name, map);
	return (map);
}
