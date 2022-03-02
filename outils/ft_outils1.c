/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:04:29 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/10 12:04:29 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printerror(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	ft_free_stack(int **array)
{
	int	iter;

	iter = 0;
	while (iter < 2)
	{
		free(array[iter]);
		iter++;
	}
	free(array);
}

void	ft_free_split(char **array, int words)
{
	int	iter;

	iter = 0;
	while (iter < words)
	{
		free(array[iter]);
		iter++;
	}
	free(array);
}

int	ft_count_split(char **split)
{
	int	iter;

	iter = 0;
	while (split[iter])
		iter++;
	return (iter);
}

int	ft_check_order(int **stack)
{
	int	iter;
	int	seen;

	iter = 1;
	seen = stack[1][0];
	while (iter < stack[0][0])
	{
		if (seen > stack[1][iter])
			return (0);
		seen = stack[1][iter];
		iter++;
	}
	return (1);
}
