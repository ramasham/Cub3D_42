/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:38:43 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:54:54 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_game(t_game *game)
{
	free_map_2d(game);
	free_identifiers(game);
	free_textures(game);
	if (game->img && game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
	free_window(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	win_size(t_game *game)
{
	if (!game)
		return ;
	game->screen_height = 720;
	game->screen_width = 1280;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (init_game(&game, argv[1]))
		return (1);
	execution(&game);
	free_game(&game);
	return (0);
}
