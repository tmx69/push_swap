/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:22 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/11 15:34:06 by rywisozk         ###   ########.fr       */
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

void	duplicates(t_stacka *sa)
{
	int i;
	t_stacka *end;
	i = sa->a;
	while (sa->prev)
	{
		end = sa;
		while (end->prev)
		{
			if (sa->a == end->prev->a)
				ft_error();
			end = end->prev;
		}
		sa = sa->prev;
	}
}

int main(int ac, char **av)
{
	t_stacka	*sa;
	t_stacka	*head;
	int 		i;
	int 		j;

	i = 1;
	sa = ft_listnew();
	j = 0;
	head = sa;
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
		sa->a = ft_atoi(av[i]);
		if (i != ac - 1)
			sa = ft_listadd(sa);
		i++;
	}
	duplicates(sa);
	srot(head);
	// ft_check(sa);
	// while (sa != NULL)
	// {
	// 	printf("%d", sa->a);
	// 	printf("\n");
	// 	sa = sa->prev;
	// }
	return (0);
}