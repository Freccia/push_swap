/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:15:44 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 12:31:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					stack_lenght(t_stack *stack)
{
	t_link	*ptr;
	int		lenght;
	int		head_nbr;

	lenght = 0;
	ptr = stack->head;
	head_nbr = stack->head->n;
	if (ptr)
	{
		while (ptr)
		{
			ptr = ptr->next;
			++lenght;
			if (ptr->n == head_nbr)
				break ;
		}
	}
	return (lenght);
}

int					is_empty(t_stack *stack)
{
	if (stack->head != NULL)
		return (0);
	return (1);
}

int					is_rev_sorted(t_stack *stack)
{
	t_link		*ptr;
	int			head_nbr;

	ptr = stack->head;
	if (stack->head != NULL)
	{
		head_nbr = stack->head->n;
		if (ptr->next->n == ptr->n)
			return (0);
		while (ptr->next->n != head_nbr)
		{
			if (ptr->n < ptr->next->n)
				return (0);
			ptr = ptr->next;
		}
		return (1);
	}
	return (0);
}

int					is_sorted(t_stack *stack)
{
	t_link		*ptr;
	int			head_nbr;

	ptr = stack->head;
	if (stack->head != NULL)
	{
		head_nbr = stack->head->n;
		if (ptr->next->n == ptr->n)
			return (1);
		while (ptr->next->n != head_nbr)
		{
			if (ptr->n > ptr->next->n)
				return (0);
			ptr = ptr->next;
		}
		return (1);
	}
	return (0);
}
