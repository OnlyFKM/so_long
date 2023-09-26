/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:44:23 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/12 11:12:18 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_up_2(t_game *game)
{
	if (game->map[game->y - 1][game->x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		if (game->map[game->y][game->x] != 'E')
			game->map[game->y][game->x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->x * 32,
				game->y * 32);
		game->map[game->y - 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y - 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_up, game->x * 32,
			(game->y - 1) * 32);
		game->total_collec--;
	}
	else if (game->map[game->y - 1][game->x] == '0')
	{
		ft_move_up_3(game);
	}
}

void	ft_move_down_2(t_game *game)
{
	if (game->map[game->y + 1][game->x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		if (game->map[game->y][game->x] != 'E')
			game->map[game->y][game->x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->x * 32,
				game->y * 32);
		game->map[game->y + 1][game->x] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32,
			(game->y + 1) * 32);
		mlx_image_to_window(game->mlx, game->image->player_down, game->x * 32,
			(game->y + 1) * 32);
		game->total_collec--;
	}
	else if (game->map[game->y + 1][game->x] == '0')
	{
		ft_move_down_3(game);
	}
}

void	ft_move_left_2(t_game *game)
{
	if (game->map[game->y][game->x - 1] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		if (game->map[game->y][game->x] != 'E')
			game->map[game->y][game->x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->x * 32,
				game->y * 32);
		game->map[game->y][game->x - 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x - 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_left, (game->x - 1)
			* 32, game->y * 32);
		game->total_collec--;
	}
	else if (game->map[game->y][game->x - 1] == '0')
	{
		ft_move_left_3(game);
	}
}

void	ft_move_right_2(t_game *game)
{
	if (game->map[game->y][game->x + 1] == 'C')
	{
		mlx_image_to_window(game->mlx, game->image->floor, game->x * 32, game->y
			* 32);
		if (game->map[game->y][game->x] != 'E')
			game->map[game->y][game->x] = '0';
		else
			mlx_image_to_window(game->mlx, game->image->exit, game->x * 32,
				game->y * 32);
		game->map[game->y][game->x + 1] = 'P';
		mlx_image_to_window(game->mlx, game->image->floor, (game->x + 1) * 32,
			game->y * 32);
		mlx_image_to_window(game->mlx, game->image->player_right, (game->x + 1)
			* 32, game->y * 32);
		game->total_collec--;
	}
	else if (game->map[game->y][game->x + 1] == '0')
	{
		ft_move_right_3(game);
	}
}
