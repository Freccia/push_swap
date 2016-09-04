/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:33:10 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:42:24 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_mooves(t_mooves *mooves, int colors)
{
	t_link	*ptr;

	ptr = mooves->head;
	if (ptr)
	{
		while (ptr)
		{
			which_moove(ptr->n, colors);
			if (ptr->next)
				ft_printf(" ");
			ptr = ptr->next;
		}
	}
	ft_printf("\n");
}

int				print_stacks(t_data *data)
{
	ft_printf("------------------------------------------\n");
	ft_printf("Stack a:\n");
	print_stack(data->a, data->flags->colors, 'a');
	ft_printf("Stack b:\n");
	print_stack(data->b, data->flags->colors, 'b');
	if (data->mvs)
		ft_printf("Number of mooves: %d\n", data->mvs->nb);
	else
		ft_printf("Number of mooves: 0\n");
	if (data->flags->mooves)
	{
		ft_printf("Mooves: ");
		if (data->mvs)
			print_mooves(data->mvs, data->flags->colors);
		else
			ft_putchar('\n');
	}
	ft_printf("------------------------------------------\n");
	ft_printf("Press ENTER\n");
	ft_getchar();
	return (0);
}

int				print_result(t_data *data)
{
	if (data && (data->flags->print_stacks || data->flags->step_by_step))
	{
		ft_printf("Stack a:\n");
		print_stack(data->a, data->flags->colors, 'a');
		ft_printf("Stack b:\n");
		print_stack(data->b, data->flags->colors, 'b');
	}
	if (data->flags->mooves)
	{
		ft_printf("Mooves: ");
		if (data->mvs)
			print_mooves(data->mvs, data->flags->colors);
		else
			ft_printf("\n");
	}
	if (data->mvs)
		ft_printf("Number of mooves: %d\n", data->mvs->nb);
	else
		ft_printf("Number of mooves: 0\n");
	return (0);
}
