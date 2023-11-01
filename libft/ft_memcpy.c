/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:17:13 by oyozcan           #+#    #+#             */
/*   Updated: 2023/07/12 17:20:11 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	i = 0;
	dstc = (unsigned char *) dst;
	srcc = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (NULL); 
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
