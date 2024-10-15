#include <stdio.h>
#include <limits.h>
#include "ft_printf.h" // Include your ft_printf header

int main(void) {
    char *null_str = NULL;
    void *ptr = (void *)0x12345678;

    // Test characters
    printf("return ft:%d\n", ft_printf("output: %c\n", 'a'));
    printf("return :%d\n", printf("output: %c\n", 'a'));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %c\n", '\0'));
    printf("return :%d\n", printf("output: %c\n", '\0'));
    printf("\n");

    // Test strings
    printf("return ft:%d\n", ft_printf("output: %s\n", "Hello, world!"));
    printf("return :%d\n", printf("output: %s\n", "Hello, world!"));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %s\n", ""));
    printf("return :%d\n", printf("output: %s\n", ""));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %s\n", null_str));
    printf("return :%d\n", printf("output: %s\n", null_str));
    printf("\n");

    // Test integers
    printf("return ft:%d\n", ft_printf("output: %d\n", 42));
    printf("return :%d\n", printf("output: %d\n", 42));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %d\n", -42));
    printf("return :%d\n", printf("output: %d\n", -42));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %d\n", INT_MAX));
    printf("return :%d\n", printf("output: %d\n", INT_MAX));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %d\n", INT_MIN));
    printf("return :%d\n", printf("output: %d\n", INT_MIN));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %i\n", 42));
    printf("return :%d\n", printf("output: %i\n", 42));
    printf("\n");

    // Test unsigned integers
    printf("return ft:%d\n", ft_printf("output: %u\n", 42));
    printf("return :%d\n", printf("output: %u\n", 42));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %u\n", UINT_MAX));
    printf("return :%d\n", printf("output: %u\n", UINT_MAX));
    printf("\n");

    // Test hexadecimal
    printf("return ft:%d\n", ft_printf("output: %x\n", 0xabcdef));
    printf("return :%d\n", printf("output: %x\n", 0xabcdef));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %X\n", 0xABCDEF));
    printf("return :%d\n", printf("output: %X\n", 0xABCDEF));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %x\n", 0));
    printf("return :%d\n", printf("output: %x\n", 0));
    printf("\n");

    // Test pointers
    printf("return ft:%d\n", ft_printf("output: %p\n", ptr));
    printf("return :%d\n", printf("output: %p\n", ptr));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %p\n", NULL));
    printf("return :%d\n", printf("output: %p\n", NULL));
    printf("\n");

    // Test percent sign
    printf("return ft:%d\n", ft_printf("output: %%\n"));
    printf("return :%d\n", printf("output: %%\n"));
    printf("\n");

    // Test multiple conversions
    printf("return ft:%d\n", ft_printf("output: %c %s %d %u %x %X %p %%\n", 'A', "test", -42, 42, 0xabcdef, 0xABCDEF, ptr));
    printf("return :%d\n", printf("output: %c %s %d %u %x %X %p %%\n", 'A', "test", -42, 42, 0xabcdef, 0xABCDEF, ptr));
    printf("\n");

    // Test with field width (if implemented)
    printf("return ft:%d\n", ft_printf("output: %5d\n", 42));
    printf("return :%d\n", printf("output: %5d\n", 42));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %5s\n", "abc"));
    printf("return :%d\n", printf("output: %5s\n", "abc"));
    printf("\n");

    // Test with precision (if implemented)
    printf("return ft:%d\n", ft_printf("output: %.3d\n", 42));
    printf("return :%d\n", printf("output: %.3d\n", 42));
    printf("\n");

    printf("return ft:%d\n", ft_printf("output: %.3s\n", "abcdef"));
    printf("return :%d\n", printf("output: %.3s\n", "abcdef"));
    printf("\n");

    return 0;
}
