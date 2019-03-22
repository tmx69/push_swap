/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:26:36 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/22 19:51:18 by rywisozk         ###   ########.fr       */
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

void ft_error()
{
	write(1,"ERROR\n", 6);
	exit(0);
}

void    ft_check(t_stack  *sa)
{
	while (sa->prev != NULL)
    {
    	sa = sa->prev;
    }
    while (sa->next != NULL)
    {
        if (sa->value > sa->next->value)
		{
			write (1, "ko", 2);
			// exit (0);
		}
        sa = sa->next;
    }
	write(1, "ok", 2);

}

void	ft_oper_check(char *arr, t_stack *a, t_stack **b)
{

			if (ft_strcmp(arr, "sa") ==  0)
				ft_sa(a);
			else if(ft_strcmp(arr, "b") == 0)
				ft_sb(*b);
			else if(ft_strcmp(arr, "ss") == 0)
				ft_ss(a, *b);
			else if(ft_strcmp(arr, "pa") == 0)
			{
				ft_pa(&a, b);
				*b = del((*b)->value, b);
			}
			else if(ft_strcmp(arr, "pb") == 0)
			{
				ft_pb(&a, b);
				a = del(a->value, &a);
			}
			else if(ft_strcmp(arr, "ra") == 0)
				ft_turn_ra(a);
			else if(ft_strcmp(arr, "rb") == 0)
				ft_turn_rb(*b);
			else if(ft_strcmp(arr, "rr") == 0)
				ft_rr(*b, a);
			else if(ft_strcmp(arr, "rra") == 0)
				ft_rra(a);
			else if(ft_strcmp(arr, "rrb") == 0)
				ft_rrb(*b);
			else if(ft_strcmp(arr, "rrr") == 0)
				ft_rrr(*b,a);
			else
				ft_error();

}
void ft_read(t_stack	*sa)
{
	char	*t;
	char	*array;
	int		fd;
	int		ret;
	char	temp[10000];

	array = (char*)malloc(sizeof(char) * 10);
	// array = (char*)malloc(sizeof(char) * 10000);
	// array[0] = 'r';
	// array[1] = 'r';
	// array[2] = 'a';
	// array[3] = '\n';
	// array[4] = 'p';
	// array[5] = 'b';
	// array[6] = '\n';
	// array[7] = 's';
	// array[8] = 'a';
	// array[9] = '\n';
	// array[10] = 'r';
	// array[11] = 'r';
	// array[12] = 'a';
	// array[13] = '\n';
	// array[14] = 'p';
	// array[15] = 'a';
	// array[16] = '\n';
	// array[17] = 'p';
	// array[18] = 'a';
	// array[19] = '\n';
	// array[20] = 'p';
	// array[21] = 'a';
	// array[22] = '\n';
	// array[23] = 'p';
	// array[24] = 'a';
	// array[25] = '\n';
	// array[6] = 'p';
	// array[7] = 'a';
	// array[8] = '\n';
	// array[9] = 'p';
	// array[10] = 'a';
	// array[11] = '\n';
	// array[12] = 'p';
	// array[13] = 'b';
	// array[14] = '\n';
	// array[12] = 'p';
	// array[13] = 'a';
	// array[14] = '\n';
	// array[15] = 'p';
	// array[16] = 'a';
	// array[17] = '\n';
	// array[18] = 'p';
	// array[19] = 'a';
	// array[20] = '\n';
	fd =  open(0, O_RDONLY);
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
int main(int ac, char **av)
{
	t_stack	*sa;
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
		sa->value = ft_atoi(av[i]);
		if (i != ac - 1)
			sa = ft_listadd(sa);
		i++;
	}
	ft_read(sa);
	return (0);
}
