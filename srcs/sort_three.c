/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:11:07 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 13:09:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		one(t_data *data)
{
	rrotate(&data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	swap(data->a, &data->mvs, STACK_A);
	return (0);
}

static int		two(t_data *data)
{
	t_link	*ptr;

	ptr = data->a->head;
	if (ptr->next->n > ptr->prev->n)
	{
		swap(data->a, &data->mvs, STACK_A);
		if (data->flags->step_by_step)
			print_stacks(data);
		rrotate(&data->a, &data->mvs, STACK_A);
	}
	else
		rotate(&data->a, &data->mvs, STACK_A);
	return (0);
}

static int		three(t_data *data)
{
	swap(data->a, &data->mvs, STACK_A);
	return (0);
}

static int		four(t_data *data)
{
	swap(data->a, &data->mvs, STACK_A);
	if (data->flags->step_by_step)
		print_stacks(data);
	rrotate(&data->a, &data->mvs, STACK_A);
	return (0);
}

int				sort_three(t_data *data)
{
	t_link	*ptr;

	ptr = data->a->head;
	if (!is_sorted(data->a))
	{
		if (ptr->n < ptr->next->n && ptr->n > ptr->prev->n)
			rrotate(&data->a, &data->mvs, STACK_A);
		else if (ptr->n < ptr->next->n && ptr->n < ptr->prev->n)
			return (one(data));
		else if (ptr->n > ptr->next->n && ptr->n > ptr->prev->n)
			return (two(data));
		else if (ptr->n > ptr->next->n && ptr->n < ptr->prev->n)
			return (three(data));
		else if (ptr->n < ptr->next->n && ptr->next->n > ptr->prev->n)
			return (four(data));
	}
	return (0);
}
