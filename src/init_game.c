/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:34:05 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 14:23:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	init_game_vars(game);
	init_map_struct(game);
	init_ray_struct(game);
	init_player_struct(game);
	init_texture_struct(game);
}

int	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_memset(game->img_data, 0, game->screen_height * game->line_len);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

static int	free_game_return(t_game *game)
{
	free_game(game);
	return (1);
}

int	init_game(t_game *game, char *filename)
{
	init_data(game);
	if (check_name(filename))
		return (1);
	if (parsing(game, filename))
		return (free_game_return(game));
	win_size(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game_return(game));
	if (init_textures(game))
		return (free_game_return(game));
	return (0);
}

void	execution(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3D");
	if (!game->win)
		exit(1);
	game->img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	game->img_data = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, esc_key, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_handler, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, mouse_handler, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}
