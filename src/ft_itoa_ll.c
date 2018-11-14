/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 09:16:02 by pfaust            #+#    #+#             */
/*   Updated: 2018/10/17 09:19:00 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static long long		ft_itoalen(unsigned int n)
{
	long long		len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa_ll(long long n)
{
	char				*itoa;
	long long			len;
	unsigned long long	i;
	unsigned int		pow;

	itoa = NULL;
	if (!(itoa = (char*)malloc(sizeof(char) * (ft_itoalen(n) + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		itoa[i++] = '-';
		n = (unsigned int)-n;
	}
	len = ft_itoalen(n);
	if (n == 0)
		itoa[i++] = '0';
	while (len)
	{
		pow = ft_pow(len--);
		itoa[i++] = (n / pow) + '0';
		n = n % pow;
	}
	itoa[i] = '\0';
	return (itoa);
}
