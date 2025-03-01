/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:02:25 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/01 15:37:36 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_prog *prog)
{
	int	w;

	w = 64;
	init_person_image(prog);
	init_enemy_image(prog);
	init_collectible_image(prog);
	prog->image->wall_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/Wall/w1.xpm", &w, &w);
	prog->image->exit_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/door/door2.xpm", &w, &w);
	prog->image->background_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bg/bg.xpm", &w, &w);
}

void	init_person_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->character_image1 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp2.xpm", &w, &w);
	prog->image->character_image2 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp3.xpm", &w, &w);
	prog->image->character_image3 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp4.xpm", &w, &w);
	prog->image->character_image4 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp5.xpm", &w, &w);
	prog->image->character_image5 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp6.xpm", &w, &w);
	prog->image->character_image6 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp7.xpm", &w, &w);
	prog->image->character_image7 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp8.xpm", &w, &w);
	prog->image->character_image8 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp1.xpm", &w, &w);
	prog->image->character_image = prog->image->character_image8;
}

void	init_enemy_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->enemy_image1 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy1.xpm", &w, &w);
	prog->image->enemy_image2 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy2.xpm", &w, &w);
	prog->image->enemy_image3 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy3.xpm", &w, &w);
	prog->image->enemy_image4 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy4.xpm", &w, &w);
	prog->image->enemy_image5 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy5.xpm", &w, &w);
	prog->image->enemy_image6 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy6.xpm", &w, &w);
	prog->image->enemy_image7 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy7.xpm", &w, &w);
	prog->image->enemy_image8 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/icy1/enemy8.xpm", &w, &w);
	prog->image->enemy_image = prog->image->enemy_image8;
}

void	init_collectible_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->collection_image1 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c1.xpm", &w, &w);
	prog->image->collection_image2 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c2.xpm", &w, &w);
	prog->image->collection_image3 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c3.xpm", &w, &w);
	prog->image->collection_image4 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c4.xpm", &w, &w);
	prog->image->collection_image5 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c5.xpm", &w, &w);
	prog->image->collection_image6 = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/kalp1/c6.xpm", &w, &w);
	prog->image->collection_image = prog->image->collection_image6;
}
