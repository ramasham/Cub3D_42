/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:54:09 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:52:23 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	handle_map_line(t_game *game, char *line, int *i, int *map_started)
{
	*map_started = 1;
	if (store_map_line(game, line, i))
		return (1);
	return (0);
}

static int	handle_invalid_line(t_game *game, char *line, int map_started)
{
	if (map_started && line[0] != '\n' && line[0] != '\0')
	{
		close(game->map.fd);
		get_next_line(-1);
		ft_putstr_fd("Map must be the last\n", 2);
		return (1);
	}
	return (0);
}

static int	handle_line(t_game *game, char *line, int *i, int *map_started)
{
	if (is_map_line(line))
	{
		if (handle_map_line(game, line, i, map_started))
			return (1);
	}
	else if (handle_invalid_line(game, line, *map_started))
		return (1);
	return (0);
}

int	read_map(t_game *game, char *map)
{
	char	*line;
	int		i;
	int		map_started;

	i = 0;
	map_started = 0;
	if (!game->map.map_2d)
		return (1);
	if (open_map_file(game, map))
		return (1);
	line = get_next_line(game->map.fd);
	while (line)
	{
		if (handle_line(game, line, &i, &map_started))
		{
			free(line);
			close(game->map.fd);
			get_next_line(-1);
			return (1);
		}
		free(line);
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
	return (0);
}
