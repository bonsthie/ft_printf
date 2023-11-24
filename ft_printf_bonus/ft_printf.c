/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:07:18 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/24 02:08:09 by bbonnet          ###   ########.fr       */
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

#include <stdio.h>

int main() {
    int num;
    char *str;

    // Test Case 1: Integer with various flags
    num = 123;
    printf("Standard printf:\n");
    printf("%+d\n", num);
    printf("ft_printf:\n");
    ft_printf("%+d\n", num);
    fflush(stdout); // Flush stdout to ensure synchronous output

    // Test Case 2: String with precision
    str = "Hello, World!";
    printf("Standard printf:\n");
    printf("%.5s\n", str);
    printf("ft_printf:\n");
    ft_printf("%.5s\n", str);
    fflush(stdout);

    // Test Case 3: Hexadecimal with # flag
    num = 456;
    printf("Standard printf:\n");
    printf("%#x\n", num);
    printf("ft_printf:\n");
    ft_printf("%#x\n", num);
    fflush(stdout);

    // Test Case 4: Left padding with spaces
    printf("Standard printf:\n");
    printf("%10d\n", num);
    printf("ft_printf:\n");
    ft_printf("%10d\n", num);
    fflush(stdout);

    // Test Case 5: Left padding with zeros
    printf("Standard printf:\n");
    printf("%010d\n", num);
    printf("ft_printf:\n");
    ft_printf("%010d\n", num);
    fflush(stdout);

    // Test Case 6: Left justified with -
    printf("Standard printf:\n");
    printf("%-10d\n", num);
    printf("ft_printf:\n");
    ft_printf("%-10d\n", num);
    fflush(stdout);

    // More test cases as needed...

    return 0;
}

/*
int main()
{
    int test = 123;
	//ft_printf("%+ 23423472327834628427864d", 123);
	ft_printf("%p\n", &test);
	ft_printf("% 9d\n", -123);
	ft_printf("%09u\n", 123);
	ft_printf("% -9d\n\n", 123);
	printf("%p\n", &test);
	printf("% 9d\n", -123);
	printf("%09u\n", 123);
	printf("% -9d\n", 123);
}*/
