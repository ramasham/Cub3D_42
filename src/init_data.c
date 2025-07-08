/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:05:37 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 11:41:44 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_game_vars(t_game *game)
{
	game->rows = 0;
	game->cols = 0;
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->screen_width = 0;
	game->screen_height = 0;
	game->bpp = 0;
	game->line_len = 0;
	game->endian = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_data = NULL;
	game->mouse_x = 0;
	game->mouse_y = 0;
	game->last_mouse_x = 0;
	game->mouse_captured = 0;
}

void	init_map_struct(t_game *game)
{
	game->map.fd = -1;
	game->map.end = 0;
	game->map.id_flag = 0;
	game->map.map_2d = NULL;
}

void	init_ray_struct(t_game *game)
{
	game->ray.map_x = 0;
	game->ray.map_y = 0;
	game->ray.ray_dir_x = 0.0;
	game->ray.ray_dir_y = 0.0;
	game->ray.delta_dist_x = 0.0;
	game->ray.delta_dist_y = 0.0;
	game->ray.side_dist_x = 0.0;
	game->ray.side_dist_y = 0.0;
	game->ray.perp_wall_dist = 0.0;
	game->ray.tex_pos = 0.0;
	game->ray.step = 0.0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.side = 0;
	game->ray.line_height = 0;
	game->ray.draw_start = 0;
	game->ray.draw_end = 0;
	game->ray.tex_x = 0;
	game->ray.texture = NULL;
}

void	init_player_struct(t_game *game)
{
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.angle = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
}

void	init_texture_struct(t_game *game)
{
	game->tex.tex_width = TEX_WIDTH;
	game->tex.tex_height = TEX_HEIGHT;
	game->tex.width = 0;
	game->tex.height = 0;
	game->tex.bpp = 0;
	game->tex.line_len = 0;
	game->tex.endian = 0;
	game->tex.no_path = NULL;
	game->tex.so_path = NULL;
	game->tex.we_path = NULL;
	game->tex.ea_path = NULL;
	game->tex.textures[NO] = NULL;
	game->tex.textures[SO] = NULL;
	game->tex.textures[WE] = NULL;
	game->tex.textures[EA] = NULL;
	game->tex.texture_data[NO] = NULL;
	game->tex.texture_data[SO] = NULL;
	game->tex.texture_data[WE] = NULL;
	game->tex.texture_data[EA] = NULL;
}
