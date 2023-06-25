/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:19:39 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/03 23:19:39 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_pointer;
	char	*src_pointer;

	dst_pointer = (char *)dst;
	src_pointer = (char *)src;
	if (dst == src)
		return (dst);
	if (src_pointer < dst_pointer)
	{
		while (len--)
			*(dst_pointer + len) = *(src_pointer + len);
		return (dst);
	}
	while (len--)
		*dst_pointer++ = *src_pointer++;
	return (dst);
}
