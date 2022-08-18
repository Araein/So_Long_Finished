/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:25 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/13 17:13:10 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	test( int **r, char *buf)
{
	if (**r == -1)
		return (0);
	buf[**r] = 0;
	return (1);
}

int	itoanega(long long *n, long long *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		return (1);
	}
	return (0);
}

void	itoalen(long long *tmpn, long long *len)
{
	while (*tmpn > 9)
	{
		(*len)++;
		*tmpn /= 10;
	}
}

char	*ft_itoa(long long n)
{
	long long		tmpn;
	long long		len;
	char			*str;
	long long		negative;

	if (n == -2147483648)
		return ((char *)ft_strdup("2147483648"));
	negative = 0;
	tmpn = n;
	len = 2;
	itoalen(&tmpn, &len);
	len += itoanega(&n, &negative);
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
