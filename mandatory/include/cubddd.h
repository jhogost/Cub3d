/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubddd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhervieu <hhervieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:17:40 by jbayet            #+#    #+#             */
/*   Updated: 2026/05/28 09:23:42 by hhervieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBDDD_H
# define CUBDDD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <errno.h>
# include <time.h>
# include <math.h>
# include <float.h>
# include "../minilibx-linux/mlx.h"

# define BUFFER_SIZE 64
# define TEXTURE_SIZE 128
# define WIN_WIDTH 1280
# define WIN_HEIGHT 800
# define FOV 0.80
# define FPS_LIMIT 60
# define EVENT_DESTROY 17
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define INPUT_FORWARD 0
# define INPUT_BACKWARD 1
# define INPUT_STRAFE_LEFT 2
# define INPUT_STRAFE_RIGHT 3
# define INPUT_TURN_LEFT 4
# define INPUT_TURN_RIGHT 5
# define INPUT_COUNT 6

typedef struct s_pixel
{
	int	red;
	int	green;
	int	blue;
}	t_pixel;

typedef struct s_color
{
	t_pixel	*floor;
	t_pixel	*ceiling;
	int		floor_pixel;
	int		ceiling_pixel;
}	t_color;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_textures
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_textures;

typedef struct s_coord
{
	double	x;
	double	y;
	double	ply_dir_x;
	double	ply_dir_y;
	double	sensor_x;
	double	sensor_y;
}	t_coord;

typedef struct s_ray
{
	double	sensor_col;
	double	sensor_div;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit;
	int		side;
	double	x_hit;
	double	distance;
	double	perp_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
}	t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_textures		*textures;
	t_color			*color;
	char			**map;
	t_coord			*player;
	int				input[INPUT_COUNT];
	t_img			*img;
	struct timeval	time_fps_limit;
}	t_game;

/* --init-- */
void	init_graphic(t_game *game);
void	init_game(t_game **game);
void	init(char *filename, t_game **game);

/* --init base-- */
void	img_to_null(t_textures *textures);
void	init_textu_img(t_textures *textures, t_game *game);
void	init_textures(t_game *game);
void	init_color(t_game *game);
void	init_img(t_game *game);

/* --init map-- */
void	color_to_zero(t_game *game);
void	map_to_null(t_game *game, int max);
int		init_map(char *filename, t_game *game, int count);
void	init_player(t_game *game);

/* --init elem-- */
void	parsing_player(t_game *game);

/* --free-- */
void	free_textures(t_game *game);
void	free_color(t_game *game);
void	free_map(t_game *game);
void	free_game(t_game *game);
void	exit_game(t_game *game, int out);

/* --free textures-- */
void	free_textures_part1(t_game *game);
void	free_textures_part2(t_game *game);

/* --check-- */
int		is_ok_arg(int argc, char **argv);
int		missing_info(t_game *game);

/* --parsing-- */
int		parsing_textures(char *line, t_game *game, t_img *texture);
int		parsing_pixel(char *line, t_pixel *color, int j, unsigned int step);
int		parsing_color(char *line, t_pixel *color);
int		parsing_line(char *line, t_game *game);
int		parsing_textu_color(char *filename, t_game *game);

/* --parsing map-- */
int		parsing_line_map(char *line);
int		fill_map(char *filename, t_game *game, int status, int in_map);
int		parsing_map(char *filename, t_game *game);

/* --render-- */
void	draw_floor_and_ceiling(t_game *game, t_img *img);
void	raycast_scene(t_game *game, t_img *img);
int		render_frame(t_game *game);

/* --raycasting-- */
void	init_ray(t_game *game, t_ray *ray, int col);
void	init_step(t_game *game, t_ray *ray);
void	dda(t_game *game, t_ray *ray);
void	calculate_wall(t_game *game, t_ray *ray);
void	draw_wall(t_game *game, t_img *img, t_ray *ray, int col);

/* --textures-- */
t_img	*get_texture(t_game *game, t_ray *ray);
int		get_tex_color(t_img *tex, int x, int y);

/* --utils graphique-- */
int		create_rgb(t_pixel *pixel);
void	put_pixel(t_img *img, int x, int y, int color);

/* --player_controls-- */
void	move_player(t_game *game, double direction);
void	strafe_player(t_game *game, double direction);
void	rotate_player(t_coord *player, double angle);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
void	update_player(t_game *game);
int		can_walk(char **map, double x, double y);

/* --utils game-- */
int		is_player(char c);
int		is_walkable(char c);
int		is_map_char(char c);
int		is_map_line(char *str);
char	get_map_char(char **map, int y, int x);

/* --utils-- */
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
int		ft_abs(int value);
void	flood_fill(char **map, int x, int y);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		is_empty_line(char *line);
int		is_num_string(char *str);

#endif
