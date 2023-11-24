/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:02:52 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/24 01:43:27 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	calcul_length(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		count++;
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static int	calcul_length_base(unsigned long nb, int base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= base;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*dest;
	int		dest_len;
	long	n;

	n = nb;
	dest_len = calcul_length(n);
	dest = malloc((dest_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[dest_len--] = 0;
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	while (n)
	{
		dest[dest_len--] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}

char	*ft_uitoa_base(unsigned long nb, char *base, int base_len)
{
	char	*dest;
	int		dest_len;
	long	n;

	n = nb;
	dest_len = calcul_length_base(n, base_len);
	dest = malloc((dest_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[dest_len--] = 0;
	if (n == 0)
	{
		dest[0] = '0';
	}
	while (n)
	{
		dest[dest_len--] = base[n % base_len];
		n /= base_len;
	}
	return (dest);
}
