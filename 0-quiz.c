#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 * @format: the format.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
int j, num = 0, num_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list args;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(args, format);

for (j = 0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
buffer[buff_ind++] = format[j];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[j], 1);*/
num_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = the_flags(format, &j);
width = the_width(format, &j, args);
precision = the_precision(format, &j, args);
size = the_size(format, &j);
++j;
num = handle_print(format, &j, args, buffer, flags, width, precision, size);
if (num == -1)
return (-1);
num_chars += num;
}
}

print_buffer(buffer, &buff_ind);

va_end(args);

return (num_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}

