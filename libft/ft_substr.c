/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:42:39 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 20:06:31 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len2;
	char	*subs;

	i = 0;
	if (!s)
		return (0);
	len2 = ft_strlen(s);
	if (len2 < (size_t)start)
		return (ft_strdup(""));
	if (len2 < len)
		len = len2;
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (!subs)
		return (0);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
