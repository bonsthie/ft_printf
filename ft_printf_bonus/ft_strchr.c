/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:16:09 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/19 23:16:25 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	while (*str)
	{
		if (uc == *str)
			return ((char *) str);
		str++;
	}
	if (uc == '\0')
		return ((char *) str);
	return (NULL);
}
