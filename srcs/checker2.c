/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:33:03 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/23 15:50:37 by rywisozk         ###   ########.fr       */
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
	int i;
	t_stack *end;
	i = a->value;
	if (a->prev == NULL)
		exit(0);
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
}

void	ft_search(char *arr, t_stack *a)
{
	char	**s;
	int		i;
	t_stack	*b;
	t_stack *help;

	b = NULL;
	i = 0;
	s = ft_strsplit(arr, '\n');
	while (s[i])
	{
		ft_oper_check(s[i], a, &b);
		printf("%s", s[i]);
		help = a;
		while (help->prev)
			help = help->prev;
		while(help != NULL)
		{
			printf("|%d|", help->value );
			help = help->next;
		}
		printf("\n");
		i++;
	}
	if (b)
	{
	help = b;
	while (help->prev)
			help = help->prev;
	printf("___________");
		while(help->next)
		{
			printf("|%d|", help->value );
			help = help->next;
		}
		printf("\n");
	}
	ft_check(a);
}
