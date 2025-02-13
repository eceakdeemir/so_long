#include "so_long.h"

void	init_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->character_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/black-cat/tile000.xpm", &w, &w);
	prog->image->enemy_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/black-cat/tile002.xpm", &w, &w);
	prog->image->wall_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/bricks.xpm", &w, &w);
	prog->image->collection_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/mud.xpm", &w, &w);
	prog->image->exit_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/bricks.xpm", &w, &w);
	prog->image->background_image = mlx_xpm_file_to_image(prog->mlx->mlx, "textures/grass.xpm", &w, &w);
	condition_image(prog->map, prog);
}

void	condition_image(char **map, t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->background_image, j * 64, i * 64);
			if (map[i][j] == '1')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->wall_image, j * 64, i * 64);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->character_image, j * 64, i * 64);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->exit_image, j * 64, i * 64);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->collection_image, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	destroy_image(t_prog *prog)
{
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->wall_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->background_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->exit_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image);
}
