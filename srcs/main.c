/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 20:01:09 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:50:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int argc, char **argv)
{
	t_data		*data;

	data = new_data();
	if (argc >= 2)
	{
		if ((data->flags = ps_parse_flags(argc, argv)) == NULL)
			return (usage_error());
		if ((data->a = ps_parse_stack(data, argc, argv)) == NULL)
			return (list_error());
		push_swap(data);
	}
	else
		return (usage_error());
	return (0);
}
