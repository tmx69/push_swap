/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:33:03 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/08 09:50:45 by rywisozk         ###   ########.fr       */
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
}

void	free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
}

void	ft_search(char *arr, t_stack *a)
{
	char	**s;
	int		i;
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
	free_array(s);
	b ? ft_error() : ft_check(a);
}
