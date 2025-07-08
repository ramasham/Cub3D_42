/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:06:03 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:48:54 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_texture_data(t_game *game, int index)
{
	game->tex.texture_data[index] = (int *)mlx_get_data_addr(
			game->tex.textures[index], &game->tex.bpp,
			&game->tex.line_len, &game->tex.endian);
}

static void	load_texture_data(t_game *game)
{
	get_texture_data(game, NO);
	get_texture_data(game, SO);
	get_texture_data(game, WE);
	get_texture_data(game, EA);
}

static void	load_image(t_game *game, int index, char *path)
{
	game->tex.textures[index] = mlx_xpm_file_to_image(
			game->mlx, path, &game->tex.width, &game->tex.height);
}

static int	load_images(t_game *game)
{
	load_image(game, NO, game->tex.no_path);
	load_image(game, SO, game->tex.so_path);
	load_image(game, WE, game->tex.we_path);
	load_image(game, EA, game->tex.ea_path);
	if (!game->tex.textures[NO] || !game->tex.textures[SO]
		|| !game->tex.textures[WE] || !game->tex.textures[EA])
		return (1);
	return (0);
}

int	init_textures(t_game *game)
{
	game->tex.tex_width = TEX_WIDTH;
	game->tex.tex_height = TEX_HEIGHT;
	if (load_images(game))
	{
		free_textures(game);
		free_game(game);
		ft_putstr_fd("Error: loading textures\n", 2);
		return (1);
	}
	load_texture_data(game);
	return (0);
}
