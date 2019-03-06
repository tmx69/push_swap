/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:22 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/06 15:21:34 by rywisozk         ###   ########.fr       */
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
	while (sa->prev)
	{
		if (sa->a == sa->prev->a)
			ft_error();
		sa = sa->prev;
	}
}

int main(int ac, char **av)
{
	t_stacka	*sa;
	int 		i;
	int 		j;

	i = 1;
	sa = ft_listnew();
	j = 0;
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
	// ft_check(sa);
	// while (sa != NULL)
	// {
	// 	printf("%d", sa->a);
	// 	printf("\n");
	// 	sa = sa->prev;
	// }
	return (0);
}