/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:26:36 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/21 18:07:29 by rywisozk         ###   ########.fr       */
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

void	ft_oper_check(char *arr, t_stack	*sa)
{
	int i;
	char *s;
	int j;

	j = 0;
	t_stack	*sb;
	i = 0;
	sb = ft_listnew();
	s = (char*)malloc(sizeof(char) * 10);
	// while(arr[i])
	// {
			if (ft_strcmp(arr, "sa") ==  0)
				ft_sa(sa);
			else if(ft_strcmp(arr, "sb") == 0)
				ft_sb(sb);
			else if(ft_strcmp(arr, "ss") == 0)
				ft_ss(sa, sb);
			else if(ft_strcmp(arr, "pa") == 0)
				ft_pa(sa, &sb);
			else if(ft_strcmp(arr, "pb") == 0)
				ft_pb(sa, sb);
			else if(ft_strcmp(arr, "ra") == 0)
				ft_turn_ra(sa);
			else if(ft_strcmp(arr, "rb") == 0)
				ft_turn_rb(sb);
			else if(ft_strcmp(arr, "rr") == 0)
				ft_rr(sb, sa);
			else if(ft_strcmp(arr, "rra") == 0)
				ft_rra(sa);
			else if(ft_strcmp(arr, "rrb") == 0)
				ft_rrb(sb);
			else if(ft_strcmp(arr, "rrr") == 0)
				ft_rrr(sb,sa);
			else
				ft_error();
		// i++;
	// }
	// ft_check(sa);
	// while (sa->prev != NULL)
    // {
    // 	sa = sa->prev;
    // }
	// while (sa != NULL)
	// {
	// 	printf("%d", sa->value);
	// 	// printf("\n");
	// 	sa = sa->next;
	// }

}
void ft_read(t_stack	*sa)
{
	char	*t;
	int 	i;
	char	**array;
	int		fd;
	int		ret;
	char	temp[10000];
	i = 0;
	array = (char**)malloc(sizeof(char*) * 10);
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
	fd =  open(0, O_RDONLY);
	while ((ret = read(0, temp, 10000)) > 0)
	{
		t = *array;
		temp[ret] = '\0';
		array[i] = ft_strjoin(*array, temp);
		// array = ft_strjoin(array, "\n");
		i++;
		free(t);
	}
	while (*array[i])
{
	printf("%s", array[i]);
	i--;
}
	// while (sa->prev != NULL)
    // {
    // 	sa = sa->prev;
    // }
	// while (sa != NULL)
	// {
	// 	printf("%d", sa->value);
	// 	// printf("\n");
	// 	sa = sa->next;
	// }
	// ft_oper_check(array, sa);
	// printf("%s", array);
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
