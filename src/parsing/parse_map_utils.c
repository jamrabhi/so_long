/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:07:06 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/09/20 21:07:08 by jamrabhi         ###   ########.fr       */
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

int	check_rectangle(char **map)
{
	size_t i;
	size_t x;
	size_t y;

	i = 0;
	x = ft_strlen(map[0]);
	printf("x = %ld\n", x);
	while (map[i])
	{
		if (ft_strlen(map[i]) != x)
			return (1);
		i++;
	}
	y = i;
	printf("y = %ld\n", y);
	if (y == x || y == 1)
		return (1);
	return (0);
}

int	check_first_last_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!map[i])
		return (1);
	while (map[i][++j])
		if (map[i][j] != '1')
			return (1);
	while (map[i])
		i++;
	i--;
	j = -1;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (1);
	return (0);
}

int	check_borders(char **map)
{
	int	i;
	int	j;
	int	last_char;

	i = 0;
	j = 0;
	last_char = (ft_strlen(map[i]) - 1);
	while (map[i])
	{
		j = 0;
		last_char = (ft_strlen(map[i]) - 1);
		if (map[i][j] == ' ' || map[i][last_char] == ' ')
		{
			while (map[i][j] && map[i][j] == ' ')
				j++;
			while (map[i][last_char] > 0 && map[i][last_char] == ' ')
				last_char--;
		}
		if (map[i][j] != '1' || map[i][last_char] != '1')
			return (0);
		i++;
	}
	return (1);
}
