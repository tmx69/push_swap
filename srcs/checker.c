/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:26:36 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/27 10:17:52 by rywisozk         ###   ########.fr       */
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

void	ft_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void	opeartion_check(char *arr, t_stack *a, t_stack **b)
{
	if (ft_strcmp(arr, "sb") == 0)
		ft_sb(*b);
	else if (ft_strcmp(arr, "rb") == 0)
		ft_turn_rb(*b);
	else if (ft_strcmp(arr, "rr") == 0)
		ft_rr(*b, a);
	else if (ft_strcmp(arr, "rra") == 0)
		ft_rra(a);
	else if (ft_strcmp(arr, "rrb") == 0)
		ft_rrb(*b);
	else if (ft_strcmp(arr, "rrr") == 0)
		ft_rrr(*b, a);
	else
		ft_error();
}

void	ft_oper_check(char *arr, t_stack *a, t_stack **b)
{
	if (ft_strcmp(arr, "sa") == 0)
		ft_sa(a);
	else if (ft_strcmp(arr, "ra") == 0)
		ft_turn_ra(a);
	else if (ft_strcmp(arr, "ss") == 0)
		ft_ss(a, *b);
	else if (ft_strcmp(arr, "pa") == 0 )
	{
		if ((*b) != NULL)
		{
			ft_pa(&a, b);
			*b = del((*b)->value, b);
		}
	}
	else if (ft_strcmp(arr, "pb") == 0)
	{
		ft_pb(&a, b);
		a = del(a->value, &a);
	}
	else
	{
		opeartion_check(arr, a, b);
	}
}

void	ft_read(t_stack *sa)
{
	char	*t;
	char	*array;
	int		fd;
	int		ret;
	char	temp[10000];

	duplicate(sa);
	array = (char*)malloc(sizeof(char) * 10);
	fd = open(0, O_RDONLY);
	while ((ret = read(0, temp, 10000)) > 0)
	{
		t = array;
		temp[ret] = '\0';
		array = ft_strjoin(array, temp);
		array = ft_strjoin(array, "\n");
		free(t);
	}
	ft_search(array, sa);
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	int		i;
	int		j;

	i = 1;
	sa = ft_listnew();
	// while (av[i])
	// {
	// 	j = 0;
	// 	while (av[i][j])
	// 	{
	// 		if (ft_isdigit(av[i][j]) == 0)
	// 		{
	// 			if (!(av[i][j] == 45 && av[i][j + 1] > 47 &&
	// 			av[i][j + 1] < 58 && j == 0))
	// 				ft_error();
	// 		}
	// 		j++;
	// 	}
	// 	sa->value = ft_atoi(av[i]);
	// 	printf("VLUED:%d", sa->value);
	// 	i != ac - 1 ? sa = ft_listadd(sa) : 0;
	// 	i++;
	// }

	if (ac > 1)
	{
		while (av[i])
		{
			str_check(av[i]);
			str_arg(sa, av[i]);
			i != ac - 1 ? sa = ft_listadd(sa) : 0;
			i++;
		}
	}
	ft_read(sa);
	return (0);
}
