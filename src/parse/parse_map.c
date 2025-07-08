/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:12:28 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 11:58:11 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	read_and_validate(t_game *game, char *map)
{
	if (read_map(game, map))
	{
		free_identifiers(game);
		free_map_2d(game);
		return (1);
	}
	if (is_valid_cell(game->map.map_2d))
	{
		free_identifiers(game);
		free_map_2d(game);
		return (1);
	}
	if (validate_player(game) || validate_map(game))
		return (1);
	return (0);
}

int	parsing(t_game *game, char *map)
{
	static char	*line = NULL;

	if (open_map_file(game, map))
		return (1);
	if (config_identifier(game, &line))
	{
		free_identifiers(game);
		close(game->map.fd);
		return (1);
	}
	get_map_size(game, &line);
	close(game->map.fd);
	if (allocate_2d_map(game))
	{
		free_identifiers(game);
		return (1);
	}
	if (read_and_validate(game, map))
	{
		return (1);
	}
	return (0);
}
