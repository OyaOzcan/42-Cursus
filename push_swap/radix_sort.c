/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:15:41 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/12 12:15:59 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_num(t_list *list)
{
	int	max;
	int	i;

	i = 0;
	max = list->stack_a[0];
	while (i < list->size_a)
	{
		if (list->stack_a[i] > max)
			max = list->stack_a[i];
		i++;
	}
	return (max);
}

int	max_bits(int max)
{
	int	bit_count;

	bit_count = 0;
	while (max > 0)
	{
		max /= 2;
		bit_count++;
	}
	return (bit_count);
}

void	radix_sort(t_list *list)
{
	int	i;
	int	j;
	int	size;
	int	max;
	int	max_bit;

	i = 0;
	size = list->size_a;
	max = max_num(list);
	max_bit = max_bits(max);
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if (((list->stack_a[0] >> i) & 1) == 1)
				rotate_a(list);
			else
				push_b(list);
			j++;
		}
		while (list->size_b != 0)
			push_a(list);
		i++;
	}
}
