/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:57:38 by frcastil          #+#    #+#             */
/*   Updated: 2023/12/13 11:51:14 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	ft_textures(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_textures));
	if (!game->texture)
		return (FALSE);
	game->texture->floor = mlx_load_png("./textures/floor.png");
	if (!game->texture->floor)
		return (FALSE);
	game->texture->wall = mlx_load_png("./textures/wall.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->player_up = mlx_load_png
		("./textures/player_up.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->player_down = mlx_load_png
		("./textures/player_down.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->player_left = mlx_load_png
		("./textures/player_left.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->player_right = mlx_load_png
		("./textures/player_right.png");
	return (ft_textures_2(game));
}

int	ft_textures_2(t_game *game)
{
	if (!game->texture->wall)
		return (FALSE);
	game->texture->exit = mlx_load_png("./textures/exit.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->collectable = mlx_load_png
		("./textures/collectable.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->enemy_up = mlx_load_png("./textures/enemy_up.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->enemy_down = mlx_load_png
		("./textures/enemy_down.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->enemy_left = mlx_load_png
		("./textures/enemy_left.png");
	if (!game->texture->wall)
		return (FALSE);
	game->texture->enemy_right = mlx_load_png
		("./textures/enemy_right.png");
	if (!game->texture->wall)
		return (FALSE);
	return (TRUE);
}
