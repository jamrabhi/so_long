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

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		print_error("Usage: ./so_long map.ber\n");
	ft_bzero(&data, sizeof(data));
	data.fd = open(argv[1], O_DIRECTORY);
	if (data.fd != -1)
		print_error("Map specified is a directory\n");
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		print_error("File doesn't exist\n");
	parse_line(argv[1], &data);
	printf("OK !\n");
	return (0);
}
