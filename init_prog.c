/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:46:00 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/02 17:49:10 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_null_image(t_prog *prog)
{
	prog->image->character_image = NULL;
	prog->image->collection_image = NULL;
	prog->image->enemy_image = NULL;
	prog->image->wall_image = NULL;
	prog->image->exit_image = NULL;
	prog->image->background_image = NULL;
}

void	add_null(t_prog *prog)
{
	prog->image = NULL;
	prog->player = NULL;
	prog->exit = NULL;
	prog->mlx = NULL;
	prog->map = NULL;
	prog->fake_map = NULL;
}

void	init_prog(t_prog *prog)
{
	prog->image = malloc(sizeof(t_image));
	prog->mlx = malloc(sizeof(t_mlx));
	prog->player = malloc(sizeof(t_position_player));
	prog->exit = malloc(sizeof(t_position_exit));
	prog->player->count_str = malloc(sizeof(char) * 12);
	prog->player->count_str[0] = '0';
	prog->player->count_str[0] = '\0';
	if (!(prog->image && prog->mlx && prog->player && prog->exit))
	{
		ft_printf("ERROR: program creation failed\n");
		free_all(prog, 1);
		exit(1);
	}
	prog->player->count = 0;
	add_null_image(prog);
}

void	map_manage(t_prog *prog, char *map_name)
{
	int	ctrl;

	ctrl = 1;
	if (map_name_check(map_name) == 0)
	{
		free_all(prog, 1);
		ft_printf("ERROR: The map name is not correct\n");
		exit(1);
	}
	prog->map = map_read(prog->map_name);
	if (!prog->map)
		free_all(prog, 1);
	prog->fake_map = map_read(prog->map_name);
	if (!prog->fake_map)
		free_all(prog, 1);
	count_map_x_y(prog->map, prog);
	prog->count_collect = counter_check_map(prog, 'C');
	find_exit_position(prog);
	find_character_position(prog);
	map_is_true(prog, prog->map_name);
}

void	mlx_manage(t_prog *prog)
{
	prog->mlx->mlx = mlx_init();
	if (!prog->mlx->mlx)
	{
		mlx_destroy_display(prog->mlx->mlx);
		free_all(prog, 1);
	}
	prog->mlx->mlx_window = mlx_new_window(prog->mlx->mlx,
			prog->map_x * 64, prog->map_y * 64, "So_Long");
	if (!prog->mlx->mlx_window)
	{
		mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
		ft_printf("ERROR: The window creation failed\n");
		free_all(prog, 1);
	}
}
