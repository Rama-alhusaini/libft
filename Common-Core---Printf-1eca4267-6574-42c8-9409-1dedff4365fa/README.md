*This activity has been created as part of the 42 curriculum by ralhusai.*

# ft_printf

## Description

The `ft_printf` project is part of the 42 curriculum. Its goal is to recreate the basic behavior of the standard C `printf()` function.

The function processes a format string containing regular characters and conversion specifiers. It uses variadic arguments to receive different types of arguments and prints the corresponding values using the `write()` system call.

This project helps develop a better understanding of C programming, variadic functions, recursion, and character handling.

### Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

The project uses a Makefile to compile the source files into a static library named `libftprintf.a`.

Run the following command from the project directory:

```bash
make
```

Available Makefile rules:

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild the library
```

### Usage

Include the project header in your C source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    return (0);
}
```

Compile the program and link the library:

```bash
cc main.c -L. -lftprintf -o test
```

Run the executable:

```bash
./test
```

## Algorithm and Data Structure

### Algorithm

The function processes the format string from left to right.

1. Initialize a counter to track the number of characters printed.
2. Start processing the variable arguments using `va_start()`.
3. Read each character in the format string.
4. If the character is not a format specifier, print it using `write()`.
5. If a `%` character is encountered, examine the following character to identify the conversion specifier.
6. Retrieve the corresponding argument using `va_arg()` and call the appropriate helper function.
7. Add the number of printed characters to the counter.
8. Finish processing the arguments using `va_end()` and return the total number of characters printed.

### Recursive Number Conversion

Recursive functions are used to print decimal and hexadecimal numbers in the correct order.

For decimal numbers, the function uses division and remainder with base 10. For hexadecimal numbers, it uses base 16.

The function first processes the higher-order digits by calling itself with the number divided by the base. It then prints the current digit using the remainder.

Lowercase and uppercase hexadecimal conversions use different character tables.

For signed integers, the negative sign is printed separately. A wider integer type can be used to handle the minimum integer value safely when converting it to a positive value.

### Data Structures

The project mainly uses simple C data types and does not require complex data structures.

- **Format string:** A character array containing regular characters and conversion specifiers.
- **Index:** An integer used to track the current position in the format string.
- **Character counter:** An integer used to count the characters printed.
- **`va_list`:** A standard C type used to access the variable arguments passed to `ft_printf()`.
- **Temporary variables:** Used to store characters, numeric values, and function return values.

### Justification of the Algorithm and Data Structures

Processing the format string sequentially makes the implementation straightforward because each character is examined in order.

Helper functions separate the printing logic for different data types, making the code easier to understand, test, and maintain.

Recursion provides a simple way to print numeric digits in the correct order without requiring an additional array to reverse them.

The `va_list` mechanism is suitable because `ft_printf()` accepts a variable number of arguments, similar to the standard `printf()` function.

## Resources

### Documentation

- [42 School](https://42.fr/) — Information about the 42 curriculum.
- [printf(3) Manual](https://man7.org/linux/man-pages/man3/printf.3.html) — Standard `printf()` behavior and conversion specifiers.
- [C Variadic Functions](https://en.cppreference.com/w/c/variadic.html) — Documentation about variable arguments.
- [write(2) Manual](https://man7.org/linux/man-pages/man2/write.2.html) — Documentation about the `write()` system call.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) — Documentation about Makefiles and compilation.

### AI Usage

AI tools were used as a learning aid during the development of this project. They helped explain C programming concepts, variadic functions, recursion, format specifiers, and error handling.

AI was also used to discuss implementation choices, understand compiler and Norminette errors, and organize the project documentation.

The author is responsible for understanding, reviewing, and verifying the final implementation.

## Project Structure

- `ft_printf.c` — Main function and format-string processing.
- `ft_printf.h` — Function prototypes and required header files.
- `ft_putchar.c` — Prints a single character.
- `ft_putstr.c` — Prints a string.
- `ft_putptr.c` — Prints a pointer address.
- `ft_puti_d.c` — Prints signed decimal integers.
- `ft_putunsigned.c` — Prints unsigned decimal integers.
- `ft_puthex.c` — Prints lowercase hexadecimal numbers.
- `ft_puthex_upper.c` — Prints uppercase hexadecimal numbers.
- `Makefile` — Compiles the static library.

## Author

Rama Al-Husseini

