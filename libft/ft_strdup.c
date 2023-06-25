/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:02:26 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/20 18:01:46 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s;
	int		index;
	int		size;

	size = ft_strlen(s1);
	new_s = (char *)malloc(sizeof(char) * (size + 1));
	if (new_s == NULL)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		new_s[index] = s1[index];
		++index;
	}
	new_s[index] = '\0';
	return (new_s);
}
