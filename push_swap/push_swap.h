/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <oyozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:56:02 by oyozcan           #+#    #+#             */
/*   Updated: 2023/11/30 15:08:51 by oyozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct list
{
	int	*stack_a;
	int	*stack_b;
	int	tmp;
	int	size_a;
	int	size_b;
}		t_list;

void	rotate_a(t_list *list);
void	rotate_b(t_list *list);
void	rr(t_list *list);
void	swap_a(t_list *list);
void	swap_b(t_list *list);
void	ss(t_list *list);
void	push_a(t_list *list);
void	push_b(t_list *list);
void	reverse_rotate_a(t_list *list);
void	reverse_rotate_b(t_list *list);
void	rrr(t_list *list);
void	sort_two(t_list *list);
void	sort_three(t_list *list);
void	sort_five(t_list *list);
void	radix_sort(t_list *list);
void	sort_all(t_list *list, int len);
void	initialize_stacks(int argc, char **argv, t_list *list);
void	check_arguments(int argc, char **argv);
int		ft_atoin(char *str);
int		*parse_control(char **av, int ta);
void	check_duplicate(t_list *list);
int		check_sorted(t_list *list);
int		count_element(char **av);
void	stack_free(t_list *list);
void	error_message(void);
void	array_free(char **array);
int		count_words(char *str);
void	create_index(t_list *list);
int		max_bit(int max);
int		max_num(t_list *list);
void	ft_check(char **str);

#endif
