/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:24:45 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 01:01:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_arg(char *arg)
{
	long	argll;
	int		i;

	i = 0;
	argll = ft_atoll(arg);
	if (ft_strlen(arg) == 0 || ft_strlen(arg) > 11)
		return (1);
	if (!(argll >= INT_MIN && argll <= INT_MAX))
		return (1);
	while (arg[i] && (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\t'))
		++i;
	if (arg[i] == '-' || arg[i] == '+')
	{
		++i;
		while (arg[i] == ' ' || arg[i] == '\n' || arg[i] == '\t')
			++i;
		if (arg[i] >= '0' && arg[i] <= '9')
			return (0);
		else
			return (1);
	}
	else if (!(arg[i] >= '0' && arg[i] <= '9'))
		return (1);
	return (0);
}

static int			check_doubles(int argc, int *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = (i + 1);
		while (j < argc)
		{
			if (list[i] == list[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static int			check_args_validity(int argc, char **argv, int skip,
		int *list)
{
	int		i;
	int		j;

	i = skip;
	j = 0;
	while (i < argc)
	{
		if (check_arg(argv[i]))
			return (1);
		list[j] = ft_atoi(argv[i]);
		++i;
		++j;
	}
	return (0);
}

int					check_list_args(int argc, char **argv, int skip)
{
	int		*list;

	if ((list = (int*)malloc(sizeof(int) * argc)) == NULL)
		malloc_error();
	if (check_args_validity(argc, argv, skip, list))
		return (1);
	if (check_doubles((argc - skip), list))
		return (1);
	free(list);
	return (0);
}
