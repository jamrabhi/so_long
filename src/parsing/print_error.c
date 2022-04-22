/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:27:51 by jamrabhi          #+#    #+#             */
/*   Updated: 2021/10/06 00:27:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	print_error(char *error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

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
