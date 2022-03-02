/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:42:38 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/11 09:57:16 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_prepare(int **stack_b, int **stack_a, int iter);

int	**ft_stack_b(int **stack_a)
{
	int	**stack_b;
	int	iter;

	iter = 0;
	stack_b = malloc(sizeof(int *) * 2);
	if (!stack_b)
	{
		ft_free_stack(stack_a);
		ft_printerror();
	}
	while (iter < 2)
	{
		stack_b[iter] = malloc(sizeof(int) * stack_a[0][0]);
		if (!stack_b[iter])
			ft_free_prepare(stack_b, stack_a, iter);
		iter++;
	}
	stack_b[0][0] = 0;
	return (stack_b);
}

static void	ft_free_prepare(int **stack_b, int **stack_a, int iter)
{
	int	free_iter;

	free_iter = 0;
	while (free_iter <= iter)
	{
		free(stack_b[iter]);
		iter++;
	}
	free(stack_b);
	ft_free_stack(stack_a);
}
