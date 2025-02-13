#include "so_long.h"

int	flood_fill(t_prog *prog, int x, int y)
{
	if (x < 0 || x >= prog->map_x || y < 0 || y >= prog->map_y)
		return (0);
	if (prog->fake_map[y][x] == '1' || prog->fake_map[y][x] == 'A')
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

char	**map_read(char *map_name)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (!fd)
		return (NULL);
	while (line = get_next_line(fd))
	{
		free(line);
		i++;
	}
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
	{
		free(map);
		return (NULL);
	}
	map[i] = NULL;
	close(fd);
	fd = open(map_name, O_RDONLY);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}
