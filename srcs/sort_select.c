/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:59:48 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 16:41:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				push_all_in_a(t_data *data)
{
	while (!is_empty(data->b))
	{
		push(data, STACK_A);
		if (data->flags->step_by_step && !is_empty(data->b))
			print_stacks(data);
	}
}

static void				r_pop_min(t_data *data, int min)
{
	if (!is_empty(data->a))
	{
		while (data->a->head->n != min)
		{
			rotate(&data->a, &data->mvs, STACK_A);
			if (data->flags->step_by_step)
				print_stacks(data);
		}
		if (!is_sorted(data->a))
		{
			push(data, STACK_B);
			if (data->flags->step_by_step)
				print_stacks(data);
		}
	}
}

static void				rr_pop_min(t_data *data, int min)
{
	if (data->a->head != NULL)
	{
		while (data->a->head->n != min)
		{
			rrotate(&data->a, &data->mvs, STACK_A);
			if (data->flags->step_by_step)
				print_stacks(data);
		}
		if (!is_sorted(data->a))
		{
			push(data, STACK_B);
			if (data->flags->step_by_step)
				print_stacks(data);
		}
	}
}

static int				get_min(t_stack **stack, int mid, int *pos)
{
	t_link	*ptr;
	int		min;
	int		i;
	int		j;

	ptr = (*stack)->head;
	*pos = BEFORE_MID;
	i = 0;
	j = 0;
	min = ptr->n;
	while (ptr)
	{
		if (ptr->n < min)
		{
			min = ptr->n;
			j = i;
			*pos = (j > mid) ? AFTER_MID : *pos;
		}
		ptr = ptr->next;
		if (ptr->n == (*stack)->head->n)
			break ;
		++i;
	}
	return (min);
}

int						sort_select(t_data *data)
{
	int		min;
	int		pos;
	int		llen;
	int		lenght;

	pos = BEFORE_MID;
	llen = data->a->len;
	lenght = data->a->len;
	if (!is_sorted(data->a))
	{
		while (lenght-- && !is_sorted(data->a))
		{
			if (data->a->head != NULL)
			{
				min = get_min(&data->a, (llen / 2), &pos);
				if (pos == BEFORE_MID)
					r_pop_min(data, min);
				else
					rr_pop_min(data, min);
				--llen;
			}
		}
		push_all_in_a(data);
	}
	return (0);
}
