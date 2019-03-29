/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:44:22 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/23 15:56:50 by rywisozk         ###   ########.fr       */
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

// void	str_check(char *av)
// {
// 	int j;

// 	j = 0;
// 	while (av[j])
// 	{
// 		if (ft_isdigit(av[j]) == 0 && av[j] != ' ')
// 		{
// 			if (!(av[j] == 45 && av[j + 1] > 47
// 				&& av[j + 1] < 58))
// 				ft_error();
// 		}
// 		j++;
// 	}
// }

// void	str_arg(t_stack *a, char *av)
// {
// 	int j;
// 	int c;
// 	int	minus;
// 	int flagg;

// 	minus = 0;
// 	j = -1;
// 	c = 0;
// 	flagg = 0;
// 	while (av[++j])
// 	{
// 		if (ft_isdigit(av[j]) == 1)
// 		{
// 			c = c * 10 + (av[j] - '0');
// 			if ((av[j + 1] == ' ') || (av[j + 1] == '\0'))
// 			{
// 				flagg == 1 ? a = ft_listadd(a) : 0;
// 				minus == 1 ? (c = c * -1) && minus-- : 0;
// 				a->value = c;
// 				c = 0;
// 				flagg == 0 ? flagg++ : 0;
// 			}
// 		}
// 		av[j] == 45 ? minus = 1 : 0;
// 	}
// }

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
	srot(head);
	return (0);
}
