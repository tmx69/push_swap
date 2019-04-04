/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:33:03 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/04 18:52:25 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/_types.h>
#include <sys/stat.h>
#include <stdlib.h>

void	duplicate(t_stack *a)
{
	t_stack *end;

	while (a->prev)
	{
		end = a;
		while (end->prev)
		{
			if (a->value == end->prev->value)
				ft_error();
			end = end->prev;
		}
		a = a->prev;
	}
	while (a->next)
	{
		end = a;
		while (end->next)
		{
			a->value == end->next->value ? ft_error() : 0;
			end = end->next;
		}
		a = a->next;
	}
	if (a->prev == NULL)
		exit(0);
}

void	ft_search(char *arr, t_stack *a)
{
	char	**s;
	int		i;
	int		j;
	t_stack	*b;

	b = NULL;
	i = 0;
	s = ft_strsplit(arr, '\n');
	free(arr);
	while (s[i])
	{
		if (!a && ft_strcmp(s[i], "pa") == 0 && b)
			a = ft_listnew();
		else if (a && ft_strcmp(s[i], "pa") == 0 && b)
			a = ft_listadd_start(a);
		ft_oper_check(s[i], a, &b);
		if (a)
		{
			while (a->prev != NULL)
				a = a->prev;
		}
		ft_strcmp(s[i], "pb") == 0 && a ? a = del(a->value, &a) : 0;
		i++;
	}
	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	b ? ft_error() : ft_check(a);
}
