/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:17:21 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/23 21:08:06 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_10 "0123456789"

int		ft_printf(const char *format, ...);

int		manage_flag(const char *flag, va_list args, int *count);
int		is_chars(const char c, const char *str);
int		putstr_len_fill_after_string(char *str, int len, char fill_char);
int		putstr_len_fill_before_string(char *str, int len, char fill_char);
int		putstr_len_fill_after_num(char *str, int len, char fill_char);
int		putstr_len_fill_before_num(char *str, int len, char fill_char);
int		print_flag(const char *start, const char *end);
int		print_sign(const char *start, const char *value_type, char *nb);
int print_with_fill(const char *start, const char *end, char *nb, int print);

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int nb);
char	*ft_uitoa_base(unsigned long nb, char *base, int base_len);
int		ft_putstr(char *str);
int		ft_isdigit(int num);
int		ft_putchar(char c);
int		ft_atoi(const char *str);

#endif
