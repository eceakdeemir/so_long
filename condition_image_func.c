/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_image_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:16:56 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/02 17:52:11 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	condition_person_image(t_prog *prog, int count)
{
	if (prog->image->character_image == NULL || count == 799)
		prog->image->character_image = prog->image->character_image8;
	if (count == 100)
		prog->image->character_image = prog->image->character_image1;
	if (count == 200)
		prog->image->character_image = prog->image->character_image2;
	if (count == 300)
		prog->image->character_image = prog->image->character_image3;
	if (count == 400)
		prog->image->character_image = prog->image->character_image4;
	if (count == 500)
		prog->image->character_image = prog->image->character_image5;
	if (count == 600)
		prog->image->character_image = prog->image->character_image6;
	if (count == 700)
		prog->image->character_image = prog->image->character_image7;
}

void	condition_enemy_image(t_prog *prog, int count)
{
	if (prog->image->enemy_image == NULL || count == 799)
		prog->image->enemy_image = prog->image->enemy_image8;
	if (count == 100)
		prog->image->enemy_image = prog->image->enemy_image1;
	if (count == 200)
		prog->image->enemy_image = prog->image->enemy_image2;
	if (count == 300)
		prog->image->enemy_image = prog->image->enemy_image3;
	if (count == 400)
		prog->image->enemy_image = prog->image->enemy_image4;
	if (count == 500)
		prog->image->enemy_image = prog->image->enemy_image5;
	if (count == 600)
		prog->image->enemy_image = prog->image->enemy_image6;
	if (count == 700)
		prog->image->enemy_image = prog->image->enemy_image7;
}

void	condition_collect_image(t_prog *prog, int count)
{
	if (prog->image->collection_image == NULL || count == 799)
		prog->image->collection_image = prog->image->collection_image6;
	if (count == 100)
		prog->image->collection_image = prog->image->collection_image1;
	if (count == 200)
		prog->image->collection_image = prog->image->collection_image2;
	if (count == 300)
		prog->image->collection_image = prog->image->collection_image3;
	if (count == 400)
		prog->image->collection_image = prog->image->collection_image4;
	if (count == 500)
		prog->image->collection_image = prog->image->collection_image5;
}

void	condition_image(char **map, void *mlx, t_prog *prog, void *wn)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			condition_image_helper(prog, map, i, j);
			mlx_string_put(prog->mlx->mlx, prog->mlx->mlx_window, 0, 10,
				328965, "STEP COUNT: ");
			mlx_string_put(prog->mlx->mlx, prog->mlx->mlx_window, 75, 10,
				328965, prog->player->count_str);
			j++;
		}
		i++;
	}
}

void	condition_image_helper(t_prog *prog, char **map, int i, int j)
{
	void	*mlx;
	void	*window;

	mlx = prog->mlx->mlx;
	window = prog->mlx->mlx_window;
	if (map[i][j] == '0')
		mlx_put_image_to_window(mlx, window,
			prog->image->background_image, j * 64, i * 64);
	if (map[i][j] == '1')
		mlx_put_image_to_window(mlx, window,
			prog->image->wall_image, j * 64, i * 64);
	if (map[i][j] == 'P')
		mlx_put_image_to_window(mlx, window,
			prog->image->character_image, j * 64, i * 64);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(mlx, window,
			prog->image->exit_image, j * 64, i * 64);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(mlx, window,
			prog->image->collection_image, j * 64, i * 64);
	if (map[i][j] == 'X')
		mlx_put_image_to_window(mlx, window,
			prog->image->enemy_image, j * 64, i * 64);
}
