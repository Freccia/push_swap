/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:16:08 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:55:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			usage_error(void)
{
	ft_printf("Error.\n");
	ft_printf("Usage: ./push_swap [flags] [[-f filename] ||  [args ...]]\n");
	ft_printf("Flags:\n");
	ft_printf("	-c colors	ON\n");
	ft_printf("	-m print mooves	ON\n");
	ft_printf("	-v step by step	ON\n");
	ft_printf("	-s print_stacks	ON\n");
	ft_printf("	-f [filename]\n");
	return (-1);
}

int			flag_error(void)
{
	ft_printf("Wrong flag.\n");
	return (usage_error());
}

int			filename_error(void)
{
	ft_printf("Wrong filename.\n");
	return (-1);
}

int			close_error(void)
{
	ft_printf("Failed closing file.\n");
	return (-1);
}

int			malloc_error(void)
{
	ft_printf("Failed to malloc. Stop.\n");
	exit(1);
}
