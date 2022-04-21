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

//A SUPPRIMER !!!!
# include <stdio.h>

typedef struct s_data
{
	int	fd;
	size_t	width;
	size_t	height;
}				t_data;

int		print_error(char *error);
void	parse_line(char *file_ber, t_data *data);
void	parse_map(char *line, t_data *data);
void	free_array(char **str);
int		check_first_last_line(char **map);
int		check_rectangle(char **map, t_data *data);
int		check_borders(char **map, t_data *data);



#endif
