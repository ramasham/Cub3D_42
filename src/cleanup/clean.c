/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:49:38 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:40:51 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_copy_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_map_2d(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map.map_2d)
		return ;
	while (i < game->rows)
	{
		free(game->map.map_2d[i]);
		i++;
	}
	free(game->map.map_2d);
	game->map.map_2d = NULL;
}

void	free_identifiers(t_game *game)
{
	if (game->tex.no_path)
		free(game->tex.no_path);
	if (game->tex.so_path)
		free(game->tex.so_path);
	if (game->tex.we_path)
		free(game->tex.we_path);
	if (game->tex.ea_path)
		free(game->tex.ea_path);
	game->tex.no_path = NULL;
	game->tex.so_path = NULL;
	game->tex.we_path = NULL;
	game->tex.ea_path = NULL;
}

void	free_textures(t_game *game)
{
	if (game->mlx)
	{
		if (game->tex.textures[NO])
			mlx_destroy_image(game->mlx, game->tex.textures[NO]);
		if (game->tex.textures[SO])
			mlx_destroy_image(game->mlx, game->tex.textures[SO]);
		if (game->tex.textures[WE])
			mlx_destroy_image(game->mlx, game->tex.textures[WE]);
		if (game->tex.textures[EA])
			mlx_destroy_image(game->mlx, game->tex.textures[EA]);
	}
	game->tex.textures[NO] = NULL;
	game->tex.textures[SO] = NULL;
	game->tex.textures[WE] = NULL;
	game->tex.textures[EA] = NULL;
}

void	free_window(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}
