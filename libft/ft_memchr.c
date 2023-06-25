/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:53:27 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/20 18:00:49 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_char;
	unsigned char	c_char;
	size_t			index;

	s_char = (unsigned char *)s;
	c_char = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (s_char[index] == c_char)
			return ((void *)s);
		++s;
		++index;
	}
	return (0);
}
