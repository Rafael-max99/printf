#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *s = NULL;
    void *p = NULL;
    int d = 42;
    int neg = -42;
    int zero = 0;
    unsigned int u = 42;

    printf("== Extended tests for ft_printf (42) ==\n");

    /* Basic specifiers */
    printf("\n-- Basic specifiers --\n");
    printf("printf:    |%c|\n", 'Z'); ft_printf("ft_printf: |%c|\n", 'Z');
    printf("printf:    |%s|\n", "hello"); ft_printf("ft_printf: |%s|\n", "hello");
    printf("printf:    |%%|\n"); ft_printf("ft_printf: |%%|\n");

    /* NULL string with precision/width */
    printf("\n-- String NULL/precision/width --\n");
    printf("printf:    |%.3s|\n", s); ft_printf("ft_printf: |%.3s|\n", s);
    printf("printf:    |%5.3s|\n", s); ft_printf("ft_printf: |%5.3s|\n", s);
    printf("printf:    |%-5.3s|\n", s); ft_printf("ft_printf: |%-5.3s|\n", s);

    /* Pointer tests */
    printf("\n-- Pointer tests --\n");
    printf("printf:    |%p|\n", p); ft_printf("ft_printf: |%p|\n", p);
    p = &d;
    printf("printf:    |%p|\n", p); ft_printf("ft_printf: |%p|\n", p);

    /* Integers: width, precision, signs, zero, space */
    printf("\n-- Integer formatting --\n");
    printf("printf:    |%d| |%5d| |%.5d| |%8.5d|\n", d, d, d, d);
    ft_printf("ft_printf: |%d| |%5d| |%.5d| |%8.5d|\n", d, d, d, d);

    printf("printf:    |%+8.5d| |% 8.5d| |%08d|\n", d, d, d);
    ft_printf("ft_printf: |%+8.5d| |% 8.5d| |%08d|\n", d, d, d);

    printf("printf:    |%+.5d| |% 5d| |%03d|\n", d, d, d);
    ft_printf("ft_printf: |%+.5d| |% 5d| |%03d|\n", d, d, d);

    /* Negatives */
    printf("\n-- Negatives --\n");
    printf("printf:    |%d| |%5d| |%.5d| |%8.5d|\n", neg, neg, neg, neg);
    ft_printf("ft_printf: |%d| |%5d| |%.5d| |%8.5d|\n", neg, neg, neg, neg);

    printf("printf:    |%+8.5d| |% 8.5d| |%08d|\n", neg, neg, neg);
    ft_printf("ft_printf: |%+8.5d| |% 8.5d| |%08d|\n", neg, neg, neg);

    printf("printf:    |%.0d| |%5.0d|\n", zero, zero);
    ft_printf("ft_printf: |%.0d| |%5.0d|\n", zero, zero);

    /* INT min/max */
    printf("\n-- INT min/max --\n");
    printf("printf:    |%d| |%d|\n", INT_MIN, INT_MAX);
    ft_printf("ft_printf: |%d| |%d|\n", INT_MIN, INT_MAX);

    /* Unsigned */
    printf("\n-- Unsigned --\n");
    printf("printf:    |%u| |%5u| |%.5u|\n", u, u, u);
    ft_printf("ft_printf: |%u| |%5u| |%.5u|\n", u, u, u);

    /* Hex with #, 0, width and precision combinations */
    printf("\n-- Hex formatting --\n");
    printf("printf:    |%#08x| |%#8.5x| |%#X|\n", 42, 42, 42);
    ft_printf("ft_printf: |%#08x| |%#8.5x| |%#X|\n", 42, 42, 42);

    printf("printf:    |%#x| |%#.0x| |%#5.0x|\n", 0, 0, 0);
    ft_printf("ft_printf: |%#x| |%#.0x| |%#5.0x|\n", 0, 0, 0);

    /* Mix flags and edge cases */
    printf("\n-- Mixed/edge cases --\n");
    /* space and plus are mutually exclusive; test separately */
    printf("printf:    |%+10.5d|\n", 123);
    ft_printf("ft_printf: |%+10.5d|\n", 123);
    printf("printf:    |% 10.5d|\n", 123);
    ft_printf("ft_printf: |% 10.5d|\n", 123);

    printf("printf:    |%0+5d| |%0 5d|\n", 7, 7);
    ft_printf("ft_printf: |%0+5d| |%0 5d|\n", 7, 7);

    printf("printf:    |%#06x|\n", 0x2a);
    ft_printf("ft_printf: |%#06x|\n", 0x2a);

    return 0;
}