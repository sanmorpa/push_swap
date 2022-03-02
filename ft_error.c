/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:29:01 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 12:30:38 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_only_int(int argcs, char **argvs);
static int	ft_outbounds(int argcs, char **argvs);
static int	ft_duplicate(int argcs, char **argvs);
static int	ft_not_void(int argcs, char **argvs);

void	ft_errors(int argcs, char **argvs, int argcopy)
{
	int	err_only;
	int	err_out;
	int	err_dup;
	int	err_len;

	err_len = ft_not_void(argcs, argvs);
	err_only = ft_only_int(argcs, argvs);
	err_out = ft_outbounds(argcs, argvs);
	err_dup = ft_duplicate(argcs, argvs);
	if (err_only == 1 || err_out == 1 || err_dup == 1 || err_len == 1)
	{
		if (argcopy == 1)
			ft_free_split(argvs, ft_count_split(argvs));
		ft_printerror();
	}
}

static int	ft_not_void(int argcs, char **argvs)
{
	int	arg;

	arg = 0;
	while (arg < argcs)
	{
		if (ft_strlen(argvs[arg]) == 0)
			return (1);
		arg++;
	}
	return (0);
}

static int	ft_only_int(int argcs, char **argvs)
{
	int	arg;
	int	iter_str;

	arg = 0;
	iter_str = 1;
	while (arg < argcs)
	{
		if (argvs[arg][0] != '-' && ft_isdigit(argvs[arg][0]) == 0)
			return (1);
		while (argvs[arg][iter_str])
		{
			if (ft_isdigit(argvs[arg][iter_str]) == 0)
				return (1);
			iter_str++;
		}
		arg++;
		iter_str = 1;
	}
	return (0);
}

static int	ft_outbounds(int argcs, char **argvs)
{
	int		arg;
	long	atoied;

	arg = 0;
	while (arg < argcs)
	{
		atoied = ft_atoi(argvs[arg]);
		if (atoied < -2147483648 || atoied > 2147483647)
			return (1);
		arg++;
	}
	return (0);
}

static int	ft_duplicate(int argcs, char **argvs)
{
	long	fetch;
	int		arg;
	int		iter;

	arg = 0;
	iter = arg + 1;
	while (arg < argcs)
	{
		fetch = ft_atoi(argvs[arg]);
		while (argvs[iter])
		{
			if (fetch == ft_atoi(argvs[iter]))
				return (1);
			iter++;
		}
		arg++;
		iter = arg + 1;
	}
	return (0);
}
