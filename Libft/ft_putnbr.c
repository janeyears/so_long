/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:34 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/17 11:47:29 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr, size_t *count)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648", count));
	if (nbr < 0)
	{
		res = ft_putchar('-', count);
		if (res == -1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		res = ft_putnbr(nbr / 10, count);
		if (res == -1)
			return (-1);
	}
	return (ft_putchar(nbr % 10 + '0', count));
}
