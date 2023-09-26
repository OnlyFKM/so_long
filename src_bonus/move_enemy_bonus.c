/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:24:03 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/13 10:35:48 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_move_enemy_up(t_game *game)
{
	if (game->map[game->enemy_y - 1][game->enemy_x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			game->enemy_y * 32);
		if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] != 'E')
			game->map[game->enemy_y][game->enemy_x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			(game->enemy_y - 1) * 32);
		mlx_image_to_window(game->mlx, game->image->enemy_up, game->enemy_x
			* 32, (game->enemy_y - 1) * 32);
	}
	else if (game->map[game->enemy_y - 1][game->enemy_x] == '0'
		|| game->map[game->enemy_y - 1][game->enemy_x] == '1')
	{
		ft_move_enemy_up2(game);
	}
	else if (game->map[game->enemy_y - 1][game->enemy_x] == 'E')
		ft_move_enemy_up3(game);
}

void	ft_move_enemy_down(t_game *game)
{
	if (game->map[game->enemy_y + 1][game->enemy_x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			game->enemy_y * 32);
		if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] != 'E')
			game->map[game->enemy_y][game->enemy_x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		game->map[game->enemy_y + 1][game->enemy_x] = 'C';
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			(game->enemy_y + 1) * 32);
		mlx_image_to_window(game->mlx, game->image->enemy_down, game->enemy_x
			* 32, (game->enemy_y + 1) * 32);
	}
	else if (game->map[game->enemy_y + 1][game->enemy_x] == '0'
		|| game->map[game->enemy_y + 1][game->enemy_x] == '1')
	{
		ft_move_enemy_down2(game);
	}
	else if (game->map[game->enemy_y + 1][game->enemy_x] == 'E')
		ft_move_enemy_down3(game);
}

void	ft_move_enemy_left(t_game *game)
{
	if (game->map[game->enemy_y][game->enemy_x - 1] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			game->enemy_y * 32);
		if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] != 'E')
			game->map[game->enemy_y][game->enemy_x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		game->map[game->enemy_y][game->enemy_x - 1] = 'C';
		mlx_image_to_window(game->mlx, game->image->floor, (game->enemy_x - 1)
			* 32, game->enemy_y * 32);
		mlx_image_to_window(game->mlx, game->image->enemy_left, (game->enemy_x
				- 1) * 32, game->enemy_y * 32);
	}
	else if (game->map[game->enemy_y][game->enemy_x - 1] == '0'
		|| game->map[game->enemy_y][game->enemy_x - 1] == '1')
	{
		ft_move_enemy_left2(game);
	}
	else if (game->map[game->enemy_y][game->enemy_x - 1] == 'E')
		ft_move_enemy_left3(game);
}

void	ft_move_enemy_right(t_game *game)
{
	if (game->map[game->enemy_y][game->enemy_x + 1] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
			game->enemy_y * 32);
		if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] != 'E')
			game->map[game->enemy_y][game->enemy_x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		game->map[game->enemy_y][game->enemy_x + 1] = 'C';
		mlx_image_to_window(game->mlx, game->image->floor, (game->enemy_x + 1)
			* 32, game->enemy_y * 32);
		mlx_image_to_window(game->mlx, game->image->enemy_right, (game->enemy_x
				+ 1) * 32, game->enemy_y * 32);
	}
	else if (game->map[game->enemy_y][game->enemy_x + 1] == '0'
		|| game->map[game->enemy_y][game->enemy_x + 1] == '1')
	{
		ft_move_enemy_right2(game);
	}
	else if (game->map[game->enemy_y][game->enemy_x + 1] == 'E')
		ft_move_enemy_right3(game);
}

void	ft_game_loop(void *param)
{
	t_game	*game;

	game = param;
	ft_move_enemy_to_player(game);
}
