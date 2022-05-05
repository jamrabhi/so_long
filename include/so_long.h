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
# include "../src/get_next_line/get_next_line.h"
# include <mlx.h>

//A SUPPRIMER !!!!
# include <stdio.h>

typedef struct s_data
{
	int		fd;
	size_t	width;
	size_t	height;
	int		collectible;
	int		map_exit;
	int		player_start;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*wall_img;
	void	*empty_img;
	void	*exit_img;
	void	*player_img;
	void	*collect_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

// typedef struct	s_mlx_data {
// 	char	**map;
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	void	*img;
// 	void	*wall_img;
// 	void	*empty_img;
// 	void	*exit_img;
// 	void	*player_img;
// 	void	*collect_img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_mlx_data;

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

void	free_array(char **str);
int		print_error(char *error);
int		print_error_free(t_data *data, char *error);
char	**parse_map(char *line, t_data *data);
void	check_ber(char *file_name);
int		check_first_last_line(char **map);
int		check_rectangle(char **map, t_data *data);
int		check_borders(char **map, t_data *data);
int		check_valid_char(char **map, t_data *data);
void	display(t_data *data);

#endif
