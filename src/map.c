/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:34:46 by frcastil          #+#    #+#             */
/*   Updated: 2023/09/13 11:55:29 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_read_map_2(t_game *game, char *map_name, char *line);

void	ft_free_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->map != NULL)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
	}
	if (game->map_copy != NULL)
	{
		while (game->map_copy[j])
		{
			free(game->map_copy[j]);
			j++;
		}
	}
	free(game->map);
	free(game->map_copy);
}

void	ft_free_part_map(t_game *game, int i)
{
	int	j;

	j = i;
	if (game->map)
	{
		if (game->map[i] != NULL)
			free(game->map[i]);
		while (--i >= 0)
			free(game->map[i]);
		free(game->map);
	}
	if (game->map_copy)
	{
		if (game->map_copy[j] != NULL)
			free(game->map_copy[j]);
		while (--j >= 0)
			free(game->map_copy[j]);
		free(game->map_copy);
	}
}

static int	ft_read_map_2(t_game *game, char *map_name, char *line)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nThe file cant be opened\n"), FALSE);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	game->len_column = ft_strlen(line) - 1;
	while (line)
	{
		game->map[i] = ft_calloc(game->len_column + (line[game->len_column
					- 1] != '\n'), sizeof(char));
		game->map_copy[i] = ft_calloc(game->len_column + (line[game->len_column
					- 1] != '\n'), sizeof(char));
		if (game->map[i] == NULL || game->map_copy[i] == NULL)
			return (free(line), ft_free_part_map(game, i), FALSE);
		ft_strlcpy(game->map[i], line, game->len_column + 1);
		ft_strlcpy(game->map_copy[i++], line, game->len_column + 1);
		free(line);
		line = get_next_line(fd);
	}
	return (game->map[i] = NULL, game->map_copy[i] = NULL, free(line), TRUE);
}

int	ft_read_map(t_game *game, char *map_name)
{
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nThe file cant be opened\n"), FALSE);
	line = get_next_line(fd);
	while (line)
	{
		game->len_row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_calloc(game->len_row + 1, sizeof(char *));
	game->map_copy = ft_calloc(game->len_row + 1, sizeof(char *));
	if (!game->map || !game->map_copy)
		return (free(line), FALSE);
	if (ft_read_map_2(game, map_name, line) == FALSE)
		return (free(line), FALSE);
	return (free(line), TRUE);
}
