/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_image_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:16:56 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 15:52:31 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

int	hook_func(void *param)
{
	t_prog		*prog;

	prog = (t_prog *)param;
	condition_image(prog->map, prog->mlx->mlx, prog, prog->mlx->mlx_window);
	return (0);
}
