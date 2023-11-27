/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:07:18 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/27 01:29:24 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int display_char(const char *str)
{
    const char *tmp;
    int         len;

    tmp = ft_strchr(str, '%');
    if (tmp == NULL)
        len = ft_strlen(str);
    else
        len = tmp - str;
    return (write(1, str, len));
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    int     len;

    if (format == NULL)
        return (write(1, "(null)", 6));
    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            if (*(format++))
                len = manage_flag(format, args, &count);
            else
                return (-1);
        }
        else
        {
            len = display_char(format);
            count += len;
        }
        format += len;
    }
    return (count);
}

int main() {
    int test;

    test = -123;
    printf("teist % 9.5d", test);     
    return 0;
}

