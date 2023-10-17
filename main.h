#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

#include <stdarg.h>
int _printf(const char *formatString, ...);
int _putchar(char c);
int custom_printf(const char *format, va_list args);
int print_int(int num);
int print_uint(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int uppercase);

#endif
