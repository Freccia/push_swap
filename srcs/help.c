/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:55:01 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 01:43:37 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				free_splitt(char **splitt)
{
	int	i;

	i = 0;
	while (splitt[i])
	{
		free(splitt[i]);
		++i;
	}
	free(splitt);
}

t_link				*last_link(t_stack *stack)
{
	t_link		*ptr;

	ptr = stack->head;
	while (ptr->next && ptr->next->n != stack->head->n)
		ptr = ptr->next;
	return (ptr);
}

int					set_min(t_stack *stack, int *pos)
{
	t_link	*ptr;
	int		min;
	int		mid;
	int		i;
	int		j;

	ptr = stack->head;
	mid = stack->len / 2;
	*pos = BEFORE_MID;
	i = 0;
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
		if (ptr->n == stack->head->n)
			break ;
		++i;
	}
	return (min);
}

void				add_moove(t_mooves **mooves, int mv)
{
	t_link		*ptr;

	if ((*mooves))
	{
		ptr = (*mooves)->queque;
		ptr->next = new_link(mv, ptr);
		(*mooves)->queque = ptr->next;
		++(*mooves)->nb;
	}
	else
		(*mooves) = new_mooves(mv);
}

int					pop(t_stack **stack)
{
	t_link		*ptr;
	t_link		*ptr_next;
	t_link		*ptr_prev;

	ptr = (*stack)->head;
	if (ptr)
	{
		if ((*stack)->head->next->n != (*stack)->head->n)
		{
			ptr_next = (*stack)->head->next;
			ptr_prev = (*stack)->head->prev;
			free(ptr);
			(*stack)->head = ptr_next;
			(*stack)->head->prev = ptr_prev;
			(*stack)->head->prev->next = ptr_next;
		}
		else
		{
			free((*stack)->head);
			(*stack)->head = NULL;
		}
	}
	return (1);
}
