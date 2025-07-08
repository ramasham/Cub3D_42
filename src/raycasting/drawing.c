/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:50:17 by rsham             #+#    #+#             */
/*   Updated: 2025/07/06 17:50:49 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_pixel(t_game *game, int x, int y, int color)
{
	int	pixel;

	pixel = y * game->line_len + x * (game->bpp / 8);
	*(unsigned int *)(game->img_data + pixel) = color;
}

void	draw_vertical_line(t_game *game, int x, t_line line, int color)
{
	int	y;

	if (line.y_start < 0)
		line.y_start = 0;
	if (line.y_end >= game->screen_height)
		line.y_end = game->screen_height - 1;
	y = line.y_start;
	while (y <= line.y_end)
	{
		put_pixel(game, x, y, color);
		y++;
	}
}
