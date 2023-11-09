#include <stdio.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putstr_fd(char *str, int fd)
{
    while(*str)
        write(fd, str++, 1);
}

void ft_putnbr_hex_fd(unsigned long n, int fd) {
    char *hex = "0123456789abcdef";

    if (n >= 16) {
        ft_putnbr_hex_fd(n / 16, fd);
        ft_putnbr_hex_fd(n % 16, fd);
    } else {
        ft_putchar_fd(hex[n], fd);
    }
}


int main()
{
    long i = 12;

    ft_putnbr_hex_fd((unsigned long)&i, 1);
    write(1, "\n", 1);
    printf("%p", &i);
    
}


