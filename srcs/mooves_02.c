/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:55:17 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 13:01:53 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_stack **stack, t_mooves **mvs, int w_stack)
{
	if ((*stack)->head)
	{
		if ((*stack)->head->next)
			(*stack)->head = (*stack)->head->next;
	}
	if (w_stack == STACK_A)
		add_moove(mvs, ROT_A);
	else if (w_stack == STACK_B)
		add_moove(mvs, ROT_B);
}

void		rrotate(t_stack **stack, t_mooves **mvs, int w_stack)
{
	if ((*stack)->head)
	{
		if ((*stack)->head->prev)
			(*stack)->head = (*stack)->head->prev;
	}
	if (w_stack == STACK_A)
		add_moove(mvs, RROT_A);
	else if (w_stack == STACK_B)
		add_moove(mvs, RROT_B);
}

void		swap_ab(t_stack *stack_a, t_stack *stack_b, t_mooves **mvs)
{
	swap(stack_a, mvs, STACK_AB);
	swap(stack_b, mvs, STACK_AB);
	add_moove(mvs, STACK_AB);
}

void		rotate_ab(t_stack *stack_a, t_stack *stack_b, t_mooves **mvs)
{
	rotate(&stack_a, mvs, STACK_AB);
	rotate(&stack_b, mvs, STACK_AB);
	add_moove(mvs, R_AB);
}

void		rrotate_ab(t_stack *stack_a, t_stack *stack_b, t_mooves **mvs)
{
	rrotate(&stack_a, mvs, STACK_AB);
	rrotate(&stack_b, mvs, STACK_AB);
	add_moove(mvs, RR_AB);
}
