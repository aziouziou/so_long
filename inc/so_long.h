/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abziouzi <abziouzi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:08:49 by abziouzi          #+#    #+#             */
/*   Updated: 2022/11/22 20:36:00 by abziouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include "libft/libft.h"
// # include <mlx.h>
# include "mlx/mlx.h"

// Keys
# define KEY_LEFT				0
# define KEY_DOWN				1
# define KEY_RIGHT				2
# define KEY_UP					13
# define KEY_ESC				53

// Errors & Messages
# define ERR_ARGS				"ERROR : Invalid arguments. Use : ./so_long [*.ber] map."
# define ERR_ARGS_BONUS			"ERROR : Invalid arguments. Use : ./so_long_bonus [*.ber] map."
# define ERR_MAP_EXT			"ERROR : Invalid file extension. Only [*.ber] files allowed."
# define ERR_MAP_EXIT			"ERROR : Exit."
# define ERR_MAP_READ			"ERROR : Could not read map."
# define ERR_MAP_COLLECTIBLES	"ERROR : Collectibles."
# define ERR_MAP_PLAYER			"ERROR : Player."
# define ERR_MAP_WALLS			"ERROR : Walls."
# define ERR_MLX				"ERROR : MLX error."
# define EXIT_GAME				"Closing game..."
# define GAME_SUCCESS			"ALLAH Y TA9ABAL :)"
# define LINES					"-------------------------------------------------------------"

// XPMs
# define COLLECTIBLE			"./img/collectible.xpm"
# define EMPTY					"./img/empty.xpm"
# define ENEMY					"./img/satan.xpm"
# define EXIT					"./img/exit.xpm"
# define PLAYER_DOWN			"./img/player_down.xpm"
# define PLAYER_LEFT			"./img/player_left.xpm"
# define PLAYER_RIGHT			"./img/player_right.xpm"
# define PLAYER_UP				"./img/player_up.xpm"
# define WALL					"./img/wall.xpm"

// Structs

typedef struct s_point
{
	int	x;
	int	y;
	int	pos;
}				t_point;

typedef struct s_map
{
	char	**data;
	size_t	collectibles;
	size_t	exits;
	size_t	players;
	size_t	enemies;
}				t_map;

typedef struct s_img
{
	bool	ret;
	int		width;
	int		height;
	void	*data;
}				t_img;

typedef struct s_obj
{
	size_t	moves;
	size_t	stacks;
	size_t	height;
	size_t	width;

	t_img	collectible;
	t_img	enemy;
	t_img	exit;
	t_img	floor;
	t_img	player_right;
	t_img	player_left;
	t_img	player_up;
	t_img	player_down;
	t_img	wall;
	t_map	map;
	t_point	player_pos;

	void	*mlx;
	void	*win;
}				t_obj;

bool	check_each_line(t_obj *obj, char *line, size_t length, int y);
bool	check_fl(char *str);
bool	is_valid_ext(char *filename, char *ext);
bool	map_checker(char *filename, t_obj *obj);
bool	map_validator(int fd, t_obj *obj);
bool	map_validator_bis(int fd, t_obj *obj);
bool	checks(t_obj *obj, char *line, size_t length, int y);

int		destroy_window(t_obj *obj);
int		rendering(t_obj *obj);

size_t	get_map_lines(char *filename);

void	check_enemy(t_obj *obj);
void	free_all(t_obj *obj);
void	load_images(t_obj *obj);
void	movement(int keycode, t_obj *obj);
void	render(t_obj *obj);
void	trim_nl(char *line, int length);

#endif
