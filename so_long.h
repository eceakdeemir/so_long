#include <stdio.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include "Get_next_line-main/get_next_line.h"
#include  <fcntl.h>

typedef struct  s_image
{
    void *wall_image;
    void *collection_image;
    void *character_image;
    void *enemy_image;
    void *exit_image;
    void *background_image;
    
}   t_image ;

typedef struct s_position_exit
{
    int exit_x;
    int exit_y;
} t_position_exit;

typedef struct s_position_player
{
    int player_x;
    int player_y;
} t_position_player;


typedef struct s_mlx
{
    void *mlx;
    void *mlx_window;
    
} t_mlx;

typedef struct s_prog
{
    char **map;
    char **fake_map;
    int map_x;
    int map_y;
    int count_collect; // collect sayısı
    t_mlx *mlx;
    t_image *image;
    t_position_player *player;
    t_position_exit *exit;
    
} t_prog;

void init_prog(t_prog *prog);
int map_manage(t_prog *prog);
int mlx_manage(t_prog *prog);
int flood_fill(t_prog *prog, int x, int y);
void count_map_x_y(char **map, t_prog *prog);
char **map_read(char *map_name);
int keycode_actions(int keycode, void *param);
void move_up(t_prog *prog, char **map);
void move_down(t_prog *prog, char **map);
void move_left(t_prog *prog, char **map);
void move_right(t_prog *prog, char **map);
void find_character_position(t_prog *prog);
void find_exit_position(t_prog *prog);
int map_name_check(char *map_name);
int is_map_rectangular(t_prog *prog);
int is_map_line_one(t_prog *prog);
int check_number_error(t_prog *prog);
int check_exit(t_prog *prog);
int counter_check_map(t_prog *prog, char a);
int counter_check_fake_map(t_prog *prog, char a);
int map_control(t_prog *prog);
void map_is_true(t_prog *prog, char *map_name);
void init_image(t_prog *prog);
void condition_image(char **map, t_prog *prog);
void destroy_image(t_prog *prog);
void add_null(t_prog *prog);
void free_all(t_prog *prog, int condition);
void free_map(t_prog *prog);
int x_button(void *param);




