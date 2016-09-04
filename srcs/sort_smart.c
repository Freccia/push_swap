/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:20:50 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 13:12:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		one(t_data *data)
{
	swap(data->a, &data->mvs, STACK_A);
	return (0);
}

static int		two(t_data *data)
{
	rrotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	rrotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	swap(data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	rotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	rotate(&data->a, &data->mvs, STACK_A);
	return (0);
}

static int		three(t_data *data)
{
	rrotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	swap(data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	rotate(&data->a, &data->mvs, STACK_A);
	return (0);
}

static int		four(t_data *data)
{
	rotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	swap(data->a, &data->mvs, STACK_A);
	return (0);
}

int				sort_smart(t_data *data)
{
	int		ret;

	if ((ret = is_swapped(data->a)) == 1)
		return (one(data));
	else if (ret == 2)
		return (two(data));
	else if (ret == 3)
		return (three(data));
	else if (ret == 4)
		return (four(data));
	return (0);
}
