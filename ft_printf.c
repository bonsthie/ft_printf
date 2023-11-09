#include "ft_printf.h"
#include <stdio.h>

static void ft_putnbr_base(long long n, char *base, int base_size, int *count)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
        (*count)++;
		n = -n;
	}
	if (n >= base_size)
	{
		ft_putnbr_base(n / base_size, base, base_size, count);
		ft_putnbr_base(n % base_size, base, base_size, count);
	}
	else
    {
        ft_putchar_fd(base[n], 1);
        (*count)++;
    }
}

static int manage_char(va_list var, const char type)
{
	char *str;

	if (type == 'c')
	{
		ft_putchar_fd((char) va_arg(var, int), 1);
		return (1);
	}
	str = NULL;
	str = va_arg(var, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int print_variable(va_list var, const char type)
{
	int count;

	count = 0;
	if (type == 'c' || type == 's')
		count = manage_char(var, type);
	else if (type == 'd' || type == 'i')
		ft_putnbr_base(va_arg(var, long long), "0123456789", 10, &count);
	else if (type == 'u')
		ft_putnbr_base(va_arg(var, unsigned long long), "0123456789", 10, &count);
	else if (type == 'x')
		ft_putnbr_base(va_arg(var, unsigned long long), "0123456789abcdef", 16, &count);
	else if (type == 'X')
		ft_putnbr_base(va_arg(var, unsigned long long), "0123456789ABCDEF", 16, &count);
	else if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
        count += 2;
		ft_putnbr_base((unsigned long long) va_arg(var, void *), "0123456789abcdef", 16, &count);
	}
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int     done;

	va_start(args, format);
	done = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				done += print_variable(args, *format);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			done++;
		}
		format++;
	}
	va_end(args);
	return (done);
}
