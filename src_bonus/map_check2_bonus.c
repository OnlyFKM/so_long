/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:27:42 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/07 17:03:07 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_start_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->len_row)
	{
		x = 0;
		while (x < game->len_column)
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
			}
			x++;
		}
		y++;
	}
}

int	ft_entry_exit_map(char **map)
{
	int	r;
	int	c;
	int	n_exit;
	int	n_entry;

	r = 0;
	n_exit = 0;
	n_entry = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == 'E')
				n_exit++;
			if (map[r][c] == 'P')
				n_entry++;
			c++;
		}
		r++;
	}
	if (n_entry == 1 && n_exit == 1)
		return (TRUE);
	else
		return (FALSE);
}

int	ft_collectables_map(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	game->nb_collec = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'C')
				game->nb_collec++;
			c++;
		}
		r++;
	}
	game->total_collec = game->nb_collec;
	if (game->nb_collec > 0)
		return (TRUE);
	else
		return (FALSE);
}
