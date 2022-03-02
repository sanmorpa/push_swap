/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:02:19 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/10 10:02:19 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**ft_intarray(int argc, int argcopy, char **args);
static void	free_in_arr(int argcopy, char **args, int array_flag, int **intar);
static void	ft_map(int **stack);

int	**ft_stack_a(int argc, char **args)
{
	int	**array;
	int	argc_copy;

	argc_copy = argc;
	if (argc == 1)
	{
		args = ft_split(args[0], ' ');
		if (!args)
			ft_printerror();
		argc = ft_count_split(args);
		if (argc == 0)
		{
			ft_free_split(args, ft_count_split(args));
			ft_printerror();
		}
	}
	ft_errors(argc, args, argc_copy);
	array = ft_intarray(argc, argc_copy, args);
	if (argc_copy == 1)
		ft_free_split(args, ft_count_split(args) + 1);
	ft_map(array);
	return (array);
}

static int	**ft_intarray(int argc, int argcopy, char **args)
{
	int		**intarray;
	int		iter;
	int		mall_iter;

	iter = 0;
	mall_iter = 0;
	intarray = malloc(sizeof(int *) * 2);
	if (!intarray)
		free_in_arr(argcopy, args, -1, intarray);
	while (mall_iter < 2)
	{
		intarray[mall_iter] = malloc(sizeof(int) * argc);
		if (!intarray[mall_iter])
			free_in_arr(argcopy, args, mall_iter, intarray);
		mall_iter++;
	}
	intarray[0][0] = argc;
	while (iter < argc)
	{
		intarray[1][iter] = ft_atoi(args[iter]);
		iter++;
	}
	return (intarray);
}

static void	ft_map(int **stack)
{
	int	iter;
	int	pos_change;
	int	*copy_stack;

	iter = 0;
	copy_stack = malloc(sizeof(int) * stack[0][0]);
	if (!copy_stack)
	{
		ft_free_stack(stack);
		ft_printerror();
	}
	while (iter < stack[0][0])
	{
		pos_change = ft_find_pos(stack, iter);
		copy_stack[pos_change] = iter;
		iter++;
	}
	iter = 0;
	while (iter < stack[0][0])
	{
		stack[1][iter] = copy_stack[iter];
		iter++;
	}
	free(copy_stack);
}

static void	free_in_arr(int argcopy, char **args, int array_flag, int **intar)
{
	int	iter;

	iter = 0;
	if (array_flag >= 0)
	{
		while (iter <= array_flag)
		{
			free(intar[iter]);
			iter++;
		}
		free(intar);
	}
	if (argcopy == 1)
		ft_free_split(args, ft_count_split(args) + 1);
	ft_printerror();
}
