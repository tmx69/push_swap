/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:22 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/18 12:34:03 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void ft_error()
{
	write(1,"ERROR\n", 6);
	exit(0);
}

void	duplicates(t_stack *a)
{
	int i;
	t_stack *end;
	i = a->value;
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

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*head;
	int		i;
	int		j;

	i = 1;
	a = ft_listnew();
	j = 0;
	head = a;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				if (av[i][j] == 45 && av[i][j + 1] > 47 && av[i][j + 1] < 58 && j == 0)
				{

				}
				else
					ft_error();
			}
			j++;
		}
		a->value = ft_atoi(av[i]);
		if (i != ac - 1)
			a = ft_listadd(a);
		i++;
	}
	duplicates(a);
	srot(head);
	// ft_check(a);
	// while (a != NULL)
	// {
	// 	printf("%d", a->a);
	// 	printf("\n");
	// 	a = a->prev;
	// }
	return (0);
}