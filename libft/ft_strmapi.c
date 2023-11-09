/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:37:30 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/06 13:13:33 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[i] = 0;
	while (i--)
		dest[i] = f(i, s[i]);
	return (dest);
}
