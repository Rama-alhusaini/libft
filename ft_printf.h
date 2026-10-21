#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char chr);
int	ft_putstr(char *str);
int	ft_putptr(void *s);
int	ft_puti_d(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n);
int	ft_puthex_upper(unsigned int n);

#endif
