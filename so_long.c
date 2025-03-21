/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:16:59 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 23:12:59 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_prog	*program;

	if (ac != 2)
	{
		ft_printf("ERROR: The number of arguments is not two\n");
		return (1);
	}
	program = malloc(sizeof(t_prog));
	if (!program)
		return (0);
	program->map_name = ft_strdup(av[1]);
	add_null(program);
	init_prog(program);
	map_manage(program, program->map_name);
	mlx_manage(program);
	init_image(program);
	condition_image(program->map, program->mlx->mlx,
		program, program->mlx->mlx_window);
	mlx_key_hook(program->mlx->mlx_window, keycode_actions, program);
	mlx_loop_hook(program->mlx->mlx, hook_func, (void *)program);
	mlx_hook(program->mlx->mlx_window, 17, 1, x_button, program);
	mlx_loop(program->mlx->mlx);
}
