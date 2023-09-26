/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:21:40 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/13 11:01:25 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_move_enemy_up2(t_game *game)
{
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		(game->enemy_y - 1) * 32);
	mlx_image_to_window(game->mlx, game->image->enemy_up, game->enemy_x * 32,
		(game->enemy_y - 1) * 32);
	if (game->map[game->enemy_y][game->enemy_x] == 'C')
		mlx_image_to_window(game->mlx, game->image->collectable, game->enemy_x
			* 32, game->enemy_y * 32);
	else if (game->map[game->enemy_y][game->enemy_x] != 'E'
		&& game->map[game->enemy_y][game->enemy_x] != 'C')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y - 1][game->enemy_x] = 'Z';
	}
	else
	{
		if (game->map[game->enemy_y][game->enemy_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		game->map[game->enemy_y - 1][game->enemy_x] = 'Z';
	}
}

void	ft_move_enemy_down2(t_game *game)
{
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		(game->enemy_y + 1) * 32);
	mlx_image_to_window(game->mlx, game->image->enemy_down, game->enemy_x * 32,
		(game->enemy_y + 1) * 32);
	if (game->map[game->enemy_y][game->enemy_x] == 'C')
		mlx_image_to_window(game->mlx, game->image->collectable, game->enemy_x
			* 32, game->enemy_y * 32);
	else if (game->map[game->enemy_y][game->enemy_x] != 'E'
		&& game->map[game->enemy_y][game->enemy_x] != 'C')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y + 1][game->enemy_x] = 'Z';
	}
	else
	{
		if (game->map[game->enemy_y][game->enemy_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		game->map[game->enemy_y + 1][game->enemy_x] = 'Z';
	}
}

void	ft_move_enemy_left2(t_game *game)
{
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->floor, (game->enemy_x - 1) * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->enemy_left, (game->enemy_x - 1)
		* 32, game->enemy_y * 32);
	if (game->map[game->enemy_y][game->enemy_x] == 'C')
		mlx_image_to_window(game->mlx, game->image->collectable, game->enemy_x
			* 32, game->enemy_y * 32);
	else if (game->map[game->enemy_y][game->enemy_x] != 'E'
		&& game->map[game->enemy_y][game->enemy_x] != 'C')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x - 1] = 'Z';
	}
	else
	{
		if (game->map[game->enemy_y][game->enemy_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		game->map[game->enemy_y][game->enemy_x - 1] = 'Z';
	}
}

void	ft_move_enemy_right2(t_game *game)
{
	mlx_image_to_window(game->mlx, game->image->floor, game->enemy_x * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->floor, (game->enemy_x + 1) * 32,
		game->enemy_y * 32);
	mlx_image_to_window(game->mlx, game->image->enemy_right, (game->enemy_x + 1)
		* 32, game->enemy_y * 32);
	if (game->map[game->enemy_y][game->enemy_x] == 'C')
		mlx_image_to_window(game->mlx, game->image->collectable, game->enemy_x
			* 32, game->enemy_y * 32);
	else if (game->map[game->enemy_y][game->enemy_x] != 'E'
		&& game->map[game->enemy_y][game->enemy_x] != 'C')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[game->enemy_y][game->enemy_x + 1] = 'Z';
	}
	else
	{
		if (game->map[game->enemy_y][game->enemy_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit, game->enemy_x
				* 32, game->enemy_y * 32);
		else if (game->map[game->enemy_y][game->enemy_x] == 'C')
			mlx_image_to_window(game->mlx, game->image->collectable,
				game->enemy_x * 32, game->enemy_y * 32);
		game->map[game->enemy_y][game->x + 1] = 'Z';
	}
}
