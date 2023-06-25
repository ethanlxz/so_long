/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:37 by etlaw             #+#    #+#             */
/*   Updated: 2022/10/04 11:30:37 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	number;
	long	sign;
	size_t	index;

	number = 0;
	sign = 1;
	index = 0;
	while ((str[index] != '\0') && ft_isspace(str[index]) == 1)
		++index;
	if (str[index] == '-')
		sign = -1;
	if ((str[index] == '-') || (str[index] == '+'))
		++index;
	while ((str[index] != '\0') && ('0' <= str[index]) && (str[index] <= '9'))
	{
		number = (number * 10) + (str[index] - '0');
		if (number > 2147483647 && sign == 1)
			return (-1);
		if (number > 2147483648 && sign == -1)
			return (0);
		++index;
	}
	return (sign * number);
}
