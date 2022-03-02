/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:36:38 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 10:11:18 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_pab(int **stack_1, int **stack_2);

void	ft_px(int **stack_a, int **stack_b, int flag)
{
	if (flag == 'a')
	{
		ft_pab(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
	if (flag == 'b')
	{
		ft_pab(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}
}

static void	ft_pab(int **stack_1, int **stack_2)
{
	int	iter_1;
	int	iter_2;

	iter_1 = stack_2[0][0];
	iter_2 = iter_1 - 1;
	if (stack_1[0][0] >= 1)
	{
		if (stack_2[0][0] == 1)
			stack_2[1][1] = stack_2[1][0];
		if (stack_2[0][0] > 1)
		{
			while (iter_2 >= 0)
			{
				stack_2[1][iter_1] = stack_2[1][iter_2];
				iter_1--;
				iter_2--;
			}
		}
		stack_2[1][0] = stack_1[1][0];
		stack_2[0][0]++;
		ft_rab(stack_1);
		stack_1[0][0]--;
	}
}
