/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:18:38 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:38:16 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link				*new_link(long const n, t_link *prev)
{
	t_link		*new_link;

	if ((new_link = (t_link*)malloc(sizeof(t_link))) == NULL)
		malloc_error();
	new_link->n = n;
	new_link->next = NULL;
	if (prev == NULL)
		new_link->prev = new_link;
	else
		new_link->prev = prev;
	return (new_link);
}

t_flags				*new_flags(void)
{
	t_flags		*f;

	if ((f = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	f->colors = 0;
	f->step_by_step = 0;
	f->print_stacks = 0;
	f->mooves = 0;
	f->read_from_file = 0;
	f->filename = NULL;
	return (f);
}

t_stack				*new_stack(void)
{
	t_stack		*stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->len = 0;
	stack->head = NULL;
	return (stack);
}

t_mooves			*new_mooves(long n)
{
	t_mooves	*mvs;

	if ((mvs = (t_mooves*)malloc(sizeof(t_mooves))) == NULL)
		return (NULL);
	mvs->nb = 1;
	mvs->head = new_link(n, NULL);
	mvs->queque = mvs->head;
	return (mvs);
}

t_data				*new_data(void)
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->flags = NULL;
	data->a = NULL;
	data->b = new_stack();
	data->mvs = NULL;
	return (data);
}
