#include "so_long.h"


int	key_hook(int keycode, t_mlx_data *vars)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 65307)
        exit(1);
	return (0);
}


int main()
{
    int s = 64;
    t_mlx_data *data;
    char *map[] =
    {"11111111",
        "10000001",
        "10000001",
        "10000001",
        "11111111",
    };
    
    t_image *image;
    data = malloc(sizeof(t_mlx_data) * 1);
    image = malloc(sizeof(t_image) * 1);
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 1920, 1280, "so_long");
    mlx_key_hook(data->mlx_win, key_hook, data);
    image->walls_image = mlx_xpm_file_to_image(data->mlx, "textures/walls.xpm", &s, &s);
    print_walls(map, data->mlx, image->walls_image, data->mlx_win);
    mlx_loop(data->mlx);
}