/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 13:30:29 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:04:12 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int				list_min(t_stack *stack)
{
	t_link	*ptr;
	int		min;

	min = stack->head->n;
	ptr = stack->head->next;
	while (ptr && ptr->n != stack->head->n)
	{
		if (ptr->n < min)
			min = ptr->n;
		ptr = ptr->next;
	}
	return (min);
}

int				list_max(t_stack *stack)
{
	t_link	*ptr;
	int		max;

	max = stack->head->n;
	ptr = stack->head->next;
	while (ptr && ptr->n != stack->head->n)
	{
		if (ptr->n > max)
			max = ptr->n;
		ptr = ptr->next;
	}
	return (max);
}
