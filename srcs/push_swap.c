/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:29:19 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:42:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			sort_two(t_data *data)
{
	if (!is_sorted(data->a))
	{
		swap(data->a, &data->mvs, STACK_A);
	}
	return (0);
}

int					push_swap(t_data *data)
{
	if (data->flags->step_by_step && !is_sorted(data->a))
		print_stacks(data);
	else if (data->flags->print_stacks && !is_sorted(data->a))
		print_w_stack(data->a, 'a', data->flags->colors);
	if (data->a->len == 2)
		sort_two(data);
	else if (data->a->len == 3)
		sort_three(data);
	else if (is_swapped(data->a))
		sort_smart(data);
	else if (is_rev_sorted(data->a))
		sort_select(data);
	else
		sort_split_select(data);
	return (print_result(data));
}
