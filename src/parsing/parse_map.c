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

void	print_array(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		printf("line[%d]='%s'\n",i, str[i]);
		i++;
	}
}

int	empty_space(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
					map[i][j] == 'E' || map[i][j] == 'W') && (!(empty_space(map
					[i][j + 1]) && empty_space(map[i - 1][j]) &&
					empty_space(map[i + 1][j]))))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

char	*get_array(char *line, t_data *data)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_strdup("");
	while (get_next_line(data->fd, &line))
	{
		tmp = ft_strjoin(line, "\n");
		tmp2 = ft_strjoin(str, tmp);
		free(str);
		str = ft_strdup(tmp2);
		free(line);
		free(tmp);
		free(tmp2);
	}
	free(line);
	close(data->fd);
	return (str);
}

void	parse_map(char *line, t_data *data)
{
	char	*map_str;
	char	**map_array;

	map_str = get_array(line, data);
	if (map_str[0] == '\0')
	{
		free(map_str);
		print_error("Empty map\n");
	}
	map_array = ft_split(map_str, '\n');
	print_array(map_array);
	if (check_rectangle(map_array, data) || check_borders(map_array, data) ||
		check_valid_char(map_array, data))
	{
		free(map_str);
		free_array(map_array);
		print_error("Invalid map\n");
	}
	// if (!(check_valid_map(map_str) && check_first_line(map_array)
	// 		&& check_last_line(map_array) && check_borders(map_array)
	// 		&& check_map(map_array)))
	// {
	// 	free(map_str);
	// 	free_array(map_array);
	// 	print_error("Invalid map");
	// }
	free(map_str);
	free_array(map_array);
}
