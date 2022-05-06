/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:15:57 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/04/19 01:16:10 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../src/get_next_line/get_next_line.h"
# include <mlx.h>

typedef struct s_data
{
	int		fd;
	size_t	width;
	size_t	height;
	int		collectible;
	int		map_exit;
	int		player_start;
	int		player_pos_x;
	int		player_pos_y;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*empty_img;
	void	*exit_img;
	void	*player_img;
	void	*collect_img;
	int		move_count;

}				t_data;

enum	e_texture
{
	WALL = '1',
	EMPTY = '0',
	EXIT = 'E',
	PLAYER = 'P',
	COLLECT = 'C'
};

enum	e_keycode
{
	UP_KEY = 119,
	DOWN_KEY = 115,
	LEFT_KEY = 97,
	RIGHT_KEY = 100,
	ESC_KEY = 65307
};

int		print_error(char *error);
char	**parse_map(char *line, t_data *data);
void	check_ber(char *file_name);
int		check_rectangle(char **map, t_data *data);
int		check_borders(char **map, t_data *data);
int		check_valid_char(char **map, t_data *data);
void	free_array(char **str);
void	display(t_data *data);
void	print_error_free(t_data *data, char *error);
void	free_all(t_data *data);
int		close_window(t_data *data);
void	move_player(t_data *data, int to_x, int to_y);
void	display_textures(t_data *data);
void	draw(t_data *data, int texture, int x, int y);
int		render(t_data *data);

#endif
