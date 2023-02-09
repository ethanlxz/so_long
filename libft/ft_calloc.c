/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:50:45 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/22 20:14:26 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= SIZE_MAX || size >= SIZE_MAX || size * count >= SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
