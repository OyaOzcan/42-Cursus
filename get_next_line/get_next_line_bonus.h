/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:47:25 by oyozcan           #+#    #+#             */
/*   Updated: 2023/08/01 14:54:32 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_find_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif