#include <stdio.h>
#include "ft_printf.h"

int main()
{
    // Character tests
    ft_printf("Basic char: %c\n", 'A');
    printf("Basic char: %c\n", 'A');
    
    ft_printf("Digit as char: %c\n", '7');
    printf("Digit as char: %c\n", '7');
    
    ft_printf("Special char: %c\n", '!');
    printf("Special char: %c\n", '!');
    
    ft_printf("ASCII range:\n");
    printf("ASCII range:\n");
    for (int i = 32; i <= 126; i++) {
        ft_printf("%c", i);
        printf("%c", i);
    }
    ft_printf("\n");
    printf("\n");
    
    ft_printf("Null char: %c.\n", '\0');
    printf("Null char: %c.\n", '\0');
    
    ft_printf("Multiple chars: %c %c %c\n", 'X', 'Y', 'Z');
    printf("Multiple chars: %c %c %c\n", 'X', 'Y', 'Z');

    // String tests
    ft_printf("Simple string: %s\n", "Hello, World!");
    printf("Simple string: %s\n", "Hello, World!");
    
    ft_printf("Empty string: %s\n", "");
    printf("Empty string: %s\n", "");
    
    ft_printf("String with spaces: %s\n", "This is a test");
    printf("String with spaces: %s\n", "This is a test");
    
    ft_printf("String with symbols: %s\n", "!@#$%^&*()");
    printf("String with symbols: %s\n", "!@#$%^&*()");
    
    ft_printf("Long string: %s\n", "This is a very long string that goes on and on and on...");
    printf("Long string: %s\n", "This is a very long string that goes on and on and on...");
    
    ft_printf("Multiple strings: %s %s %s\n", "One", "Two", "Three");
    printf("Multiple strings: %s %s %s\n", "One", "Two", "Three");
    
    ft_printf("Null string: %s\n", NULL);
    printf("Null string: %s\n", NULL);

    // Mixed tests
    ft_printf("Mixed: %c %s %c\n", 'A', "Middle", 'Z');
    printf("Mixed: %c %s %c\n", 'A', "Middle", 'Z');

    // Edge cases
    ft_printf("No arguments: %c %s\n");
    printf("No arguments: %c %s\n");
    
    ft_printf("Wrong type for %%c: %c\n", "string");
    printf("Wrong type for %%c: %c\n", "string");
    
    ft_printf("Wrong type for %%s: %s\n", 'c');
    printf("Wrong type for %%s: %s\n", 'c');
    
    ft_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
    printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
    
    ft_printf("%s%s%s\n", "Hello", ", ", "World!");
    printf("%s%s%s\n", "Hello", ", ", "World!");

    return 0;
}
