/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:12:04 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 15:08:15 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		slen;

	slen = ft_strlen(s) + 1;
	while (--slen >= 0)
		if (*(s + slen) == (unsigned char) c)
			return ((char *)(s + slen));
	return (NULL);
}
