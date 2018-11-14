/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:16:44 by pfaust            #+#    #+#             */
/*   Updated: 2017/11/17 14:18:05 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
			ft_putchar(s[i++]);
		ft_putchar('\n');
	}
}