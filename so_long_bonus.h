/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakdemi <ecakdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:17:04 by ecakdemi          #+#    #+#             */
/*   Updated: 2025/03/21 12:53:22 by ecakdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include "printf/ft_printf.h"

typedef struct s_image
{
	void	*wall_image;
	void	*collection_image;
	void	*collection_image1;
	void	*collection_image2;
	void	*collection_image3;
	void	*collection_image4;
	void	*collection_image5;
	void	*collection_image6;
	void	*character_image;
	void	*character_image1;
	void	*character_image2;
	void	*character_image3;
	void	*character_image4;
	void	*character_image5;
	void	*character_image6;
	void	*character_image7;
	void	*character_image8;
	void	*enemy_image;
	void	*enemy_image1;
	void	*enemy_image2;
	void	*enemy_image3;
	void	*enemy_image4;
	void	*enemy_image5;
	void	*enemy_image6;
	void	*enemy_image7;
	void	*enemy_image8;
	void	*exit_image;
	void	*background_image;	
}	t_image;

typedef struct s_position_exit
{
	int	exit_x;
	int	exit_y;
}	t_position_exit;

typedef struct s_position_player
{
	int		player_x;
	int		player_y;
	int		count;
	char	*count_str;
}	t_position_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}	t_mlx;

typedef struct s_prog
{
	char				**map;
	char				*map_name;
	char				**fake_map;
	int					map_x;
	int					map_y;
	int					count_collect;
	t_mlx				*mlx;
	t_image				*image;
	t_position_player	*player;
	t_position_exit		*exit;
}	t_prog;

void	init_prog(t_prog *prog);
void	map_manage(t_prog *prog, char *map_name);
void	mlx_manage(t_prog *prog);
int		flood_fill(t_prog *prog, int x, int y);
void	count_map_x_y(char **map, t_prog *prog);
char	**map_read(char *map_name, t_prog *prog);
int		keycode_actions(int keycode, void *param);
int		move_up(t_prog *prog, char **map);
int		move_down(t_prog *prog, char **map);
int		move_left(t_prog *prog, char **map);
int		move_right(t_prog *prog, char **map);
void	find_character_position(t_prog *prog);
void	find_exit_position(t_prog *prog);
int		map_name_check(char *map_name);
int		is_map_rectangular(t_prog *prog);
int		is_map_line_one(t_prog *prog);
int		check_number_error(t_prog *prog);
int		check_exit(t_prog *prog);
int		counter_check_map(t_prog *prog, char a);
int		counter_check_fake_map(t_prog *prog, char a);
int		map_control(t_prog *prog);
void	ft_itoa(int n, char *count_str);
void	map_is_true(t_prog *prog, char *map_name);
void	init_image(t_prog *prog);
void	condition_image(char **map, void *mlx, t_prog *prog, void *wn);
void	destroy_image(t_prog *prog);
void	add_null(t_prog *prog);
void	free_all(t_prog *prog, int condition);
void	free_map(t_prog *prog);
int		x_button(void *param);
void	init_person_image(t_prog *prog);
void	init_enemy_image(t_prog *prog);
void	init_collectible_image(t_prog *prog);
void	condition_person_image(t_prog *prog, int count);
void	condition_enemy_image(t_prog *prog, int count);
void	condition_collect_image(t_prog *prog, int count);
int		hook_func(void *param);
void	destroy_person_image(t_prog *prog);
void	destroy_enemy_image(t_prog *prog);
void	destroy_collect_image(t_prog *prog);
void	map_read_helper(char *map_name, char **map, t_prog *prog);
void	condition_image_helper(t_prog *prog, char **map, int i, int j);

#endif