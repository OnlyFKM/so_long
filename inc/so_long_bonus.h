/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:18:40 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/18 15:54:55 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ENTRY_MAP 'P'
# define EXIT_MAP 'E'
# define COLLECTABLE_MAP 'C'
# define FLOOR_MAP '0'
# define WALL_MAP '1'
# define ENEMY 'Z'

# define FALSE 0
# define TRUE 1
# define MOVE 32

typedef struct s_textures
{
	mlx_texture_t		*floor;
	mlx_texture_t		*collectable;
	mlx_texture_t		*wall;
	mlx_texture_t		*player_up;
	mlx_texture_t		*player_down;
	mlx_texture_t		*player_left;
	mlx_texture_t		*player_right;
	mlx_texture_t		*enemy_up;
	mlx_texture_t		*enemy_down;
	mlx_texture_t		*enemy_left;
	mlx_texture_t		*enemy_right;
	mlx_texture_t		*entry;
	mlx_texture_t		*exit;
}						t_textures;

typedef struct s_images
{
	mlx_image_t			*floor;
	mlx_image_t			*collectable;
	mlx_image_t			*wall;
	mlx_image_t			*player_up;
	mlx_image_t			*player_down;
	mlx_image_t			*player_left;
	mlx_image_t			*player_right;
	mlx_image_t			*enemy_up;
	mlx_image_t			*enemy_down;
	mlx_image_t			*enemy_left;
	mlx_image_t			*enemy_right;
	mlx_image_t			*entry;
	mlx_image_t			*exit;
}						t_images;

typedef struct s_game
{
	struct s_textures	*texture;
	struct s_images		*image;
	mlx_t				*mlx;
	char				**map;
	char				**map_copy;
	int					collec_copy;
	int					exit_copy;
	int					total_collec;
	int					nb_collec;
	int					len_row;
	int					len_column;
	int					total_moves;
	int					exit;
	int					y;
	int					x;
	int					enemy_y;
	int					enemy_x;
	int					n_enemy;
	double				enemy_move_timer;
}						t_game;

// main_bonus.c
int						ft_start_game(t_game *game);
int						main(int argc, char *argv[]);
void					ft_counter(t_game *game);

// map_check_bonus.c
int						ft_check_map(t_game *game);

// map_check2_bonus.c
int						ft_collectables_map(t_game *game);
int						ft_entry_exit_map(char **map);
void					ft_start_map(t_game *game);

// map_check3_bonus.c
int						ft_check_path(t_game *game);
void					ft_flood_fill(t_game *game, int y, int x);
int						ft_check_name(char *map_name);

// map_bonus.c
int						ft_read_map(t_game *game, char *map_name);
int						ft_check_name(char *map_name);
void					ft_free_map(t_game *game);
void					ft_size_map(t_game *game);

// visual_bonus.c
void					ft_load_textures(t_game *game);
void					ft_load_textures_2(t_game *game);
void					ft_images(t_game *game);
void					ft_delete_texture(t_game *game);

// visual_2_bonus.c
int						ft_textures(t_game *game);
int						ft_textures_2(t_game *game);

// move_bonus.c
void					key_hook(mlx_key_data_t keydata, void *param);
void					ft_move_up(t_game *game);
void					ft_move_down(t_game *game);
void					ft_move_left(t_game *game);
void					ft_move_right(t_game *game);

// move2_bonus.c
void					ft_move_up_2(t_game *game);
void					ft_move_down_2(t_game *game);
void					ft_move_left_2(t_game *game);
void					ft_move_right_2(t_game *game);

// move3_bonusc
void					ft_move_up_3(t_game *game);
void					ft_move_down_3(t_game *game);
void					ft_move_left_3(t_game *game);
void					ft_move_right_3(t_game *game);

// enemy_bonus.c
void					ft_move_enemy_to_player(t_game *game);
void					ft_move_enemy(t_game *game, int dx, int dy);
void					ft_calculate_direction(t_game *game, int *dx, int *dy);
void					ft_enemy_location(t_game *game);
int						ft_number_enemies(t_game *game);

// move_enemy_bonus.c
void					ft_move_enemy_up(t_game *game);
void					ft_move_enemy_down(t_game *game);
void					ft_move_enemy_left(t_game *game);
void					ft_move_enemy_right(t_game *game);
void					ft_game_loop(void *param);

// move_enemy_bonus2.c
void					ft_move_enemy_up2(t_game *game);
void					ft_move_enemy_down2(t_game *game);
void					ft_move_enemy_left2(t_game *game);
void					ft_move_enemy_right2(t_game *game);

// move_enemy_bonus2.c
void					ft_move_enemy_up3(t_game *game);
void					ft_move_enemy_down3(t_game *game);
void					ft_move_enemy_left3(t_game *game);
void					ft_move_enemy_right3(t_game *game);

#endif