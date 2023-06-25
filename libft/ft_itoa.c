/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:38:35 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/21 15:27:02 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dig_count(long n)
{
	size_t	digit;

	digit = 0;
	if (n < 0)
	{
		++digit;
		n = -n;
	}
	while (n >= 1)
	{
		++digit;
		n /= 10;
	}
	return (digit);
}

static char	*gen(char *new_s, long number, int len, int sign)
{
	if (number != 0)
		new_s = malloc(sizeof(char) * (len + 1));
	else
		return (new_s = ft_strdup("0"));
	if (!new_s)
		return (0);
	sign = 0;
	if (number < 0)
	{
		++sign;
		number = -number;
	}
	new_s[len] = '\0';
	while (--len)
	{
		new_s[len] = (number % 10) + '0';
		number /= 10;
	}
	if (sign == 1)
		new_s[0] = '-';
	else
		new_s[0] = (number % 10) + '0';
	return (new_s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*new_s;
	long	number;
	int		sign;

	number = n;
	new_s = 0;
	len = dig_count(number);
	sign = 0;
	new_s = gen(new_s, number, len, sign);
	if (!(new_s))
		return (0);
	return (new_s);
}
