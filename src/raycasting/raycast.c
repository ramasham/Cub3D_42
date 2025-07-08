/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:48:44 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/07/06 19:16:26 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_plane_x = player->plane_x;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	player->plane_x = player->plane_x * cos(angle) - player->plane_y
		* sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	draw_column(t_game *game, int x, t_ray *ray)
{
	double	wall_x;
	t_line	ceiling_line;
	t_line	floor_line;

	ray->texture = select_texture(game, ray);
	wall_x = calc_wall_x(game, ray);
	ray->tex_x = calc_tex_x(ray, wall_x);
	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - game->screen_height / 2 + ray->line_height
			/ 2) * ray->step;
	ceiling_line.y_start = 0;
	ceiling_line.y_end = ray->draw_start - 1;
	draw_vertical_line(game, x, ceiling_line, game->ceiling_color);
	draw_wall_strip(game, x, ray);
	floor_line.y_start = ray->draw_end + 1;
	floor_line.y_end = game->screen_height - 1;
	draw_vertical_line(game, x, floor_line, game->floor_color);
}

static void	draw_black_column(t_game *game, int x)
{
	t_line	black_line;

	black_line.y_start = 0;
	black_line.y_end = game->screen_height - 1;
	draw_vertical_line(game, x, black_line, 0x000000);
}

void	raycasting(t_game *game)
{
	int		x;
	int		wall_hit;
	t_ray	ray;
	double	player_x;
	double	player_y;

	x = 0;
	player_x = game->player.x / TILE_SIZE;
	player_y = game->player.y / TILE_SIZE;
	while (x < game->screen_width)
	{
		init_ray(&ray, game, x);
		setup_dda(&ray, player_x, player_y);
		wall_hit = perform_dda(&ray, game);
		if (wall_hit)
		{
			calculate_projection(game, &ray, player_x, player_y);
			draw_column(game, x, &ray);
		}
		else
			draw_black_column(game, x);
		x++;
	}
}
