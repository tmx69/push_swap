/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:35:09 by rywisozk          #+#    #+#             */
/*   Updated: 2019/04/02 19:58:57 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

void	ft_check(t_stack *sa)
{
	t_stack	*help;
	while (sa->prev != NULL)
	{
		sa = sa->prev;
	}
	help = sa;
		while (help->prev)
			help = help->prev;
		while(help != NULL)
		{
			printf("|%d|", help->value );
			help = help->next;
		}
		printf("\n");
	while (sa->next != NULL)
	{
		if (sa->value > sa->next->value)
		{
			write(1, "ko", 2);
			exit(0);
		}
		sa = sa->next;
	}
	write(1, "ok", 2);
}

t_stack	*ft_listnew(void)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		ft_error();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_listadd(t_stack *trt)
{
	t_stack *buf;
	t_stack *new;

	new = ft_listnew();
	buf = trt;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = new;
	new->next = NULL;
	new->prev = buf;
	return (new);
}

t_stack	*ft_listadd_start(t_stack *trt)
{
	t_stack *buf;
	t_stack *new;

	new = ft_listnew();
	buf = trt;
	while (buf->prev != NULL)
		buf = buf->prev;
	buf->prev = new;
	new->next = buf;
	new->prev = NULL;
	return (new);
}

void	list_del(t_stack **alst)
{
	while (*alst)
	{
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}
