/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:40:35 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/12 11:09:15 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_enemy_location(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->len_row)
	{
		x = 0;
		while (x < game->len_column)
		{
			if (game->map[y][x] == 'Z')
			{
				game->enemy_y = y;
				game->enemy_x = x;
			}
			x++;
		}
		y++;
	}
}

int	ft_number_enemies(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	game->n_enemy = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'Z')
				game->n_enemy++;
			c++;
		}
		r++;
	}
	if (game->n_enemy == 1)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_calculate_direction(t_game *game, int *dx, int *dy)
{
	int	player_x;
	int	player_y;
	int	enemy_x;
	int	enemy_y;

	player_x = game->x;
	player_y = game->y;
	enemy_x = game->enemy_x;
	enemy_y = game->enemy_y;
	*dx = player_x - enemy_x;
	*dy = player_y - enemy_y;
}

void	ft_move_enemy(t_game *game, int dx, int dy)
{
	if (dx > 0)
	{
		ft_move_enemy_right(game);
		game->enemy_x++;
	}
	else if (dx < 0)
	{
		ft_move_enemy_left(game);
		game->enemy_x--;
	}
	if (dy > 0)
	{
		ft_move_enemy_down(game);
		game->enemy_y++;
	}
	else if (dy < 0)
	{
		ft_move_enemy_up(game);
		game->enemy_y--;
	}
}

void	ft_move_enemy_to_player(t_game *game)
{
	int	dx;
	int	dy;

	ft_enemy_location(game);
	ft_calculate_direction(game, &dx, &dy);
	game->enemy_move_timer += game->mlx->delta_time;
	if (game->enemy_move_timer >= 0.4)
	{
		ft_move_enemy(game, dx, dy);
		game->enemy_move_timer = 0;
	}
	if (game->enemy_x == game->x && game->enemy_y == game->y)
	{
		ft_printf("You are dead\n");
		mlx_close_window(game->mlx);
	}
}
