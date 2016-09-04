/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:55:49 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:19:16 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			push_two(t_stack **stack_push, t_stack **stack_pop)
{
	t_link	*new_head;

	new_head = NULL;
	if ((*stack_pop)->head)
	{
		if ((*stack_push)->head)
		{
			new_head = new_link((*stack_pop)->head->n,
					(*stack_push)->head->prev);
			new_head->next = (*stack_push)->head;
			(*stack_push)->head->prev->next = new_head;
		}
		else
		{
			new_head = new_link((*stack_pop)->head->n, NULL);
			new_head->next = new_head;
		}
		(*stack_push)->head = new_head;
		(*stack_push)->head->next->prev = (*stack_push)->head;
		pop(stack_pop);
	}
}

void				push(t_data *data, int w_stack)
{
	t_stack	**stack_push;
	t_stack **stack_pop;

	if (w_stack == STACK_A)
	{
		(stack_push = &data->a);
		(stack_pop = &data->b);
	}
	else
	{
		(stack_push = &data->b);
		(stack_pop = &data->a);
	}
	push_two(stack_push, stack_pop);
	--(*stack_pop)->len;
	++(*stack_push)->len;
	if (w_stack == STACK_A)
		add_moove(&data->mvs, PUSH_A);
	else if (w_stack == STACK_B)
		add_moove(&data->mvs, PUSH_B);
}

void				swap(t_stack *stack, t_mooves **mvs, int w_stack)
{
	int		tmp;

	tmp = stack->head->n;
	if (stack->head->next)
	{
		stack->head->n = stack->head->next->n;
		stack->head->next->n = tmp;
	}
	if (w_stack == STACK_A)
		add_moove(mvs, SWAP_A);
	else if (w_stack == STACK_B)
		add_moove(mvs, SWAP_B);
}
