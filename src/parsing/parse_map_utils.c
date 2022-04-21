/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bheight: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:07:06 bheight jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/20 21:07:08 bheight jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// int	check_valid_map(char *str)
// {
// 	int	i;
// 	int	wall_count;

// 	i = 0;
// 	wall_count = 0;
// 	g_map.spawn_dir = 0;
// 	while (str && str[i])
// 	{
// 		if (!(str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' ')
// 			&& ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i]
// 					== 'W') && g_map.spawn_dir != 0))
// 			return (0);
// 		if (str[i] == '1')
// 			wall_count++;
// 		if (wall_count > 0 && str[i] == '\n' && str[i + 1] == '\n')
// 			return (0);
// 		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
// 			g_map.spawn_dir = str[i];
// 		i++;
// 	}
// 	if (g_map.spawn_dir == 0)
// 		return (0);
// 	return (1);
// }

int	check_valid_char(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == 'C')
				data->collectible++;
			else if (map[i][j] == 'E')
				data->map_exit++;
			else if (map[i][j] == 'P')
				data->player_start++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (1);
			j++;
		}
	}
	if (data->collectible == 0 || data->map_exit == 0 || data->player_start
		!= 1)
	{
		printf("KO");
		return (1);
	}
	return (0);
}

int	check_rectangle(char **map, t_data *data)
{
	size_t width;
	size_t height;

	width = ft_strlen(map[0]);
	height = 0;
	printf("width = %ld\n", width);
	while (map[height])
	{
		if (ft_strlen(map[height]) != width)
			return (1);
		height++;
	}
	// printf("height = %ld\n", height);
	if (height == width || height == 1)
		return (1);
	data->width = width;
	data->height = height;
	return (0);
}

int	check_borders(char **map, t_data *data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[0][j] != '1' || map[data->height - 1][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][data->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
