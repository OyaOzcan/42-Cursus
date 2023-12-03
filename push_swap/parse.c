/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:04:34 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:04:36 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(int ac, char **av, t_list *list)
{
	int	i;

	i = 0;
	list->size_a = 0;
	list->size_b = 0;
	while (--ac)
	{
		if (count_words(av[i + 1]))
			list->size_a += count_words(av[i + 1]);
		else
			list->size_a++;
		i++;
	}
	list->stack_b = malloc(list->size_a * sizeof * list->stack_b);
	if (list->stack_b == NULL)
	{
		stack_free(list);
		error_message();
	}
}

int	*parse_control(char **av, int ta)
{
	char	**array;
	int		i;
	int		j;
	int		x;
	int		*res;

	i = 0;
	x = 0;
	res = malloc(sizeof(int) * (ta));
	if (!res)
	{
		free(res);
		error_message();
	}
	while (av[++i] != NULL)
	{
		if (av[i][0] == '\0')
			error_message();
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j] != NULL)
			res[x++] = ft_atoin(array[j++]);
		array_free(array);
	}
	return (res);
}

void	create_index(t_list *list)
{
	int	i;
	int	j;
	int	count;
	int	*index_a;

	index_a = malloc(list->size_a * sizeof * index_a);
	if (index_a == NULL)
	{
		stack_free(list);
		error_message();
	}
	i = -1;
	while (++i < list->size_a)
	{
		count = 0;
		j = -1;
		while (++j < list->size_a)
			if (list->stack_a[i] > list->stack_a[j])
				count++;
		index_a[i] = count;
	}
	i = -1;
	while (++i < list->size_a)
		list->stack_a[i] = index_a[i];
	free(index_a);
}
