/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:04:23 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:49:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void		push_and_print(t_data *data, int w_stack)
{
	push(data, w_stack);
	if (data->flags->step_by_step && !is_empty(data->b))
		  print_stacks(data);
}

void		swap_and_print(t_data *data, int w_stack)
{
	if (w_stack == STACK_A)
		swap(data->a, &data->mvs, w_stack);
	else
		swap(data->b, &data->mvs, w_stack);
	if (data->flags->step_by_step && !is_empty(data->b))
		  print_stacks(data);
}

void		rotate_and_print(t_data *data, int w_stack)
{
	if (w_stack == STACK_A)
		rotate(&data->a, &data->mvs, w_stack);
	else
		rotate(&data->b, &data->mvs, w_stack);
	if (data->flags->step_by_step && !is_empty(data->b))
		  print_stacks(data);
}

void		rrotate_and_print(t_data *data, int w_stack)
{
	if (w_stack == STACK_A)
		rrotate(&data->a, &data->mvs, w_stack);
	else
		rrotate(&data->b, &data->mvs, w_stack);
	if (data->flags->step_by_step && !is_empty(data->b))
		  print_stacks(data);
}

