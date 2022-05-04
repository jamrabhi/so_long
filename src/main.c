/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:41:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/06/27 21:44:32 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	show_array(char **str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			printf("%c", str[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_error("Usage: ./so_long map.ber\n");
	ft_bzero(&data, sizeof(data));
	data.fd = open(argv[1], O_DIRECTORY);
	if (data.fd != -1)
		print_error("Map specified is a directory\n");
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		print_error("File doesn't exist\n");
	data.map = parse_map(argv[1], &data);
	show_array(data.map);
	//DEBUG
	printf("\ndata->fd = %d\n", data.fd);
	printf("data->width = %ld\n", data.width);
	printf("data->height = %ld\n", data.height);
	printf("data->collectible = %d\n", data.collectible);
	printf("data->map_exit = %d\n", data.map_exit);
	printf("data->player_start = %d\n\n", data.player_start);
	printf("OK !\n");
	//END DEBUG
	display(&data);
	free_array(data.map);
	return (0);
}
