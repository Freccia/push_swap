/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:58:41 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 15:58:37 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_doubles(t_stack *a)
{
	t_link		*ptr_i;
	t_link		*ptr_j;
	int			lenght_i;
	int			lenght_j;

	ptr_i = a->head;
	ptr_j = NULL;
	lenght_i = a->len;
	while (--lenght_i)
	{
		ptr_j = ptr_i->next;
		lenght_j = lenght_i;
		while (lenght_j--)
		{
			if (ptr_j->n == ptr_i->n)
				return (1);
			ptr_j = ptr_j->next;
		}
		ptr_i = ptr_i->next;
	}
	return (0);
}

static int			get_data(t_stack **stack, char **splitt)
{
	t_link		*ptr;
	int			i;
	int			ll;

	i = 0;
	ll = 0;
	if ((*stack)->head == NULL)
	{
		if (check_arg(splitt[i]))
			return (-1);
		(*stack)->head = new_link(ft_atoi(splitt[i++]), NULL);
		++ll;
	}
	ptr = last_link(*stack);
	while (splitt[i])
	{
		if (check_arg(splitt[i]))
			return (-1);
		ptr->next = new_link(ft_atoi(splitt[i++]), ptr);
		ptr = ptr->next;
		++ll;
	}
	(*stack)->head->prev = ptr;
	ptr->next = (*stack)->head;
	return (ll);
}

static t_stack		*parse_file(int fd)
{
	t_stack		*a;
	char		*line;
	char		**splitt;
	int			ll;
	int			ret;

	ll = 0;
	a = new_stack();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		splitt = ft_strsplit(line, ' ');
		if ((ll = get_data(&a, splitt)) < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		a->len += ll;
		free_splitt(splitt);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	if (ret < 0)
		return (NULL);
	return (a);
}

t_stack				*stack_from_file(char *filename)
{
	t_stack		*a;
	int			fd;

	a = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((a = parse_file(fd)) == NULL)
		return (NULL);
	if (close(fd) < 0)
		return (NULL);
	if (check_doubles(a))
		return (NULL);
	return (a);
}
