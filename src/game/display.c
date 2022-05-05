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

void	draw(t_data *data, int texture, int x, int y)
{
	if (texture == WALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, x, y);
	else if (texture == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_img, x, y);
	else if (texture == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, x, y);
	else if (texture == PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, x, y);
	else if (texture == COLLECT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect_img, x, y);
}

void	display_textures(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			draw(data, data->map[y][x], x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	load_images(t_data *data)
{
	int	width;
	int	height;

	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.XPM", &width, &height);
	data->empty_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/empty.XPM", &width, &height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit.XPM", &width, &height);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player.XPM", &width, &height);
	data->collect_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collectible.XM", &width, &height);
	if (data->wall_img == 0 || data->empty_img == 0 || data
		->exit_img == 0 || data->player_img == 0 || data->collect_img
		== 0)
		{
			if (data->wall_img)
				mlx_destroy_image(data->mlx_ptr, data->wall_img);
			if (data->empty_img)
				mlx_destroy_image(data->mlx_ptr, data->empty_img);
			if (data->exit_img)
				mlx_destroy_image(data->mlx_ptr, data->exit_img);
			if(data->player_img)
				mlx_destroy_image(data->mlx_ptr, data->player_img);
			if(data->collect_img)
				mlx_destroy_image(data->mlx_ptr, data->collect_img);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_display(data->mlx_ptr);
		print_error_free(data, "Failed to load texture (mlx_xpm_file_to_image");
		}
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->empty_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img);
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	mlx_destroy_image(data->mlx_ptr, data->collect_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_array(data->map);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

void	display(t_data *data)
{
	// ft_bzero(&data, sizeof(data));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error_free(data, "mlx_init failed\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 50, data->height * 50, "so_long");
	// data->img = mlx_new_image(data->mlx_ptr, data->width * 50, data->width * 50);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
	// 		&data.line_length, &data.endian);
	load_images(data);
	display_textures(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
}
