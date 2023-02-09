/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:39:15 by etlaw             #+#    #+#             */
/*   Updated: 2023/02/06 14:04:20 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	getlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*s;

	len = 0;
	len = getlen(n);
	s = (char *)malloc(len + 1 * sizeof(char));
	if (!s)
		return (0);
	s[len] = '\0';
	while (n != 0)
	{
		s[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len += ft_putstr(num);
		free (num);
	}
	return (len);
}
