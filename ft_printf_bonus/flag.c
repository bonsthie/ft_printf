/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:53 by babonnet          #+#    #+#             */
/*   Updated: 2023/11/24 15:01:12 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	is_chars(const char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

const char	*find_value_type(const char *flag)
{
	if (!flag)
		return (NULL);
	while (is_chars(*flag, "0.-+ #") || ft_isdigit(*flag))
		flag++;
	return (flag);
}

int	manage_char(va_list args, const char *flag, const char *value_type)
{
	int	len;

	(void)flag;
	if (*value_type == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (*value_type == 's')
	{
		while (!ft_strchr("-.", *value_type) && value_type >= flag)
			value_type--;
		if (*value_type == '-')
			len = putstr_len_fill_after_num(va_arg(args, char *),
                    ft_atoi(value_type + 1), ' ');
		else if (*value_type == '.')
			len = putstr_len_fill_before_string(va_arg(args, char *),
					ft_atoi(value_type + 1), ' ');
		else
			len = ft_putstr(va_arg(args, char *));
	}
	else
		len = 0;
	return (len);
}

int	manage_pointer(unsigned long pointer)
{
	int		count;
	char	*pointer_s;

	count = 0;
	if (pointer == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	pointer_s = ft_uitoa_base(pointer, BASE_16_LOW, 16);
	if (!pointer_s)
		return (0);
	ft_putstr("0x");
	count += 2 + ft_putstr(pointer_s);
	free(pointer_s);
	return (count);
}

int	manage_num(va_list args, const char *flag, const char *value_type)
{
	char	*nb_s;
	int		count;

	count = 0;
	if (*value_type == 'x')
		nb_s = ft_uitoa_base(va_arg(args, unsigned int), BASE_16_LOW, 16);
	else if (*value_type == 'X')
		nb_s = ft_uitoa_base(va_arg(args, unsigned int), BASE_16_UP, 16);
	else if (*value_type == 'i' || *value_type == 'd')
		nb_s = ft_itoa(va_arg(args, int));
	else if (*value_type == 'u')
		nb_s = ft_uitoa_base(va_arg(args, unsigned int), BASE_10, 10);
	else
		return (print_flag(flag, value_type));
	count = print_sign(flag, value_type, nb_s);
	if (*nb_s == '-')
		nb_s++;
	count = print_with_fill(flag, value_type, nb_s, count);
	//free(nb_s);
	return (count);
}

int	manage_flag(const char *flag, va_list args, int *count)
{
	const char	*value_type;

	(void)args;
	value_type = find_value_type(flag);
	if (*value_type == 'c' || *value_type == 's')
		*count += manage_char(args, flag, value_type);
	else if (*value_type == '%')
		*count += write(1, "%", 1);
	else if (*value_type == 'p')
		*count += manage_pointer((unsigned long)va_arg(args, void *));
	else if (ft_strchr("diuxX", *value_type))
		*count += manage_num(args, flag, value_type);
	else
		*count += print_flag(flag, value_type);
	return (value_type - flag + 1);
}
