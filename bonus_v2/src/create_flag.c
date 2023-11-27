/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:23:28 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/26 09:45:08 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_flag.h"
#include "format_parser.h"
#include "libft.h"
#include <stdlib.h>

static const char *find_length_char(const char *start, const char *end, char *prefer_length)
{
	const char *return_char;

	while (ft_strchr("+#", *start) && start < end)
		start++;
	return_char = start;
	while (ft_isdigit(*start))
		start++;
	while (!ft_strchr(prefer_length, *start) && start < end)
		start++;
	if (start == end || start == end - 1)
		return (return_char);
	return (start);
}

t_flag *create_flag(const char *start, const char *end, char precision, char *prefer_length)
{
	t_flag *new;
	const char *precision_char;
	const char *length_char;
	int         error;

	new = malloc(sizeof(t_flag *));
	if (!new)
		return (NULL);
	while (*start != precision && ft_strchr("+#", *start))
		start++;
	precision_char = start;
	if (((*end == 'd' || *end == 'i') && *start == '+') || (((*end == 'x' || *end == 'X') && *start == '#')))
		length_char = find_length_char(start, end, "-0.");
	else
		length_char = find_length_char(start, end, prefer_length);
	if (!is_valid_flag(length_char + 1, end))
		new->format = *end;
	else
		new->format = FMT_WRONG;
	error = complete_struct(new, precision_char, length_char);
	if (!error)
		return (new);
	free(new);
	return (NULL);
}
