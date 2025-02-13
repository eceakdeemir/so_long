#include "so_long.h"

int	main(void)
{
	t_prog	*program;

	program = malloc(sizeof(t_prog));
	if (!program)
		return (0);
	add_null(program);
	init_prog(program);
	map_manage(program);
	mlx_manage(program);
	init_image(program);
	condition_image(program->map, program);
	mlx_key_hook(program->mlx->mlx_window, keycode_actions, program);
	mlx_hook(program->mlx->mlx_window, 17, 0, x_button, program);
	mlx_loop(program->mlx->mlx);
}
