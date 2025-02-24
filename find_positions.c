/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:45:52 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/02/24 14:45:53 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_character_position(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == 'P')
			{
				prog->player->player_x = j;
				prog->player->player_y = i;
			}
			j++;
		}
		i++;
	}
}

void	find_exit_position(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == 'E')
			{
				prog->exit->exit_x = j;
				prog->exit->exit_y = i;
			}
			j++;
		}
		i++;
	}
}
