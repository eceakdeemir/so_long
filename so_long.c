/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:16:59 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/14 15:54:27 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (ac != 2)
	{
		ft_printf("ERROR: The number of arguments is not two\n");
		return (1);
	}
	prog = malloc(sizeof(t_prog));
	if (!prog)
		return (0);
	prog->map_name = ft_strdup(av[1]);
	add_null(prog);
	init_prog(prog);
	map_manage(prog, prog->map_name);
	mlx_manage(prog);
	init_image(prog);
	condition_image(prog->map, prog->mlx->mlx,
		prog, prog->mlx->mlx_window);
	mlx_key_hook(prog->mlx->mlx_window, keycode_actions, prog);
	mlx_loop_hook(prog->mlx->mlx, hook_func, (void *)prog);
	mlx_hook(prog->mlx->mlx_window, 17, 0, x_button, prog);
	mlx_loop(prog->mlx->mlx);
}
