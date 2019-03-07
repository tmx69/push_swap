/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:26:36 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/07 17:11:45 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

# include <fcntl.h>
# include <stdio.h>
# include <sys/_types.h>
# include <sys/stat.h>
# include <stdlib.h>

void ft_error()
{
	write(1,"ERROR\n", 6);
	exit(0);
}

void    ft_check(t_stacka  *sa)
{
	if (sa->next == NULL)
	{
    	while (sa->prev != NULL)
    	{
        	if (sa->a < sa->prev->a)
            	ft_error();
        	sa = sa->prev;
    	}
	}
	else if (sa->prev == NULL)
	{
    	while (sa->next != NULL)
    	{
        	if (sa->a > sa->next->a)
            	ft_error();
        	sa = sa->next;
    	}
	}
}

void	ft_oper_check(char *arr, t_stacka	*sa)
{
	int i;
	char *s;
	t_stackb	*sb;
	i = 0;
	sb = ft_listnewb();
	s = (char*)malloc(sizeof(char) * 10);
	while(arr[i])
	{
		if (arr[i] == '\n')
		{
			if (ft_strcmp(s, "sa") ==  0)
				ft_sa(sa);
			else if(ft_strcmp(s, "sb") == 0)
				ft_sb(sb);
			else if(ft_strcmp(s, "ss") == 0)
				ft_ss(sa, sb);
			else if(ft_strcmp(s, "pa") == 0)
				ft_pa(sa, sb);
			else if(ft_strcmp(s, "pb") == 0)
				ft_pb(sa, sb);
			else if(ft_strcmp(s, "ra") == 0)
				ft_turn_ra(sa);
			else if(ft_strcmp(s, "rb") == 0)
				ft_turn_rb(sb);
			else if(ft_strcmp(s, "rr") == 0)
				ft_rr(sb, sa);
			else if(ft_strcmp(s, "rra") == 0)
				ft_rr(sb, sa);
			else if(ft_strcmp(s, "rrb") == 0)
				ft_rra(sa);
			else if(ft_strcmp(s, "rrr") == 0)
				ft_rrb(sb);
			else
				ft_error();
			i++;
		}
		s[i] = arr[i];
		i++;
	}
	// ft_check(sa);
	while (sa != NULL)
	{
		printf("%d", sa->a);
		printf("\n");
		sa = sa->prev;
	}

}
void ft_read(t_stacka	*sa)
{
	char *t;
	char *array;
	int fd;
	int				ret;
	char			temp[10000];
	array = (char*)malloc(sizeof(char) * 10);
	fd =  open(0, O_RDONLY);

		while ((ret = read(0, temp, 10000)) > 0)
		{
			t = array;
			temp[ret] = '\0';
			array = ft_strjoin(array, temp);
			// array = ft_strjoin(array, "\n");
			free(t);
		}
		ft_oper_check(array, sa);
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
	ft_read(sa);


	return (0);
}
