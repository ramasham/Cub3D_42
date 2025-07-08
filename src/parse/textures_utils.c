/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:50:25 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 11:50:39 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	skip_empty_lines(char *line)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = NULL;
		return (1);
	}
	return (0);
}

char	*skip_spaces(char *str)
{
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v'))
		str++;
	return (str);
}

char	*trim_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

int	is_map_line(char *line)
{
	if (!line || line[0] == '\0')
		return (0);
	if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
		return (1);
	return (0);
}

int	cleanup_and_exit(t_game *game, char **line, char *error_msg)
{
	free(*line);
	close(game->map.fd);
	get_next_line(-1);
	if (error_msg)
		ft_putstr_fd(error_msg, 2);
	return (1);
}
