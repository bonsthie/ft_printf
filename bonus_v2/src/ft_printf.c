/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:53:37 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/26 09:28:28 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "format_parser.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    t_flag *flag;
    int status;

    status = 0;
    flag = format_parsing(format, &status);
    printf("len type == %d \nlen == %d \n format == %d\n", flag->length_flag, flag->length, flag->format);
    printf("%s\n", format);
    clear_all(flag);
    return (1);
}
