/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:26:36 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/06 14:27:38 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void    ft_check(t_stacka  *sa)
{
    while (sa->prev != NULL)
    {
        if (sa->a < sa->prev->a)
            printf("HUY:%d\n",sa->a);
            // ft_error();
        sa = sa->prev;
    }
}