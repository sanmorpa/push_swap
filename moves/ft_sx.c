/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:35:19 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 10:12:06 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sab(int **stack);

void	ft_sx(int **stack_a, int **stack_b, int flag)
{
	if (flag == 'a')
	{
		ft_sab(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (flag == 'b')
	{
		ft_sab(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	if (flag == 's')
	{
		ft_sab(stack_a);
		ft_sab(stack_b);
		ft_putstr_fd("ss\n", 1);
	}
}

static void	ft_sab(int **stack)
{
	int	temporal;

	if (stack[0][0] >= 2)
	{
		temporal = stack[1][0];
		stack[1][0] = stack[1][1];
		stack[1][1] = temporal;
	}
}
