#include "ft_printf.h"

static int print_variable(va_list var, const char type)
{
	int count;

	count = 0;
	if (type == 'c' || type == 's')
		count = manage_char(var, type);
	else if (type == 'd' || type == 'i')
		ft_putnbr_count(va_arg(var, long long), &count);
	else if (type == 'u')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789", 10, &count);
	else if (type == 'x')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789abcdef", 16, &count);
	else if (type == 'X')
		ft_putnbr_base(va_arg(var, unsigned int), "0123456789ABCDEF", 16, &count);
	else if (type == 'p')
			count += print_pointer((unsigned long) va_arg(var, void *));
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	else
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
