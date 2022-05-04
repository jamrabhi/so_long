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

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	display()
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_data	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 400, "so_long");
	mlx_data.img = mlx_new_image(mlx, 200, 400);
	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel,
		&mlx_data.line_length, &mlx_data.endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&mlx_data, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&mlx_data, 6, 5, 0x00FF0000);
	// my_mlx_pixel_put(&mlx_data, 7, 5, 0x00FF0000);
	// my_mlx_pixel_put(&mlx_data, 8, 5, 0x00FF0000);
	// my_mlx_pixel_put(&mlx_data, 9, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, mlx_data.img, 2, 2);
	mlx_loop(mlx);
}
