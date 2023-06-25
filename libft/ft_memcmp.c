/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:02:01 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/12 18:02:33 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_pointer;
	const unsigned char	*s2_pointer;
	size_t				index;

	index = 0;
	s1_pointer = (const unsigned char *)s1;
	s2_pointer = (const unsigned char *)s2;
	while (index < n)
	{
		if (s1_pointer[index] != s2_pointer[index])
			return (s1_pointer[index] - s2_pointer[index]);
		++index;
	}
	return (0);
}
