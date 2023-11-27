/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:23:59 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/27 01:15:37 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSER_H
#define FORMAT_PARSER_H

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef enum {
    FMT_CHAR = 'c',
    FMT_STR = 's',
    FMT_PTR = 'p',
    FMT_DEC = 'd',
    FMT_INT = 'i',
    FMT_UINT = 'u',
    FMT_HEX_LOW = 'x',
    FMT_HEX_UP = 'X',
    FMT_PERCENT = '%',
    FMT_WRONG = INT_MIN
} e_format;

typedef enum {
    FLAG_NONE,
    FLAG_PLUS,
    FLAG_HASH
} e_precision_flags;

typedef enum {
    LENGTH_NONE,
    LENGTH_SPACE,
    LENGTH_DOT,
    LENGTH_MINUS
} e_length_flags;

typedef struct s_flag
{
    e_format format;
    e_precision_flags precision_flag;
    e_length_flags length_flag_zero;
    int             length_zero;
    e_length_flags length_flag_space;
    int             length_space;
    struct s_flag   *next;
} t_flag;


void    clear_all(t_flag *head);

#endif
