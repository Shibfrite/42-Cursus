#include <stdio.h>
#include "ft_printf.h"  // Include your ft_printf header file

int main()
{
    printf("Test 1:\n");
    printf("ft_printf: ["); ft_printf("%5%"); printf("]\n");
    printf("printf:    ["); printf("%5%"); printf("]\n\n");

    printf("Test 2:\n");
    printf("ft_printf: ["); ft_printf("%-5%"); printf("]\n");
    printf("printf:    ["); printf("%-5%"); printf("]\n\n");

    printf("Test 3:\n");
    printf("ft_printf: ["); ft_printf("%-05%"); printf("]\n");
    printf("printf:    ["); printf("%-05%"); printf("]\n\n");

    printf("Test 4:\n");
    printf("ft_printf: ["); ft_printf("%23s", NULL); printf("]\n");
    printf("printf:    ["); printf("%23s", NULL); printf("]\n\n");

    printf("Test 5:\n");
    printf("ft_printf: ["); ft_printf("%32s", NULL); printf("]\n");
    printf("printf:    ["); printf("%32s", NULL); printf("]\n\n");

    printf("Test 6:\n");
    printf("ft_printf: ["); ft_printf("%2s", NULL); printf("]\n");
    printf("printf:    ["); printf("%2s", NULL); printf("]\n\n");

    printf("Test 7:\n");
    printf("ft_printf: ["); ft_printf("%-32s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-32s", NULL); printf("]\n\n");

    printf("Test 8:\n");
    printf("ft_printf: ["); ft_printf("%-16s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-16s", NULL); printf("]\n\n");

    printf("Test 9:\n");
    printf("ft_printf: ["); ft_printf("%-3s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-3s", NULL); printf("]\n\n");

    printf("Test 10:\n");
    printf("ft_printf: ["); ft_printf("%.03s", NULL); printf("]\n");
    printf("printf:    ["); printf("%.03s", NULL); printf("]\n\n");

    printf("Test 11:\n");
    printf("ft_printf: ["); ft_printf("%3.1s", NULL); printf("]\n");
    printf("printf:    ["); printf("%3.1s", NULL); printf("]\n\n");

    printf("Test 12:\n");
    printf("ft_printf: ["); ft_printf("%9.1s", NULL); printf("]\n");
    printf("printf:    ["); printf("%9.1s", NULL); printf("]\n\n");

    printf("Test 13:\n");
    printf("ft_printf: ["); ft_printf("%-3.1s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-3.1s", NULL); printf("]\n\n");

    printf("Test 14:\n");
    printf("ft_printf: ["); ft_printf("%-9.1s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-9.1s", NULL); printf("]\n\n");

    printf("Test 15:\n");
    printf("ft_printf: ["); ft_printf("%3.6s", NULL); printf("]\n");
    printf("printf:    ["); printf("%3.6s", NULL); printf("]\n\n");

    printf("Test 16:\n");
    printf("ft_printf: ["); ft_printf("%20.6s", NULL); printf("]\n");
    printf("printf:    ["); printf("%20.6s", NULL); printf("]\n\n");

    printf("Test 17:\n");
    printf("ft_printf: ["); ft_printf("%-3.8s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-3.8s", NULL); printf("]\n\n");

    printf("Test 18:\n");
    printf("ft_printf: ["); ft_printf("%-10.8s", NULL); printf("]\n");
    printf("printf:    ["); printf("%-10.8s", NULL); printf("]\n\n");

    printf("Test 19:\n");
    printf("ft_printf: ["); ft_printf("%7i", -14); printf("]\n");
    printf("printf:    ["); printf("%7i", -14); printf("]\n\n");

    printf("Test 20:\n");
    printf("ft_printf: ["); ft_printf("%10.5i", -216); printf("]\n");
    printf("printf:    ["); printf("%10.5i", -216); printf("]\n\n");

    return 0;
}
