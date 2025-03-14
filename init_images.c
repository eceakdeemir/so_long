/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:02:25 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 14:28:58 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->character_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bloom1/pp2.xpm", &w, &w);
	prog->image->collection_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/heart1/c1.xpm", &w, &w);
	prog->image->wall_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/Wall/w1.xpm", &w, &w);
	prog->image->exit_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/door/door2.xpm", &w, &w);
	prog->image->background_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"xpm/bg/bg.xpm", &w, &w);
}
