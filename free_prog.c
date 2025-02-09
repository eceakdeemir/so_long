#include "so_long.h"

void free_map(t_prog *prog)
{
    int i;

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


void free_all(t_prog *prog, int condition)
{
    if (condition >= 2)
    {
        destroy_image(prog);
        mlx_clear_window(prog->mlx->mlx, prog->mlx->mlx_window);
        mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
        mlx_destroy_display(prog->mlx->mlx);
        free(prog->mlx->mlx);
    }
    if (condition >= 1)
    {
        free(prog->image);
        free(prog->player);
        free(prog->exit);
        free(prog->mlx);
        if (prog->map)
            free_map(prog);   
    }
    free(prog);
}

int x_button(void *param)
{
    t_prog *program;
    program = param;
    free_all(program, 2);
    exit(1);
}
