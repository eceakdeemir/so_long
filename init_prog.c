#include "so_long.h"

static void add_null_image(t_prog *prog)
{
    prog->image->wall_image = NULL;
    prog->image->collection_image = NULL;
    prog->image->character_image = NULL;
    prog->image->enemy_image = NULL;
    prog->image->exit_image = NULL;
    prog->image->background_image = NULL;
}

void add_null(t_prog *prog)
{
    prog->image = NULL;
    prog->player = NULL;
    prog->exit = NULL;
    prog->mlx = NULL;
    prog->map = NULL;
    prog->fake_map = NULL;
}


void init_prog(t_prog *prog)
{
    prog->image = malloc(sizeof(t_image));
    prog->mlx = malloc(sizeof(t_mlx));
    prog->player = malloc(sizeof(t_position_player));
    prog->exit = malloc(sizeof(t_position_exit));
    if(!(prog->image && prog->mlx && prog->player && prog->exit))
    {
        free_all(prog, 1);
        exit(1);
    }
    add_null_image(prog);
}

int map_manage(t_prog *prog)
{
    int ctrl;
    ctrl = 1;
    prog->map = map_read("map.txt");
    if(!prog->map)
        free_all(prog, 1);
    prog->fake_map = map_read("map.txt");
    if(!prog->fake_map)
        free_all(prog, 1);
    count_map_x_y(prog->map, prog);
    prog->count_collect = counter_check_map(prog, 'C');
    find_exit_position(prog);
    find_character_position(prog);
    map_is_true(prog, "map.txt");
}

int mlx_manage(t_prog *prog)
{
    prog->mlx->mlx = mlx_init();
    if(!prog->mlx->mlx)
    {
        mlx_destroy_display(prog->mlx->mlx);
        free_all(prog, 1);
    }
    prog->mlx->mlx_window = mlx_new_window(prog->mlx->mlx, prog->map_x * 64, prog->map_y * 64, "So_Long");
    if(!prog->mlx->mlx_window)
        mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
    
}