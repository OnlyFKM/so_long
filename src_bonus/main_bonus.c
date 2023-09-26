/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:42:21 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/18 16:03:54 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long_bonus");
} */
void	resizable(int32_t width, int32_t height, void *param)
{
	(void)param;
	(void)width;
	(void)height;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

void	init_struct(t_game *g)
{
	g->collec_copy = 0;
	g->exit_copy = 0;
	g->nb_collec = 0;
	g->len_row = 0;
	g->len_column = 0;
	g->total_moves = 0;
	g->exit = 0;
	g->y = 0;
	g->x = 0;
	g->enemy_y = 0;
	g->enemy_x = 0;
	g->n_enemy = 0;
}

int	ft_start_game(t_game *game)
{
	// atexit(ft_leaks);
	game->mlx = mlx_init(game->len_column * 32, game->len_row * 32,
		"so_long_bonus", TRUE);
	if (!game->mlx)
		return (ft_printf("Error\nFailed to initialize MLX\n"), FALSE);
	if (ft_textures(game) != TRUE)
		return (ft_printf("Error\nFailed to load textures\n"), FALSE);
	mlx_resize_hook(game->mlx, &resizable, game);
	ft_images(game);
	ft_load_textures(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop_hook(game->mlx, ft_game_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (TRUE);
}

void	ft_counter(t_game *game)
{
	char	*str;

	str = ft_itoa(game->total_moves);
	mlx_image_to_window(game->mlx, game->image->wall, 0, 0);
	mlx_put_string(game->mlx, str, 5, 5);
	free(str);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (TRUE);
	init_struct(game);
	if (argc != 2)
		return (ft_printf("Error\nWrong number of argues\n"), free(game),
			EXIT_FAILURE);
	if (ft_check_name(argv[1]) == FALSE)
		return (ft_printf("Error\nThe name is wrong\n"), free(game),
			EXIT_FAILURE);
	if (ft_read_map(game, argv[1]) == FALSE)
		return (free(game->texture), free(game->image), free(game), TRUE);
	if (ft_check_map(game) == FALSE)
		return (free(game->texture), free(game->image), ft_free_map(game),
			free(game), EXIT_FAILURE);
	if (ft_check_path(game) == FALSE)
		return (free(game->texture), free(game->image), ft_free_map(game),
			free(game), EXIT_FAILURE);
	if (ft_start_game(game) == FALSE)
		return (free(game->texture), free(game->image), ft_free_map(game),
			free(game), EXIT_FAILURE);
	return (free(game->texture), free(game->image), ft_free_map(game),
		free(game), FALSE);
}
