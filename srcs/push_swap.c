/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:22 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/04 20:20:42 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void	duplicates(t_stack *a)
{
	int		j;
	t_stack	*end;

	j = 0;
	while (a->next)
	{
		end = a;
		while (end->next)
		{
			if (a->value == end->next->value)
				ft_error();
			end = end->next;
		}
		a = a->next;
		j++;
	}
	if (j == 1)
	{
		a->prev->value > a->value ? write(1, "sa\n", 3) : 0;
		a->prev->value > a->value ? ft_sa(a) : 0;
		write(1, "ok", 2);
		exit(0);
	}
	if (a->prev == NULL)
		exit(0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*head;
	int		i;

	i = 1;
	a = ft_listnew();
	head = a;
	if (ac > 1)
	{
		while (av[i])
		{
			str_check(av[i]);
			str_arg(a, av[i]);
			i != ac - 1 ? a = ft_listadd(a) : 0;
			i++;
		}
	}
	duplicates(head);
	alg(a);
	srot(head);
	while (a->prev != NULL)
		a = a->prev;
	list_del(&a);
	return (0);
}
