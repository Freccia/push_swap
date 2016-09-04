/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_moove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:06:07 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 13:27:09 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Functions used to print right moove, in color if colors
*/

static void		which_moove_three(int mv, int colors)
{
	if (mv == RROT_A)
	{
		if (colors)
			write(1, &YELLOW, ft_strlen(RED));
		ft_printf("rra");
	}
	else if (mv == RROT_B)
	{
		if (colors)
			write(1, &YELLOW, ft_strlen(RED));
		ft_printf("rrb");
	}
	else if (mv == R_AB)
	{
		if (colors)
			write(1, &GREEN, ft_strlen(RED));
		ft_printf("rr");
	}
	else if (mv == RR_AB)
	{
		if (colors)
			write(1, &GREEN, ft_strlen(RED));
		ft_printf("rrr");
	}
}

static void		which_moove_two(int mv, int colors)
{
	if (mv == PUSH_B)
	{
		if (colors)
			write(1, &CYAN, ft_strlen(RED));
		ft_printf("pb");
	}
	else if (mv == ROT_A)
	{
		if (colors)
			write(1, &MAGENTA, ft_strlen(RED));
		ft_printf("ra");
	}
	else if (mv == ROT_B)
	{
		if (colors)
			write(1, &BLUE, ft_strlen(RED));
		ft_printf("rb");
	}
	else
		which_moove_three(mv, colors);
}

void			which_moove(int mv, int colors)
{
	if (mv == SWAP_A)
	{
		if (colors)
			write(1, &RED, ft_strlen(RED));
		ft_printf("sa");
	}
	else if (mv == SWAP_B)
	{
		if (colors)
			write(1, &CYAN, ft_strlen(RED));
		ft_printf("sb");
	}
	else if (mv == PUSH_A)
	{
		if (colors)
			write(1, &GREEN, ft_strlen(RED));
		ft_printf("pa");
	}
	else
		which_moove_two(mv, colors);
	write(1, &STOP, ft_strlen(STOP));
}
