/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:14:12 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 16:02:06 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	**stack_a;
	int	**stack_b;

	if (argc > 1)
	{
		stack_a = ft_stack_a(--argc, ++argv);
		stack_b = ft_stack_b(stack_a);
		ft_algorithm(stack_a, stack_b);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
