/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:01:13 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/12 11:05:47 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_move_up(t_game *g)
{
	ft_move_up_2(g);
	if (g->map[g->y - 1][g->x] == 'E' && g->total_collec != 0)
	{
		g->map[g->y][g->x] = '0';
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, (g->y - 1)
			* 32);
		mlx_image_to_window(g->mlx, g->image->exit, g->x * 32, (g->y - 1) * 32);
		mlx_image_to_window(g->mlx, g->image->player_up, g->x * 32, (g->y - 1)
			* 32);
	}
	if (g->map[g->y - 1][g->x] != '1')
	{
		g->y--;
		g->total_moves++;
		ft_counter(g);
	}
	if (g->map[g->y][g->x] == 'E' && g->total_collec == 0)
	{
		ft_printf("You have won the game\n");
		mlx_close_window(g->mlx);
	}
}

void	ft_move_down(t_game *g)
{
	ft_move_down_2(g);
	if (g->map[g->y + 1][g->x] == 'E' && g->total_collec != 0)
	{
		g->map[g->y][g->x] = '0';
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, (g->y + 1)
			* 32);
		mlx_image_to_window(g->mlx, g->image->exit, g->x * 32, (g->y + 1) * 32);
		mlx_image_to_window(g->mlx, g->image->player_down, g->x * 32, (g->y + 1)
			* 32);
	}
	if (g->map[g->y + 1][g->x] != '1')
	{
		g->y++;
		g->total_moves++;
		ft_counter(g);
	}
	if (g->map[g->y][g->x] == 'E' && g->total_collec == 0)
	{
		ft_printf("You have won the game\n");
		mlx_close_window(g->mlx);
	}
}

void	ft_move_left(t_game *g)
{
	ft_move_left_2(g);
	if (g->map[g->y][g->x - 1] == 'E' && g->total_collec != 0)
	{
		if (g->map[g->y][g->x] != 'E')
			g->map[g->y][g->x] = '0';
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->floor, (g->x - 1) * 32, g->y
			* 32);
		mlx_image_to_window(g->mlx, g->image->exit, (g->x - 1) * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->player_left, (g->x - 1) * 32, g->y
			* 32);
	}
	if (g->map[g->y][g->x - 1] != '1')
	{
		g->x--;
		g->total_moves++;
		ft_counter(g);
	}
	if (g->map[g->y][g->x] == 'E' && g->total_collec == 0)
	{
		ft_printf("You have won the game\n");
		mlx_close_window(g->mlx);
	}
}

void	ft_move_right(t_game *g)
{
	ft_move_right_2(g);
	if (g->map[g->y][g->x + 1] == 'E' && g->total_collec != 0)
	{
		if (g->map[g->y][g->x] != 'E')
			g->map[g->y][g->x] = '0';
		mlx_image_to_window(g->mlx, g->image->floor, g->x * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->floor, (g->x + 1) * 32, g->y
			* 32);
		mlx_image_to_window(g->mlx, g->image->exit, (g->x + 1) * 32, g->y * 32);
		mlx_image_to_window(g->mlx, g->image->player_right, (g->x + 1) * 32,
			g->y * 32);
	}
	if (g->map[g->y][g->x + 1] != '1')
	{
		g->x++;
		g->total_moves++;
		ft_counter(g);
	}
	if (g->map[g->y][g->x] == 'E' && g->total_collec == 0)
	{
		ft_printf("You have won the game\n");
		mlx_close_window(g->mlx);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		ft_move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		ft_move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		ft_move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		ft_move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}
