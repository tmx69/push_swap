/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:33:03 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/22 19:14:07 by rywisozk         ###   ########.fr       */
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

void ft_search(char *arr, t_stack *a)
{
    char **s;
    int i;
	t_stack *b;

	// b = ft_listnew();
	b = NULL;
    i = 0;
    s = ft_strsplit(arr, '\n');
    while (s[i])
    {
        ft_oper_check(s[i], a, &b);

        i++;
    }
    // // ft_check(sa);
    // if (a)
    // {
    // while (a->prev != NULL)
    // {
    //     a = a->prev;
    // }
	// while (a != NULL)
	// {
	// 	printf("a:%d", a->value);
	// 	printf("\n");
	// 	a = a->next;
	// }
    // }


	if (b)
	{
		while (b->prev != NULL)
    	{
       	 	b = b->prev;
    	}
		while (b != NULL)
		{
			printf("b: %d\n", b->value);
			printf("b->next: %p\n", b->prev);
			printf("b->prev: %p\n", b->next);

			b = b->next;
		}
	}
	if (a)
    	{
    	while (a->prev != NULL)
   	 	{
        	a = a->prev;
    	}
		while (a != NULL)
		{
			printf("a: %d", a->value);
			printf("\n");
			a = a->next;
		}
    	}
}