/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:41:02 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/06 13:10:52 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *source)
{
	char	*dest;
	size_t	source_len;

	source_len = ft_strlen(source) + 1;
	dest = malloc((source_len) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, source, source_len);
	return (dest);
}
