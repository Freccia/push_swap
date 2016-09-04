/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:29:51 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/14 12:48:55 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_linked(t_link *l)
{
	t_link	*ptr;
	t_link	*tmp;

	if (l)
	{
		ptr = l->next;
		tmp = l;
		while (ptr)
		{
			free(tmp);
			tmp = NULL;
			if (ptr)
			{
				tmp = ptr;
				ptr = ptr->next;
			}
		}
	}
	l = NULL;
}

void		free_flags(t_flags *f)
{
	if (f)
		free(f);
	f = NULL;
}

void		free_stack(t_stack *stack)
{
	if (stack)
	{
		free_linked(stack->head);
		stack->head = NULL;
		free(stack);
	}
	stack = NULL;
}

void		free_mooves(t_mooves *mvs)
{
	if (mvs)
	{
		free_linked(mvs->head);
		mvs->head = NULL;
		mvs->queque = NULL;
		free(mvs);
		mvs = NULL;
	}
}

void		free_data(t_data *data)
{
	if (data)
	{
		free_flags(data->flags);
		free_stack(data->a);
		free_stack(data->b);
		free_mooves(data->mvs);
		free(data);
	}
	data = NULL;
}
