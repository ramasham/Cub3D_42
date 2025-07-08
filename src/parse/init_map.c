/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:57:14 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:17:05 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map_size(t_game *game, char **line)
{
	int	j;

	j = 0;
	while (1)
	{
		*line = get_next_line(game->map.fd);
		if (!*line)
			break ;
		j = ft_strlen(*line);
		if (j > 0 && (*line)[j - 1] == '\n')
			j--;
		if (j > game->cols)
			game->cols = j;
		game->rows++;
		free(*line);
		*line = NULL;
	}
}

int	allocate_2d_map(t_game *game)
{
	int	i;

	i = 0;
	game->map.map_2d = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map.map_2d)
	{
		ft_putstr_fd("Error: malloc failed for map_2d\n", 2);
		return (1);
	}
	while (i < game->rows)
	{
		game->map.map_2d[i] = NULL;
		i++;
	}
	game->map.map_2d[game->rows] = NULL;
	return (0);
}

int	open_map_file(t_game *game, char *map)
{
	game->map.fd = open(map, O_RDONLY);
	if (game->map.fd == -1)
	{
		free_map_2d(game);
		ft_putstr_fd("Error: Map not found! \n", 2);
		return (1);
	}
	return (0);
}

int	store_map_line(t_game *game, char *line, int *i)
{
	if (*i >= game->rows)
		return (0);
	if (!line)
	{
		ft_putstr_fd("Error: NULL line in store_map_line\n", 2);
		return (1);
	}
	if (game->map.map_2d[*i])
		free(game->map.map_2d[*i]);
	game->map.map_2d[*i] = ft_strdup(line);
	if (!game->map.map_2d[*i])
	{
		ft_putstr_fd("Error: malloc failed in ft_strdup\n", 2);
		return (1);
	}
	(*i)++;
	return (0);
}
