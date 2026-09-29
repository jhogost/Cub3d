/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubddd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbayet <jbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:17:40 by jbayet            #+#    #+#             */
/*   Updated: 2026/06/15 10:03:25 by jbayet           ###   ########.fr       */
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
# define MINIMAP_X 1168
# define MINIMAP_Y 625
# define STAGE_X 50
# define STAGE_Y 752
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
# define KEY_L 108
# define KEY_E 101
# define INPUT_FORWARD 0
# define INPUT_BACKWARD 1
# define INPUT_STRAFE_LEFT 2
# define INPUT_STRAFE_RIGHT 3
# define INPUT_TURN_LEFT 4
# define INPUT_TURN_RIGHT 5
# define INPUT_COUNT 6
# define KEY_E 101

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
	t_img	*lo;
	t_img	*gr;
	t_img	*bl;
	t_img	*pu;
	t_img	*re;
	t_img	*or;
	t_img	*ye;
	t_img	*al;
	t_img	*st;
	t_img	*lig;
	t_img	*ton;
	t_img	*tof;
	t_img	*rti;
	t_img	*rto;
	t_img	*m_a;
	t_img	*m_b;
	t_img	*doo;
	t_img	*doi;
	t_img	*hud;
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

typedef struct s_sprite
{
	char	id;
	int		status;
	double	x;
	double	y;
	double	dist;
}	t_sprite;

typedef struct s_sprite_draw
{
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		width;
	int		height;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		tex_x;
	int		tex_y;
}	t_sprite_draw;

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

typedef enum e_door_state
{
	DOOR_CLOSED,
	DOOR_OPENING,
	DOOR_OPEN,
	DOOR_CLOSING
}	t_door_state;

typedef struct s_door
{
	int				x;
	int				y;
	t_door_state	state;
	double			offset;
	char			type;
}	t_door;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_textures		*textures;
	t_color			*color;
	char			**map;
	t_coord			*player;
	t_sprite		*sprites;
	t_door			*doors;
	int				sprite_count;
	int				stage;
	int				moulinette_find;
	int				input[INPUT_COUNT];
	double			zbuffer[WIN_WIDTH];
	int				frame;
	int				fps;
	struct timeval	time_fps_control;
	struct timeval	time_fps_limit;
	int				mouse_x;
	int				mouse_y;
	int				mouse_locked;
}	t_game;

/* --init-- */
void	init_graphic(t_game *game);
void	game_to_null(t_game *game);
void	init_game(t_game **game);
void	init(char *filename, t_game **game);

/* --init stage-- */
void	init_stage(char *filename, t_game *game);
void	init_next_stage(t_game *game);

/* --init base-- */
void	init_textures(t_game *game);
void	init_color(t_game *game);
void	init_img(t_game *game);
void	init_hud(t_game *game, t_img *texture);

/* --init textures-- */
void	init_textu_img_part1(t_textures *textures, t_game *game);
void	init_textu_img_part2(t_textures *textures, t_game *game);
void	init_textu_img_part3(t_textures *textures, t_game *game);
void	init_textu_img_part4(t_textures *textures, t_game *game);
void	init_textu_img_part5(t_textures *textures, t_game *game);
/* --init textures_2-- */
void	init_textu_img_part6(t_textures *textures, t_game *game);

/* --init textures data-- */
void	init_textu_img_data_part1(t_textures *textures);
void	init_textu_img_data_part2(t_textures *textures);

/* --init map-- */
void	color_to_zero(t_game *game);
void	map_to_null(t_game *game, int max);
int		init_map(char *filename, t_game *game, int count);
void	init_player(t_game *game);
void	init_doors(t_game *game);

/* --init sprite-- */
int		count_sprites(char **map);
void	fill_sprites(t_game *game);
void	init_sprites(t_game *game);

/* --parsing elem-- */
void	parsing_player(t_game *game);

/* --free-- */
void	free_game(t_game *game);
void	exit_game(t_game *game, int out);

/* --free stage-- */
void	free_color(t_game *game);
void	free_map(t_game *game);
void	free_textures(t_game *game);
void	free_stage(t_game *game);

/* --free textures-- */
void	free_textures_part1(t_game *game);
void	free_textures_part2(t_game *game);
void	free_textures_part3(t_game *game);
void	free_textures_part4(t_game *game);
void	free_textures_part5(t_game *game);
/* --free textures_2-- */
void	free_textures_part6(t_game *game);

/* --check-- */
int		is_ok_arg(int argc, char **argv);
int		missing_info(t_game *game);

/* --parsing-- */
int		parsing_textures(char *line, t_game *game, t_img *texture);
int		parsing_pixel(char *line, t_pixel *color, int j, unsigned int step);
int		parsing_color(char *line, t_pixel *color);
int		parsing_textu_color(char *filename, t_game *game);

/* --parsing line-- */
int		parsing_line(char *line, t_game *game);
int		parsing_line2(char *line, t_game *game);
int		parsing_line3(char *line, t_game *game);

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
/* --raycasting extra-- */
void	check_door_hit(t_game *game, t_ray *ray, int *hit);

/* --textures-- */
t_img	*get_texture(t_game *game, t_ray *ray);
int		get_tex_color(t_img *tex, int x, int y);

/* --hud-- */
void	draw_hud(t_game *game);
void	draw_minimap(t_game *game, int pos_x, int pos_y);
void	draw_square(t_game *game, int x_start, int y_start, int color);
void	draw_red_step(t_game *game);
void	draw_red_line(t_game *game, int start_x);

/* --sprite-- */
void	sort_sprites(t_game *game);
void	draw_one_sprite(t_game *game, t_sprite *sprite, t_img *img);
void	draw_sprites(t_game *game);

/* --player_controls-- */
void	move_player(t_game *game, double direction);
void	strafe_player(t_game *game, double direction);
void	rotate_player(t_coord *player, double angle);
void	update_player(t_game *game);

/* --player_action-- */
void	terminal_switch(t_game *game, int x, int y);
void	action_player(t_game *game);

/* --target_action-- */
int		get_target(t_game *game, t_coord *player, int *x, int *y);

/* --cub3d-- */
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
int		game_loop(t_game *game);

/* --win loose- */
int		player_touch_out(t_game *game, char out);
int		win_condition(t_game *game);
int		loose_condition(t_game *game);

/* --walls-- */
int		walls_border(char **map, double x, double y, char c);
int		can_walk(t_game *game, char **map, double x, double y);

/* --mouse-- */
void	lock_or_unlock_mouse(t_game *game);
void	init_mouse(t_game *game);
void	center_and_hide_mouse(t_game *game);
int		handle_mouse_move(int x, int y, t_game *game);

/* --doors-- */
void	fill_doors(t_game *game);
t_door	*get_door_at(t_game *game, int x, int y);
void	toggle_door(t_game *game, int target_x, int target_y);
void	update_doors(t_game *game);

/* --utils graphique-- */
int		create_rgb(t_pixel *pixel);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_x_position_minimap(t_game *game);
int		get_y_position_minimap(t_game *game);
int		find_square_color(t_game *game, int x, int y);

/* --utils game-- */
int		is_player(char c);
int		is_walkable(char c);
int		is_sprite_char(char c);
int		is_wall_char(char c);
int		is_map_char(char c);

/* --utils game1-- */
int		is_door_char(char c);
int		is_terminal_char(char c);
int		is_interachar(char c);
int		is_door_closed(t_door *doors, char c);

/* --utils game 2-- */
int		is_map_line(char *str);
char	get_map_char(char **map, int y, int x);
char	get_player_direction(t_coord *player);
int		get_sprite_from_pos(t_sprite *sprites, int max_sprite, int x, int y);

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
