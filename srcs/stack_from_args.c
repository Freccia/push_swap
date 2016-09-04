/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_from_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:56:50 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/13 20:08:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack				*stack_from_args(int argc, char **argv)
{
	t_stack		*a;
	t_link		*ptr;
	int			skip;

	skip = 1;
	if ((a = new_stack()) == NULL)
		malloc_error();
	while (argv[skip] && !ft_isnbr(argv[skip]) && skip < argc)
		++skip;
	if (skip >= argc)
		return (NULL);
	if (check_list_args(argc, argv, skip))
		return (NULL);
	a->head = new_link(ft_atoi(argv[skip]), NULL);
	++a->len;
	ptr = a->head;
	while (skip < (argc - 1))
	{
		ptr->next = new_link(ft_atoi(argv[++skip]), ptr);
		ptr = ptr->next;
		++a->len;
	}
	a->head->prev = ptr;
	ptr->next = a->head;
	return (a);
}
