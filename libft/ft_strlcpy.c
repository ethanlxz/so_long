/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:55:14 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/20 17:53:56 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize == 0)
	{
		while (src[index])
			++index;
		return (index);
	}
	while (index < dstsize - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		++index;
	}
	if (index < dstsize)
		dst[index] = '\0';
	while (src[index] != '\0')
		++index;
	return (index);
}
