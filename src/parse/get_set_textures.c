/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:04:22 by rsham             #+#    #+#             */
/*   Updated: 2025/07/06 19:02:04 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*get_texture_path(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (skip_spaces(line + 2));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (skip_spaces(line + 2));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (skip_spaces(line + 2));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (skip_spaces(line + 2));
	return (NULL);
}

static void	set_texture_path(t_game *game, char *line, char *clean_path)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		game->tex.no_path = clean_path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		game->tex.so_path = clean_path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		game->tex.we_path = clean_path;
	else if (ft_strncmp(line, "EA", 2) == 0)
		game->tex.ea_path = clean_path;
}

int	assign_texture(t_game *game, char *line)
{
	char	*path;
	char	*clean_path;

	path = get_texture_path(line);
	if (!path || !*path)
		return (-1);
	clean_path = ft_strdup(path);
	if (!clean_path)
		return (-1);
	clean_path = trim_newline(clean_path);
	set_texture_path(game, line, clean_path);
	return (1);
}
