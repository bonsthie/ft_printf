/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:47:09 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/27 02:15:45 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char *itoa_select(t_flag *flag, va_list args)
{
    char *num;

    num = NULL;
    if (flag->format == FMT_DEC || flag->format == FMT_INT)
            num = ft_itoa(va_arg(args, int));
    else if (flag->format == FMT_UINT)
        num = ft_ultoa_base(va_arg(args, unsigned int), BASE_10, 10);
    else if (flag->format == FMT_HEX_LOW)
        num = ft_ultoa_base(va_arg(args, unsigned int), BASE_16_LOW, 16);
    else if (flag->format == FMT_HEX_UP)
        num = ft_ultoa_base(va_arg(args, unsigned int), BASE_16_UP, 16);
    return (num);
}

char *sign_str(t_flag *flag, char *num)
{
    if (flag->precision_flag == FLAG_PLUS && ft_isdigit(num[0]))
        return (ft_strdup("+"));
    else if (num[0] == '-')
        return (ft_strdup("-"));
    else if (flag->precision_flag == FLAG_HASH && flag->format == FMT_HEX_UP)
        return (ft_strdup("0X"));
    else if (flag->precision_flag == FLAG_HASH && flag->format == FMT_HEX_LOW)
        return (ft_strdup("0x"));
    else 
        return (ft_strdup(""));
}
int make_flag_dot(t_flag *flag, va_list args)
{
	char *num;
	char *result;
    char *sign;
    int size;

    num = itoa_select(flag, args);
    size = ft_strlen(num);
    
	write(1, num, ft_strlen(num));
	return (0);
}
