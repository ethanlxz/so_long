/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:17:05 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/14 23:08:51 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s1);
	index = 0;
	while (index < len)
	{
		if (ft_strchr(set, s1[index]) == 0)
			break ;
		++index;
	}
	return (index);
}

static int	getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s1);
	index = 0;
	while (index < len)
	{
		if (ft_strchr(set, s1[len - index -1]) == 0)
			break ;
		++index;
	}
	return (len - index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (0);
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == 0)
		return (0);
	ft_strlcpy(newstr, s1 + start, end - start + 1);
	return (newstr);
}
