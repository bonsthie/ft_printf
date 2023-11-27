/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:38:21 by bbonnet           #+#    #+#             */
/*   Updated: 2023/11/26 08:51:25 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parser.h"
#include "create_flag.h"
#include "libft.h"

void    clear_all(t_flag *head)
{
    t_flag	*node;
    t_flag	*node_next;

    if (!head)
        return ;
    node = head;
    while (node)
    {
        node_next = node->next;
        free(node);
        node = node_next;
    }
    head = NULL;
}

const char	*find_value_type(const char *flag)
{
	if (!flag)
		return (NULL);
	while (ft_strchr("0.-+ #", *flag) || ft_isdigit(*flag))
		flag++;
	return (flag);
}

t_flag *create_flag_select(const char *format)
{
    t_flag *new;
    const char *end_flag;

    end_flag = find_value_type(format);
    if (*end_flag == 'c')
        new = create_flag(format, end_flag, '\0', " -");
    else if (*end_flag == 's')
        new = create_flag(format, end_flag, '\0', " -");
    else if (*end_flag == 'i' || *end_flag == 'd')
        new = create_flag(format, end_flag, '+', " -.0");
    else if (*end_flag == 'u')
        new = create_flag(format, end_flag, '\0', " -.0");
    else if (*end_flag == 'x')
        new = create_flag(format, end_flag, '#', " -.0");
    else if (*end_flag == 'X')
        new = create_flag(format, end_flag, '#', " -.0");
    else if (*end_flag == 'p')
        new = create_flag(format, end_flag, '\0', "\0");
    else
        new = create_flag(format, end_flag, '\0', "\0");
    return (new);    
}

t_flag  *format_parsing(const char *format, int *status)
{
    t_flag *head;
    t_flag *last;
    t_flag *new;

    head = NULL;
    last = NULL;
    while (*format)
    {
        if (*format == '%')
        {
            if (*format++)
            {
                new = create_flag_select(format);
                if (!new)
                {
                    clear_all(head);
                    *status = -1;
                    return (NULL);
                }
                if (!head)
                    head = new;
                else 
                    last->next = new;
                last = new;
            }
            else
                *status = (-1);
        }
        else
            format++;
    }
    return (head);
}

