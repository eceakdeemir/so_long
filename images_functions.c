#include "so_long.h"

void print_walls(char **map, void *mlx, void *image, void *mlx_win)
{
    int i;
    int j;
    int dikey;
    int yatay;

    i = 0;
    j = 0;
    yatay = 0;
    dikey = 0;
    while (i < 5)
    {
        j = 0;
        yatay = 0;
        while (j < 8)
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx, mlx_win, image, yatay, dikey);
            j++;
            yatay += 64;
        }
        dikey += 64;
        i++;
    }
}

void print_enemy(char **map, void *enemy_image, void *mlx, int len)
{

}

void print_exit(char **map, void *exit_image, void *mlx, int len)
{

}

void print_person(char **map, void *person_image, void *mlx, int len)
{

}

void print_collect(char **map, void *collect_image, void *mlx, int len)
{

}