/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:35:09 by rywisozk          #+#    #+#             */
/*   Updated: 2019/03/18 13:56:56 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/ft_push_swap.h"
#include "../libft/libft.h"

t_stack	*ft_listnew(void)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		ft_error();
	// if (!(new->array = (char **)malloc(sizeof(char *) * 5)))
	// 	ft_error();
	// if (!(new->array[0] = ft_strnew(0)))
		// ft_error();
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack *ft_listadd(t_stack *trt)
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