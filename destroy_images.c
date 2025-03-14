/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:02:30 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 15:53:03 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_prog *prog)
{
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->wall_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->background_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->exit_image);
}
