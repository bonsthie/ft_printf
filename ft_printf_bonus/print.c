/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:42:14 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/24 01:32:58 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag(const char *start, const char *end)
{
	return (write(1, start, end - start));
}


int print_sign(const char *start, const char *value_type, char *nb)
{
	if (*value_type == 'i' || *value_type == 'd' || *value_type == 'u')
	{
		if (*nb == '-')
			return (write(1, "-", 1));
		while (*start < *value_type)
		{
			if (*start == '+')
				return (write(1, "+", 1));
			start++;
		}
	}
	else if (*value_type == 'x' || *value_type == 'X')
	{
		while(*start < *value_type)
		{
			if (*start == '#' && *value_type == 'x')
				return (write(1, "0x", 2));
			else if (*start == '#' && *value_type == 'X')
				return (write(1, "0X", 2));
            start++;
		}
	}
	return (0);
}

int chose_fill_setting(const char *flag, char *nb, int print)
{
	int count;

	count = print;
	if (*flag == '.')
		count += putstr_len_fill_before_num(nb, ft_atoi(flag + 1), '0');
	else if (*flag == ' ')
		count += putstr_len_fill_before_num(nb, ft_atoi(flag + 1) - print, ' ');
	else if(*flag == '0')
		count = putstr_len_fill_before_num(nb, ft_atoi(flag + 1) - print, '0');
	else if(*flag == '-')
		count += putstr_len_fill_after_num(nb, ft_atoi(flag + 1) - print, ' '); 
	return (count);
		
}

int print_with_fill(const char *start, const char *end, char *nb, int print)
{
	int size;

	while (end >= start)
	{
		if (ft_strchr(" .0-", *end))
		{
			size = chose_fill_setting(end, nb, print);
			return (size);
		}
		end--;
	}
	size = ft_putstr(nb);
	return (size);
}
