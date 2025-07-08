/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:51:01 by rsham             #+#    #+#             */
/*   Updated: 2025/07/06 18:54:12 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (game->tex.texture_data[WE]);
		else
			return (game->tex.texture_data[EA]);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (game->tex.texture_data[NO]);
		else
			return (game->tex.texture_data[SO]);
	}
}

double	calc_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	wall_x = 0;
	if (ray->side == 0)
		wall_x = game->player.y / TILE_SIZE + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		wall_x = game->player.x / TILE_SIZE + ray->perp_wall_dist
			* ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

int	calc_tex_x(t_ray *ray, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
	{
		tex_x = TEX_WIDTH - tex_x - 1;
	}
	return (tex_x);
}

void	draw_wall_strip(t_game *game, int x, t_ray *ray)
{
	int	y;
	int	tex_y;
	int	color;
	int	pixel;

	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		color = ray->texture[TEX_HEIGHT * tex_y + ray->tex_x];
		if (ray->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		pixel = y * game->line_len + x * (game->bpp / 8);
		*(unsigned int *)(game->img_data + pixel) = color;
		y++;
	}
}
