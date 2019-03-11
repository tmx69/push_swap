/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:35:09 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/11 11:16:26 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_stacka	*ft_listnew(void)
{
	t_stacka *new;

	if (!(new = (t_stacka *)malloc(sizeof(t_stacka))))
		ft_error();
	// if (!(new->array = (char **)malloc(sizeof(char *) * 5)))
	// 	ft_error();
	// if (!(new->array[0] = ft_strnew(0)))
		// ft_error();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stackb	*ft_listnewb(void)
{
	t_stackb *new;

	if (!(new = (t_stackb *)malloc(sizeof(t_stackb))))
		ft_error();
	// if (!(new->array = (char **)malloc(sizeof(char *) * 5)))
	// 	ft_error();
	// if (!(new->array[0] = ft_strnew(0)))
		// ft_error();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stackb *ft_listadd_b(t_stackb *trt)
{
	t_stackb *buf;
	t_stackb *new;

	new = ft_listnewb();
	buf = trt;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = new;
	new->next = NULL;
	new->prev = buf;
	return (new);
}

t_stacka *ft_listadd(t_stacka *trt)
{
	t_stacka *buf;
	t_stacka *new;

	new = ft_listnew();
	buf = trt;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = new;
	new->next = NULL;
	new->prev = buf;
	return (new);
}