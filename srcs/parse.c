/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:22:00 by lfabbro           #+#    #+#             */
/*   Updated: 2016/04/17 17:58:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			g_flag(t_flags *f, char *arg)
{
	if (arg[1] == 'c')
	{
		f->colors = 1;
		return (1);
	}
	else if (arg[1] == 'v')
	{
		f->step_by_step = 1;
		return (1);
	}
	else if (arg[1] == 's')
	{
		f->print_stacks = 1;
		return (1);
	}
	else if (arg[1] == 'm')
	{
		f->mooves = 1;
		return (1);
	}
	return (0);
}

static int			which_flag(t_flags *f, char **argv, int i)
{
	int		k;

	k = 0;
	if (ft_isnbr(argv[i]))
		return (IS_NBR);
	else if (argv[i] && argv[i][k++] == '-')
	{
		if (ft_strlen(argv[i]) == 2)
		{
			if (g_flag(f, argv[i]))
				return (0);
			else if (argv[i][k] == 'f')
			{
				f->read_from_file = 1;
				f->filename = argv[++i];
				return (check_filename(argv[i]));
			}
			return (-1);
		}
		return (-1);
	}
	return (-1);
}

t_flags				*ps_parse_flags(int argc, char **argv)
{
	t_flags		*f;
	int			ret;
	int			i;

	ret = argc;
	i = 0;
	if ((f = new_flags()) == NULL)
		malloc_error();
	while (ret != IS_NBR && argv[++i])
	{
		if ((ret = which_flag(f, argv, i)) == -1)
			return (NULL);
		else if (ret == 10)
			++i;
	}
	return (f);
}

t_stack				*ps_parse_stack(t_data *data, int argc, char **argv)
{
	t_stack		*a;

	a = NULL;
	if (data->flags->read_from_file)
	{
		if ((a = stack_from_file(data->flags->filename)) == NULL)
			return (NULL);
	}
	else if ((a = stack_from_args(argc, argv)) == NULL)
		return (NULL);
	return (a);
}
