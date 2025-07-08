/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:52 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:56:37 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	assign_color(t_game *game, char *line)
{
	char	*color_str;

	if (ft_strncmp(line, "C", 1) == 0)
	{
		color_str = skip_spaces(line + 1);
		game->ceiling_color = parse_rgb(color_str);
		if (game->ceiling_color == -1)
			return (-1);
		return (1);
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		color_str = skip_spaces(line + 1);
		game->floor_color = parse_rgb(color_str);
		if (game->floor_color == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	assign_identifiers(t_game *game, char *line)
{
	int	result;

	result = assign_texture(game, line);
	if (result == 1)
		return (0);
	result = assign_color(game, line);
	if (result == 1)
		return (0);
	if (result == -1)
		return (-1);
	return (1);
}

static int	check_map_start(t_game *game, char **line)
{
	if (is_map_line(*line))
	{
		if (game->map.id_flag < 6)
			return (cleanup_and_exit(game, line,
					"Error: Missing required identifiers\n"));
		return (0);
	}
	return (cleanup_and_exit(game, line, "Error: Invalid identifier\n"));
}

int	config_identifier(t_game *game, char **line)
{
	int	result;

	*line = get_next_line(game->map.fd);
	while (*line)
	{
		if (skip_empty_lines(*line))
		{
			*line = get_next_line(game->map.fd);
			continue ;
		}
		result = assign_identifiers(game, *line);
		if (result == -1)
			return (cleanup_and_exit(game, line, NULL));
		if (result == 1)
			return (check_map_start(game, line));
		free(*line);
		game->map.id_flag++;
		if (game->map.id_flag == 6)
			return (0);
		*line = get_next_line(game->map.fd);
	}
	return (1);
}
