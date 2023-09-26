/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:13 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/18 16:01:41 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_images(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_images));
	if (!game->image)
		return ;
	game->image->floor = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->player_up = mlx_texture_to_image(game->mlx,
			game->texture->player_up);
	game->image->player_down = mlx_texture_to_image(game->mlx,
			game->texture->player_down);
	game->image->player_left = mlx_texture_to_image(game->mlx,
			game->texture->player_left);
	game->image->player_right = mlx_texture_to_image(game->mlx,
			game->texture->player_right);
	game->image->enemy_up = mlx_texture_to_image(game->mlx,
			game->texture->enemy_up);
	game->image->enemy_down = mlx_texture_to_image(game->mlx,
			game->texture->enemy_down);
	game->image->enemy_left = mlx_texture_to_image(game->mlx,
			game->texture->enemy_left);
	game->image->enemy_right = mlx_texture_to_image(game->mlx,
			game->texture->enemy_right);
	game->image->exit = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->collectable = mlx_texture_to_image(game->mlx,
			game->texture->collectable);
	ft_delete_texture(game);
}

void	ft_delete_texture(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player_up);
	mlx_delete_texture(game->texture->player_down);
	mlx_delete_texture(game->texture->player_left);
	mlx_delete_texture(game->texture->player_right);
	mlx_delete_texture(game->texture->collectable);
	mlx_delete_texture(game->texture->enemy_up);
	mlx_delete_texture(game->texture->enemy_down);
	mlx_delete_texture(game->texture->enemy_left);
	mlx_delete_texture(game->texture->enemy_right);
}

void	ft_load_textures_2(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->len_row)
	{
		x = 0;
		while (x < game->len_column)
		{
			mlx_image_to_window(game->mlx, game->image->floor, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->image->wall, x * 32, y
					* 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->image->collectable, x * 32,
					y * 32);
			if (game->map[y][x] == 'Z')
				mlx_image_to_window(game->mlx, game->image->enemy_up, x * 32, y
					* 32);
			x++;
		}
		y++;
	}
}

void	ft_load_textures(t_game *game)
{
	int	y;
	int	x;

	ft_load_textures_2(game);
	y = 0;
	while (y < game->len_row)
	{
		x = 0;
		while (x < game->len_column)
		{
			if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->image->floor, x * 32, y
					* 32);
				mlx_image_to_window(game->mlx, game->image->player_down, x * 32,
					y * 32);
			}
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->image->exit, x * 32, y
					* 32);
			x++;
		}
		y++;
	}
}
