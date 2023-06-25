/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:14:30 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 16:06:23 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		c;
	size_t		n_len;
	const char	*hay;

	index = 0;
	hay = (const char *)haystack;
	n_len = ft_strlen(needle);
	if (!needle[0])
		return ((char *)hay);
	if (len == 0)
		return (NULL);
	while (hay[index] && (index < len))
	{
		c = 0;
		while (hay[index + c] == needle[c] && index + c < len)
		{
			if (!needle[c + 1])
				return ((char *)hay + index);
			c++;
		}
		index++;
	}
	return (NULL);
}
