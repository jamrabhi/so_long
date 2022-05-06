/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:05:57 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/05 21:06:02 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	render(t_data *data)
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
	return (0);
}

void	check_collectible(t_data *data, int x, int y)
{
	if (data->map[y][x] == COLLECT)
		data->collectible--;
}

void	check_exit(t_data *data, int x, int y)
{
	if (data->map[y][x] == EXIT && data->collectible == 0)
	{
		data->map[y][x] = PLAYER;
		data->player_pos_x = x;
		data->player_pos_y = y;
		ft_putnbr_fd(++data->move_count, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		close_window(data);
	}
}

void	move_player(t_data *data, int to_x, int to_y)
{
	if (data->map[to_y][to_x] != WALL)
	{
		check_collectible(data, to_x, to_y);
		check_exit(data, to_x, to_y);
		if (data->map[to_y][to_x] != EXIT)
		{
			data->map[data->player_pos_y][data->player_pos_x] = EMPTY;
			data->map[to_y][to_x] = PLAYER;
			data->player_pos_x = to_x;
			data->player_pos_y = to_y;
			ft_putnbr_fd(++data->move_count, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
	}
}
