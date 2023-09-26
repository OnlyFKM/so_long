/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:25:17 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/12 17:45:44 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	ft_closed_map(char **map);
static int	ft_empty_map(t_game *game);
static int	ft_base_map(char **map);
static int	ft_elements_map(char **map);

static int	ft_elements_map(char **map)
{
	int	r;
	int	c;

	r = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (!(map[r][c] == 'P' || map[r][c] == 'E' || map[r][c] == 'C'
					|| map[r][c] == '0' || map[r][c] == '1'
					|| map[r][c] == 'Z'))
				return (FALSE);
			else
				c++;
		}
		r++;
	}
	return (TRUE);
}

static int	ft_base_map(char **map)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_empty_map(t_game *game)
{
	if (!game->map[0])
		return (FALSE);
	else
		return (TRUE);
}

static int	ft_closed_map(char **map)
{
	size_t	line;
	size_t	columns;
	size_t	rows;

	line = 0;
	columns = 0;
	rows = 0;
	while (map[line])
		line++;
	line--;
	while (columns < ft_strlen(map[0]) && map[0][columns] == '1'
		&& map[line][columns] == '1')
		columns++;
	--columns;
	while (rows < line && map[rows][0] == '1' && map[rows][columns] == '1')
		rows++;
	while (columns > 0 && map[line][columns] == '1')
		columns--;
	if (columns == 0 && rows == line)
		return (TRUE);
	else
		return (FALSE);
}

int	ft_check_map(t_game *game)
{
	if (ft_empty_map(game) == FALSE)
		return (ft_printf(("Error\nThe map is empty\n")), 0);
	else if (ft_closed_map(game->map) == FALSE)
		return (ft_printf(("Error\nThe map is not closed\n")), 0);
	else if (ft_base_map(game->map) == FALSE)
		return (ft_printf("Error\nThe map is not rectangle\n"), 0);
	else if (ft_elements_map(game->map) == FALSE)
		return (ft_printf("Error\nThe elements are not correct\n"), 0);
	else if (ft_entry_exit_map(game->map) == FALSE)
		return (ft_printf("Error\nThe entries or exits are not correct\n"), 0);
	else if (ft_collectables_map(game) == FALSE)
		return (ft_printf("Error\nThe collectables are wrong\n"), 0);
	else if (ft_number_enemies(game) == FALSE)
		return (ft_printf("Error\nThe number of enemies are wrong\n"), 0);
	else
		return (1);
}
