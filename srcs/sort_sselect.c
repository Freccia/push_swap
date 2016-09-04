/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sselect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 15:06:17 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:58:52 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void			rotate_and_push(t_data *data, int nbr)
{
	while (data->b->head->n != nbr)
	{
		rotate_and_print(data, STACK_B);
	}
	push_and_print(data, STACK_A);
}

static void			rrotate_and_push(t_data *data, int nbr)
{
	while (data->b->head->n != nbr)
	{
		rrotate_and_print(data, STACK_B);
	}
	push_and_print(data, STACK_A);
}

static int			locate_nbr(t_stack *stack, int nbr)
{
	t_link		*ptr;
	int			mid;
	int			i;

	ptr = stack->head;
	mid = stack->len / 2;
	i = 0;
	while (ptr->n != nbr)
	{
		++i;
		ptr = ptr->next;
	}
	if (i < mid)
		return (BEFORE_MID);
	return (AFTER_MID);
}

int					sort_sselect(t_data *data)
{
	int		max;
	int		mv;

	while (!is_empty(data->b))
	{
		max = list_max(data->b);
		mv = locate_nbr(data->b, max);
		if (mv == BEFORE_MID)
			rotate_and_push(data, max);
		else
			rrotate_and_push(data, max);
	}
	return (0);
}
