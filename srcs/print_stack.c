/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 01:44:17 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 01:49:41 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void			print_w_stack(t_stack *stack, char c, int colors)
{
	ft_printf("Stack %c:\n", c);
	print_stack(stack, colors, 'a');
	ft_printf("------------------------------------------\n");
}

static void		colo_r(int colors, char c)
{
	if (colors)
	{
		if (c == 'a')
			write(1, &RED, ft_strlen(RED));
		else if (c == 'b')
			write(1, &BLUE, ft_strlen(BLUE));
	}
}

void			print_stack(t_stack *stack, int colors, char c)
{
	t_link	*ptr;
	int		head_nbr;

	if (stack)
	{
		ptr = stack->head;
		if (ptr)
		{
			colo_r(colors, c);
			head_nbr = stack->head->n;
			while (ptr)
			{
				ft_printf("%d ", ptr->n);
				ptr = ptr->next;
				if (ptr->n == head_nbr)
					break ;
			}
			if (colors)
				write(1, &STOP, ft_strlen(STOP));
		}
	}
	ft_printf("\n");
}
