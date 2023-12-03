/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:08:13 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:09:36 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list *list)
{
	int	i;

	list->tmp = list->stack_a[list->size_a - 1];
	i = list->size_a - 1;
	while (i > 0)
	{
		list->stack_a[i] = list->stack_a[i - 1];
		i--;
	}
	list->stack_a[0] = list->tmp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list *list)
{
	int	i;

	list->tmp = list->stack_b[list->size_b - 1];
	i = list->size_b - 1;
	while (i > 0)
	{
		list->stack_b[i] = list->stack_b[i - 1];
		i--;
	}
	list->stack_b[0] = list->tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_list *list)
{
	reverse_rotate_a(list);
	reverse_rotate_b(list);
	write(1, "rrr\n", 4);
}
