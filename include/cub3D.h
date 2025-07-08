/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:17 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 14:22:43 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <ctype.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ROT_SPEED 0.10
# define MOUSE_SENSITIVITY 0.002
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MOVE_SPEED 10.0
# define KEY_LEFT_ARROW 65361
# define KEY_RIGHT_ARROW 65363

typedef enum e_texture
{
	NO,
	SO,
	WE,
	EA
}				t_texture;

typedef struct s_line
{
	int			y_start;
	int			y_end;
}				t_line;

typedef struct s_tex
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	void		*textures[4];
	int			*texture_data[4];
	int			tex_width;
	int			tex_height;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_tex;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
}				t_player;

typedef struct s_map
{
	int			fd;
	int			id_flag;
	char		**map_2d;
	int			end;

}				t_map;

typedef struct s_ray
{
	int			tex_x;
	int			map_y;
	int			map_x;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			*texture;
	double		tex_pos;
	double		step;

}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			line_len;
	int			endian;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_tex		tex;
	int			floor_color;
	int			ceiling_color;
	int			screen_width;
	int			screen_height;
	int			rows;
	int			cols;
	int			mouse_x;
	int			mouse_y;
	int			last_mouse_x;
	int			mouse_captured;

}				t_game;

// parsing
void			init_game_vars(t_game *game);
void			init_map_struct(t_game *game);
void			init_ray_struct(t_game *game);
void			init_player_struct(t_game *game);
void			init_texture_struct(t_game *game);
void			init_data(t_game *game);
int				parsing(t_game *game, char *map);
int				read_map(t_game *game, char *map);
int				config_identifier(t_game *game, char **line);
int				store_map_line(t_game *game, char *line, int *i);
int				open_map_file(t_game *game, char *map);
void			get_map_size(t_game *game, char **line);
void			free_map_2d(t_game *game);
void			get_map_size(t_game *game, char **line);
int				find_player_position(t_game *game);
int				allocate_2d_map(t_game *game);
int				parse_rgb(char *line);
int				close_window(void *param);
int				esc_key(int keycode, void *param);
int				key_handler(int keycode, t_game *game);
int				mouse_handler(int x, int y, t_game *game);
int				skip_empty_lines(char *line);
char			*skip_spaces(char *str);
char			*trim_newline(char *str);
int				is_map_line(char *line);
int				cleanup_and_exit(t_game *game, char **line, char *error_msg);
int				assign_texture(t_game *game, char *line);
void			init_data(t_game *game);
int				render_frame(t_game *game);
int				init_game(t_game *game, char *filename);
void			execution(t_game *game);
void			win_size(t_game *game);

// validating
int				check_name(char *map_name);
int				is_player(char c);
int				validate_map(t_game *game);
int				check_player_count(char **map);
int				valid_map_char(char c);
int				validate_characters(char **map);
int				is_valid_cell(char **map);
int				check_player_count(char **map);
int				is_player_surrounded(char **map, int px, int py);
int				validate_player(t_game *game);
char			**duplicate_map(char **map, int rows);
int				flood_fill(char **map, int x, int y, int rows);

// raycasting
void			execution(t_game *game);
int				key_handler(int keycode, t_game *game);
int				render_frame(t_game *game);
void			raycasting(t_game *game);
void			rotate_player(t_player *player, double angle);
int				init_textures(t_game *game);
void			draw_vertical_line(t_game *game, int x, t_line line, int color);
void			init_ray(t_ray *ray, t_game *game, int x);
void			setup_dda(t_ray *ray, double player_map_x, double player_map_y);
int				perform_dda(t_ray *ray, t_game *game);
void			calculate_projection(t_game *game, t_ray *ray,
					double player_map_x, double player_map_y);
int				*select_texture(t_game *game, t_ray *ray);
double			calc_wall_x(t_game *game, t_ray *ray);
int				calc_tex_x(t_ray *ray, double wall_x);
void			draw_wall_strip(t_game *game, int x, t_ray *ray);

// cleanup
void			free_copy_map(char **map);
void			free_identifiers(t_game *game);
void			free_textures(t_game *game);
void			free_game(t_game *game);
void			free_window(t_game *game);
void			free_map_2d(t_game *game);

#endif