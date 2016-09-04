/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:22:16 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:54:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_filename(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (filename_error());
	if (close(fd) < 0)
		return (close_error());
	return (10);
}
