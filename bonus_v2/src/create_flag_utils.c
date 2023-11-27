/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flag_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:38:20 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/26 07:02:05 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parser.h"
#include "libft.h"
#include <stdlib.h>

int is_valid_flag(const char *start, const char *end)
{
	while (start < end)
	{
		if (ft_strchr("+#. -", *start))
                return (1);
		start++;
	}
	return (0);
}

int complete_struct(t_flag *flag, const char *precision, const char *length_flag)
{
	long len;

	if (*precision == '+')
		flag->precision_flag = FLAG_PLUS;
	else if (*precision == '#')
		flag->precision_flag = FLAG_HASH;
	else
		flag->precision_flag = FLAG_NONE;
	if (*length_flag == ' ')
		flag->length_flag = LENGTH_SPACE;
	else if (*length_flag == '.')
		flag->length_flag = LENGTH_DOT;
	else if (*length_flag == '-')
		flag->length_flag = LENGTH_MINUS;
	else
		flag->length_flag = LENGTH_NONE;
	if (ft_strchr(" 0-.", *length_flag))
		len = ft_atoi(length_flag + 1);
	else
		len = ft_atoi(length_flag);
	if (len > INT_MAX || len < 0)
		return (1);
	flag->length = len;
	return (0);
}
