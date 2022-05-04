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

void	display_textures(t_data *data, t_mlx_data *mlx_data)
{
	int i;
	int j;
	int width;
	int height;
	void *img_ptr;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if(data->map[i][j] == '1')
				img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "./textures/wall.XPM", &width, &height);
			else if (data->map[i][j] == '0')
				img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "./textures/empty.XPM", &width, &height);
			else if (data->map[i][j] == 'E')
				img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "./textures/empty.XPM", &width, &height);
			else if (data->map[i][j] == 'P')
				img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "./textures/player.XPM", &width, &height);
			else if (data->map[i][j] == 'C')
				img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "./textures/collectible.XPM", &width, &height);
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, img_ptr, j * 50, i * 50);
		}
	}
}

int	key_hook(int keycode, t_mlx_data *mlx_data)
{
	// if (keycode == UP_KEY)
	printf("%d\n", keycode);
	return (0);
}

int	close_window(int keycode, t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	exit(EXIT_SUCCESS);	
	return (0);
}


void	display(t_data *data)
{
	t_mlx_data	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	mlx_data.mlx_ptr = mlx_init();
	mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, data->width *50, data->height * 50, "so_long");
	mlx_data.img = mlx_new_image(mlx_data.mlx_ptr, data->width *50, data->width *50);
	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel,
		&mlx_data.line_length, &mlx_data.endian);
	display_textures(data, &mlx_data);
	mlx_hook(mlx_data.win_ptr, 2, 1L<<0, key_hook, &mlx_data);
	mlx_hook(mlx_data.win_ptr, 17, 1L<<17, close_window, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}
