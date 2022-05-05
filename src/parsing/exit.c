/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:29:28 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/05 19:29:32 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	*str = NULL;
	if (str)
		free(str);
}

void	free_all(t_data *data)
{
	if (data->map)
		free_array(data->map);
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
	if (data->empty_img)
		mlx_destroy_image(data->mlx_ptr, data->empty_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
	if (data->collect_img)
		mlx_destroy_image(data->mlx_ptr, data->collect_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

int	print_error(char *error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	print_error_free(t_data *data, char *error)
{
	free_all(data);
	print_error(error);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}
