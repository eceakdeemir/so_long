/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_image_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:16:56 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/02/20 16:42:42 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int hook_func(void *param)
{
	t_prog *prog;
	prog = (t_prog*)param;
	static int i;

	if (i != 800)
	{
		condition_person_image(prog, i);
		condition_enemy_image(prog, i);
		condition_collect_image(prog, i);
	}
	else
		i = 0;
	i++;
	condition_image(prog->map, prog);
	return (0);
}

void condition_person_image(t_prog *prog, int count)
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
void condition_enemy_image(t_prog *prog, int count)
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

void condition_collect_image(t_prog *prog, int count)
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

void	condition_image(char **map, t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	// mlx_clear_window(prog->mlx->mlx, prog->mlx->mlx_window);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->background_image, j * 64, i * 64);
			if (map[i][j] == '1')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->wall_image, j * 64, i * 64);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->character_image, j * 64, i * 64);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->exit_image, j * 64, i * 64);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->collection_image, j * 64, i * 64);
			if (map[i][j] == 'X')
				mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window, prog->image->enemy_image, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
