/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_swapped.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:14:50 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 12:31:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			first_three_elem(t_stack *stack)
{
	t_link		*ptr;

	ptr = stack->head->next->next;
	while (ptr->next->n != stack->head->n)
	{
		if (ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static int			last_three_elem(t_stack *stack)
{
	t_link		*ptr;
	t_link		*last;

	ptr = stack->head;
	last = stack->head->prev->prev;
	while (ptr->next->n != last->n)
	{
		if (ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return (2);
}

static int			swap_first_last(t_stack *stack)
{
	t_link		*ptr;
	t_link		*last;

	ptr = stack->head->next;
	last = stack->head->prev;
	while (ptr->next->n != last->n)
	{
		if (ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return (3);
}

static int			last_is_second(t_stack *stack)
{
	t_link		*ptr;
	t_link		*last;

	ptr = stack->head;
	last = stack->head->prev;
	while (ptr->next->n != last->n)
	{
		if (ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return (4);
}

int					is_swapped(t_stack *stack)
{
	t_link		*ptr;
	t_link		*last;
	int			ret;

	ret = 0;
	ptr = stack->head;
	last = stack->head->prev;
	if (ptr)
	{
		if (ptr->n > ptr->next->n && ptr->n < ptr->next->next->n)
			return (first_three_elem(stack));
		else if (ptr->prev->n < ptr->prev->prev->n &&
				ptr->prev->n > ptr->prev->prev->prev->n)
			return (last_three_elem(stack));
		else if (ptr->prev->n < ptr->n && ptr->n > ptr->prev->prev->n)
			return (swap_first_last(stack));
		else if (ptr->prev->n > ptr->n && ptr->prev->n < ptr->next->n)
			return (last_is_second(stack));
	}
	return (0);
}
