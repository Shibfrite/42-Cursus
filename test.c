#include"ft_printf.h" // Include your ft_printf header

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
    int ret;

	// Basic tests
    ft_printf("-------- Basic Tests --------\n");
    ret = ft_printf("Hello, world!\n");
    ft_printf("Return value: %d\n\n", ret);

    // Character tests
    ft_printf("-------- Character Tests --------\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Character: %c\n", 0);
    ft_printf("Character: %5c\n", 'B');
    ft_printf("Character: %-5c\n", 'C');

    // String tests
    ft_printf("\n-------- String Tests --------\n");
    ft_printf("String: %s\n", "Hello");
    ft_printf("String: %1s\n", "Hello");
    ft_printf("String: %-10s\n", "Left");
    ft_printf("String: %.3s\n", "Truncate");
    ft_printf("String: %10.5s\n", "Precision");
    ft_printf("Null string: %s\n", NULL);

    // Integer tests
    ft_printf("\n-------- Integer Tests --------\n");
    ft_printf("Integer: %i\n", 42);
    ft_printf("Integer: %d\n", -42);
    ft_printf("Integer: %5d\n", 42);
    ft_printf("Integer: %05d\n", 42);
    ft_printf("Integer: %-5d\n", 42);
    ft_printf("Integer: %+d\n", 42);
    ft_printf("Integer: % d\n", 42);
    ft_printf("Long: %ld\n", LONG_MAX);
    ft_printf("Long: %ld\n", LONG_MIN);

    // Unsigned integer tests
    ft_printf("\n-------- Unsigned Integer Tests --------\n");
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Unsigned: %u\n", -42);
    ft_printf("Unsigned Long: %lu\n", ULONG_MAX);

    // Hexadecimal tests
    ft_printf("\n-------- Hexadecimal Tests --------\n");
    ft_printf("Hex (lowercase): %x\n", 255);
    ft_printf("Hex (uppercase): %X\n", 255);
    ft_printf("Hex with #: %#x\n", 255);
    ft_printf("Hex with 0: %0#8x\n", 255);

    // Pointer tests
    ft_printf("\n-------- Pointer Tests --------\n");
    int num = 42;
    ft_printf("Pointer: %p\n", (void*)&num);
    ft_printf("Null pointer: %p\n", NULL);

    // Percentage sign test
    ft_printf("\n-------- Percentage Sign Test --------\n");
    ft_printf("Percentage sign: %%\n");

    // Mixed format string
    ft_printf("\n-------- Mixed Format String --------\n");
    ft_printf("Mixed: %d %s %c %x %p %%\n", 42, "test", 'Z', 255, (void*)&num);

    // Edge cases
    ft_printf("\n-------- Edge Cases --------\n");
    ft_printf("Empty format string: ");
    ret = ft_printf("");
    ft_printf("\nReturn value: %d\n", ret);
    ft_printf("Only percentage: ");
    ret = ft_printf("%");
    ft_printf("\nReturn value: %d\n", ret);

    // Precision and width combinations
    ft_printf("\n-------- Precision and Width Combinations --------\n");
    ft_printf("Integer: %10.5d\n", 123);
    ft_printf("Integer: %-10.5d\n", 123);
    ft_printf("String: %10.5s\n", "Hello, world!");
    ft_printf("Hex: %#10.5x\n", 123);

    return 0;
}
