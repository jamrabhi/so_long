/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:58:11 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/04/23 01:58:14 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	display()
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_mlx_data	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	// mlx_loop(mlx);
	mlx_data.img = mlx_new_image(mlx, 1920, 1080);
	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel,
		&mlx_data.line_length, &mlx_data.endian);
}
