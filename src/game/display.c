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
			data->wall_img, x * 50, y * 50);
	else if (texture == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->empty_img, x * 50, y * 50);
	else if (texture == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, x * 50, y * 50);
	else if (texture == PLAYER)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, x * 50, y * 50);
		data->player_pos_x = x;
		data->player_pos_y = y;
	}
	else if (texture == COLLECT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect_img, x * 50, y * 50);
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
			draw(data, data->map[y][x], x, y);
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
			"./textures/collectible.XPM", &width, &height);
	if (data->wall_img == 0 || data->empty_img == 0 || data
		->exit_img == 0 || data->player_img == 0 || data->collect_img
		== 0)
		print_error_free(data, "Failed to load texture\n");
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == UP_KEY)
		move_player(data, data->player_pos_x, data->player_pos_y - 1);
	else if (keycode == DOWN_KEY)
		move_player(data, data->player_pos_x, data->player_pos_y + 1);
	else if (keycode == LEFT_KEY)
		move_player(data, data->player_pos_x - 1, data->player_pos_y);
	else if (keycode == RIGHT_KEY)
		move_player(data, data->player_pos_x + 1, data->player_pos_y);
	return (0);
}

void	display(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error_free(data, "Failed to init mlx\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 50,
			data->height * 50, "so_long");
	if (!data->win_ptr)
		print_error_free(data, "Failed to create window\n");
	load_images(data);
	display_textures(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
}
