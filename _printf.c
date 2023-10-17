#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
        va_list args;
        int printed_chars;
        printed_chars = 0;
        

        va_start(args, format);
        printed_chars = custom_printf(format, args);
        va_end(args);

        return printed_chars;
}

int custom_printf(const char *format, va_list args)
{
        int printed_chars;
        printed_chars = 0;
        while (*format)
        {
            if (*format != '%')
            {
                putchar(*format);
                printed_chars++;
            }
            else
            {
                format++;
                if (*format == '\0')
                    return -1;

                if (*format == '%')
                {
                    putchar('%');
                    printed_chars++;
                }
                else if (*format == 'c')
                {
                    char c;
                    c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                }
                else if (*format == 's')
                {
                    char *s = va_arg(args, char *);
                    if (s == NULL)
                        s = "(null)";
                    while (*s)
                    {
                        putchar(*s);
                        s++;
                        printed_chars++;
                    }
                }
                else if (*format == 'd' || *format == 'i')
                {
                    int num;
                    num = va_arg(args, int);
                    printed_chars += print_int(num);
                }
                else if (*format == 'u')
                {
                    unsigned int num;
                    num = va_arg(args, unsigned int);
                    printed_chars += print_uint(num);
                }
                else if (*format == 'o')
                {
                    unsigned int num;
                    num = va_arg(args, unsigned int);
                    printed_chars += print_octal(num);
                }
                else if (*format == 'x' || *format == 'X')
                {
                    unsigned int num;
                    num = va_arg(args, unsigned int);
                    printed_chars += print_hex(num, (*format == 'X'));
                }
                
            }
            format++;
        }
        return printed_chars;
}

int print_int(int num)
{
        int printed_chars = 0;
        if (num < 0)
        {
            putchar('-');
            num = -num;
            printed_chars++;
        }
        if (num >= 10)
            printed_chars += print_int(num / 10);
        putchar('0' + num % 10);
        printed_chars++;
        return printed_chars;
}

int print_uint(unsigned int num)
{
        int printed_chars = 0;
        if (num >= 10)
            printed_chars += print_uint(num / 10);
        putchar('0' + num % 10);
        printed_chars++;
        return printed_chars;
}

int print_octal(unsigned int num)
{
        int printed_chars = 0;
        if (num >= 8)
            printed_chars += print_octal(num / 8);
        putchar('0' + num % 8);
        printed_chars++;
        return printed_chars;
}

int print_hex(unsigned int num, int uppercase)
{
        int printed_chars = 0;
        char hex_chars[] = "0123456789abcdef";
        if (uppercase)
            hex_chars[10] = 'A';
        if (num >= 16)
            printed_chars += print_hex(num / 16, uppercase);
        putchar(hex_chars[num % 16]);
        printed_chars++;
        return printed_chars;
}
