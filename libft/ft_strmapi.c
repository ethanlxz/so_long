/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:25:02 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/20 17:39:59 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new_s;

	index = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	new_s = ft_strdup(s);
	if (!new_s)
		return (ft_strdup(""));
	while (s[index])
	{
		new_s[index] = (*f)(index, s[index]);
		++index;
	}
	return (new_s);
}
