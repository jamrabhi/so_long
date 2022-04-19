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

//A SUPPRIMER !!!!
# include <stdio.h>

typedef struct s_data
{
	int	fd;
}				t_data;

int		print_error(char *error);
void	parse_line(char *file_ber, t_data *data);

#endif
