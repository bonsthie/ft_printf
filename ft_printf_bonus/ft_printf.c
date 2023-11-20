/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:07:18 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/20 22:04:06 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_printf("%-54s%c", "oui", 'n');
	//printf();
}
