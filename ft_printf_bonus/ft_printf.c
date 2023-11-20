/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:07:18 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/20 02:28:36 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int manage_flag(const char *flag, va_list args, int *len)
{
    (void)flag;
    (void)len;
    (void)args;
    return (write(1, "%%", 2));
}

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

//manage null and nill please 
int ft_printf(const char *format, ...)
{
    va_list args;
    int count;
    int len;

    if (format == NULL)
        return (write(1, "(null)", 6));
    count = 0;
    va_start(args, format);
    while(*format)
    {
        if (*format == '%')
        {
            if (*(format++))
                len = manage_flag(format,args, &count);
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


int main()
{
    //int len = ft_printf(NULL, 1);
    printf("%+.5d", 123);
    printf("\n%.5d", -123);
}
