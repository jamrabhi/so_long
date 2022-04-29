/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:22:18 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/08 19:22:22 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*get_array(char *line, t_data *data)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		ret;

	str = ft_strdup("");
	ret = 1;
	while (ret)
	{
		ret = get_next_line(data->fd, &line);
		if (ret < 0)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		tmp = ft_strjoin(line, "\n");
		tmp2 = ft_strjoin(str, tmp);
		free(str);
		str = ft_strdup(tmp2);
		free(line);
		free(tmp);
		free(tmp2);
	}
	close(data->fd);
	return (str);
}

void	check_ber(char *file_name)
{
	const char	*dot;

	dot = NULL;
	dot = ft_strrchr(file_name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5) != 0 || !dot[-1] || dot[-1] == '/')
		print_error("Incorrect file format\n");
}

void	parse_map(char *file_ber, t_data *data)
{
	char	*map_str;
	char	**map_array;

	check_ber(file_ber);
	map_str = get_array(file_ber, data);
	map_array = ft_split(map_str, '\n');
	if (!map_array[0] || check_rectangle(map_array, data)
		|| check_borders(map_array, data) || check_valid_char(map_array, data))
	{
		free(map_str);
		free_array(map_array);
		print_error("Invalid map\n");
	}
	free(map_str);
	free_array(map_array);
}
