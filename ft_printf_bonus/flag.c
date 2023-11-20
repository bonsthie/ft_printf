/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:53 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/20 22:02:12 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int is_chars(const char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

const char *find_value_type(const char *flag)
{
	if (!flag)
		return (NULL);
	while (is_chars(*flag, "0.-+ #") || ft_isdigit(*flag))
		flag++;
	return (flag);
}

int print_flag(const char *start, const char *end)
{
	int	len;

	len = write(1, start, end - start);
	return (len);
}

int manage_char(va_list args, const char *flag, const char *value_type)
{
	int len;

	(void)flag;

	if (*value_type == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (*value_type == 's')
	{
		write(1, "rhaa", 4);
		while(!is_chars(*value_type, " -") || value_type >= flag)	
			value_type--;
		if (*value_type == '-' )
			len = putstr_len_fill_after(va_arg(args, char *), atoi(value_type + 1), ' '); /// atoi!!!!!
		else if (*value_type == ' ')
			len = putstr_len_fill_before(va_arg(args, char *), atoi(value_type + 1), ' ');
		else
			len = ft_putstr(va_arg(args, char *));
	}
	else
		len = 0;
	return (len);
}

int manage_flag(const char *flag, va_list args, int *count)
{
	const char *value_type;

	(void) args;
	value_type = find_value_type(flag);
	if (*value_type == 'c' || *value_type == 's')
		*count += manage_char(args, flag, value_type);
	else
		*count += print_flag(flag, value_type);
	return (value_type - flag + 1);
}
