/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:58:32 by pfaust            #+#    #+#             */
/*   Updated: 2018/10/11 14:23:57 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int		digits(unsigned long long n, unsigned int base)
{
	unsigned long long		ptr;
	int						len;

	ptr = n;
	if (n == 0)
		return (1);
	len = 0;
	while (ptr)
	{
		ptr = ptr / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base_ll(long long n, unsigned int base)
{
	int					len;
	char				*str;
	int					neg;
	unsigned long long	nb;

	if (base < 2 || base > 16)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	nb = (neg == 1) ? (unsigned long long)-n : (unsigned long long)n;
	len = digits(nb, base) + neg;
	if (!(str = ft_strnew(len + neg)))
		return (NULL);
	while (--len >= neg)
	{
		if (nb % base < 10)
			str[len] = nb % base + 48;
		else
			str[len] = nb % base - 10 + 'a';
		nb = nb / base;
	}
	if (neg)
		str[len] = '-';
	return (str);
}
