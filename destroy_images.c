/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:02:30 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/02/20 15:16:46 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_prog *prog)
{
	destroy_person_image(prog);
	destroy_enemy_image(prog);
	destroy_collect_image(prog);
	//mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	//mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	//mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->wall_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->background_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->exit_image);
}

void	destroy_person_image(t_prog *prog)
{
	//mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image1);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image2);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image3);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image4);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image5);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image6);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image7);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image8);

}
void	destroy_enemy_image(t_prog *prog)
{
	//mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image1);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image2);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image3);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image4);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image5);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image6);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image7);
	mlx_destroy_image(prog->mlx->mlx, prog->image->enemy_image8);
}

void	destroy_collect_image(t_prog *prog)
{
	//mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image1);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image2);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image3);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image4);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image5);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image6);

}