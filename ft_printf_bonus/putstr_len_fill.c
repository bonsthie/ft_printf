/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_len_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:53:35 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/23 20:19:06 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int putstr_len_fill_after_string(char *str, int len, char fill_char)
{
	int str_len;

	str_len = ft_strlen(str);
	if (str_len >= len)
		write(1, str, len);
	else
	{
		write(1, str, str_len);
		while(++str_len <= len)
			write(1, &fill_char, 1);
	}
	return (len);
}

int putstr_len_fill_before_string(char *str, int len, char fill_char)
{
	int str_len;

	str_len = ft_strlen(str);
	if (str_len >= len)
		write(1, str, len);
	else
	{
		while(--len >= str_len)
			write(1, &fill_char, 1);
		write(1, str, str_len);
	}
	return (len);
}

int putstr_len_fill_after_num(char *str, int len, char fill_char)
{
	int str_len;

	str_len = ft_putstr(str);
	if (str_len <= len)
	{
		while(str_len++ <= len)
			write(1, &fill_char, 1);
		return (len);
	}
	return (str_len);
}

int putstr_len_fill_before_num(char *str, int len, char fill_char)
{
	int str_len;

	str_len = ft_strlen(str);
	if (str_len >= len)
	{
		ft_putstr(str);
		return (str_len);
	}
	while(str_len < len)
	{
		write(1, &fill_char, 1);
		str_len++;
	}
	ft_putstr(str);
	return (len);
}
