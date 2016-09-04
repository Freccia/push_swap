/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_split_select_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 12:21:58 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:52:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int			find_median(t_stack *stack)
{
	t_link	*ptr;
	int		median;
	int		tot;
	int		len_cpy;
	int		min;
	int		max;

	ptr = stack->head;
	len_cpy = stack->len;
	tot = 0;
	while (len_cpy--)
	{
		tot += ptr->n;
		ptr = ptr->next;
	}
	min = list_min(stack);
	max = list_max(stack);
	median = tot / stack->len;
	return (median);
}

static int			split(t_data *data)
{
	int		median;
	int		len_cpy;
	int		last;

	if (!is_empty(data->a))
	{
		median = find_median(data->a);
		len_cpy = data->a->len;
		last = data->a->head->prev->n;
		while (data->a->head->n != last && --len_cpy)
		{
			if (data->a->head->n <= median)
				push_and_print(data, STACK_B);
			else
				rotate_and_print(data, STACK_A);
		}
		if (data->a->head->n <= median)
			push_and_print(data, STACK_B);
		if (is_sorted(data->a))
			return (0);
		return (1);
	}
	return (0);
}

int					sort_split_select(t_data *data)
{
	while (split(data))
		;
	sort_sselect(data);
	return (0);
}
