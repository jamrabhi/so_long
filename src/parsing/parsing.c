/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:00 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 23:36:00 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_ber(char *file_name)
{
	const char	*dot;

	dot = NULL;
	dot = ft_strrchr(file_name, '.');
	if (!dot || ft_strncmp(dot, ".ber", 5) != 0)
		print_error("Incorrect file format");
}

int	check_elements(void)
{
	if (g_map.no_path && g_map.so_path && g_map.ea_path && g_map.we_path
		&& g_map.f[0] > -1 && g_map.c[0] > -1)
		return (1);
	return (0);
}

// int	check_empty_line(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

void	parse_line(char *file_ber, t_data *data)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	printf("%s\n", file_ber);
	check_ber(file_ber);
	while (ret)
	{
		ret = get_next_line(data->fd, &line);
		free(line);
	}
	// if (!check_elements())
	// 	print_error("Missing element in the .cub file");
	// parse_map(line);
	close(data->fd);
}
