/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:29:02 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/13 11:32:21 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_name(char *map_name)
{
	int	i;

	i = ft_strlen(map_name) - 1;
	if (map_name[i] == 'r' && map_name[i - 1] == 'e' && map_name[i - 2] == 'b'
		&& map_name[i - 3] == '.')
		return (TRUE);
	else
		return (FALSE);
}

void	ft_flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->len_row || x < 0 || x >= game->len_column
		|| game->map_copy[y][x] == '1' || game->map_copy[y][x] == '*')
		return ;
	if (game->map_copy[y][x] == 'C')
		game->collec_copy++;
	if (game->map_copy[y][x] == 'E')
		game->exit_copy++;
	game->map_copy[y][x] = '*';
	ft_flood_fill(game, y, x - 1);
	ft_flood_fill(game, y, x + 1);
	ft_flood_fill(game, y - 1, x);
	ft_flood_fill(game, y + 1, x);
}

int	ft_check_path(t_game *game)
{
	ft_start_map(game);
	ft_flood_fill(game, game->y, game->x);
	if (game->collec_copy != game->nb_collec || game->exit_copy != 1)
	{
		return (ft_printf("Error\nThe path is incorrect1\n"), FALSE);
	}
	return (TRUE);
}