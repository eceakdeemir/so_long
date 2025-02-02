#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_image
{
    void *person_image;
    void *enemy_image;
    void *walls_image;
    void *collectable_image;
    void *exit_image;
} t_image;


typedef struct s_mlx_data
{

    void *mlx;
    void *mlx_win;

} t_mlx_data;

typedef struct s_prog_data
{
    char **map;
    t_mlx_data *mlx;
    int map_x;
    int map_y;
    t_image *image;
} t_prog_data;


void print_walls(char **map, void *mlx, void *image, void *mlx_win);


