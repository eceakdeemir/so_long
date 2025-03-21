/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:45:55 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 22:57:40 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_prog *prog)
{
	int	i;

	i = 0;
	while (prog->map[i])
	{
		free(prog->map[i]);
		free(prog->fake_map[i]);
		i++;
	}
	free(prog->map);
	free(prog->fake_map);
}

void	free_all(t_prog *prog, int condition)
{
	if (condition >= 2)
	{
		destroy_image(prog);
		mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
		mlx_destroy_display(prog->mlx->mlx);
		free(prog->mlx->mlx);
	}
	if (condition >= 1)
	{
		free(prog->image);
		free(prog->player->count_str);
		free(prog->player);
		free(prog->exit);
		free(prog->mlx);
		free(prog->map_name);
		if (prog->map)
			free_map(prog);
	}
	free(prog);
	exit(3);
}

int	x_button(void *param)
{
	t_prog	*program;

	program = param;
	free_all(program, 2);
	return (0);
}
