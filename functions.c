#include "main.h"

/**
 * _printf - Custom printf function handling c, s and % specifiers.
 * @format: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list list;
    int i = 0, printed_chars = 0;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            printed_chars++;
        }
        else
        {
            i++;  /* Move to the character after % */

            switch (format[i])
            {
                case 'c':
                    _putchar(va_arg(list, int));
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(list, char*);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                    {
                        _putchar(*str++);
                        printed_chars++;
                    }
                    break;
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    /* If not a recognized specifier, print both characters. */
                    _putchar('%');
                    _putchar(format[i]);
                    printed_chars += 2;
                    break;
            }
        }
        i++;
    }

    va_end(list);

    return (printed_chars);
}

/**
 * _putchar - Writes a character to standard output.
 * @c: character to print.
 * Return: Number of characters printed.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}
