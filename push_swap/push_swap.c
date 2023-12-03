/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:04:54 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:04:55 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list;
	int		count_elements;

	ft_check(av);
	list = malloc(sizeof * list);
	count_elements = count_element(av);
	if (list == NULL || ac < 2)
		exit(1);
	check_arguments(ac, av);
	initialize_stacks(ac, av, list);
	list->stack_a = parse_control(av, count_elements);
	if (check_sorted(list) == 1)
	{
		stack_free(list);
		exit(1);
	}
	check_duplicate(list);
	create_index(list);
	sort_all(list, list->size_a);
	if (check_sorted(list) == 0)
	{
		error_message();
	}
	stack_free(list);
	return (0);
}
