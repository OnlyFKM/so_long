/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:57:51 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/05 15:17:14 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_up_3(t_game *game)
{
	if (game->map[game->y][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		game->map[game->y - 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y - 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_up, game->x * 32,
			(game->y - 1) * 32);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		mlx_image_to_window(game->mlx, game->image->exit, game->x * 32, game->y
			* 32);
		game->map[game->y - 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y - 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_up, game->x * 32,
			(game->y - 1) * 32);
	}
}

void	ft_move_down_3(t_game *game)
{
	if (game->map[game->y][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		game->map[game->y + 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y + 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_down, game->x * 32,
			(game->y + 1) * 32);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		mlx_image_to_window(game->mlx, game->image->exit, game->x * 32, game->y
			* 32);
		game->map[game->y + 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y + 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_down, game->x * 32,
			(game->y + 1) * 32);
	}
}

void	ft_move_left_3(t_game *game)
{
	if (game->map[game->y][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		game->map[game->y][game->x - 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x - 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_left, (game->x - 1)
			* 32, game->y * 32);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		mlx_image_to_window(game->mlx, game->image->exit, game->x * 32, game->y
			* 32);
		game->map[game->y][game->x - 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x - 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_left, (game->x - 1)
			* 32, game->y * 32);
	}
}

void	ft_move_right_3(t_game *game)
{
	if (game->map[game->y][game->x] != 'E')
	{
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		game->map[game->y][game->x + 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x + 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_right, (game->x + 1)
			* 32, game->y * 32);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		mlx_image_to_window(game->mlx, game->image->exit, game->x * 32, game->y
			* 32);
		game->map[game->y][game->x + 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x + 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_right, (game->x + 1)
			* 32, game->y * 32);
	}
}
