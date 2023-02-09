/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:11:58 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 16:04:35 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst && !dstsize)
		return (srclen);
	dstlen = ft_strlen(dst);
	index = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	index = 0;
	while ((dstlen + 1 + index < dstsize) && src[index])
	{
		dst[dstlen + index] = src[index];
		index++;
	}
	dst[dstlen + index] = '\0';
	return (dstlen + srclen);
}
