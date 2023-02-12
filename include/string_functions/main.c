#include <stdio.h>

#include "string_functions.h"

int main()
{
    char str[] = "Extenction";
    char empty[] = "";
    char str5[6];
    char str10[11];
    char str15[16];

    printf("str length = %lu\n", string_length(str));
    printf("str length = %lu\n", string_length(empty));

    printf("%s\n", str);
    string_reverse(str);
    printf("%s\n", str);
    string_reverse(str);

    string_copy(str, str5, 5);
    string_copy(str, str10, 10);
    string_copy(str, str15, 15);

    printf("str == str10 -> %d, str == str5 -> %d\n", string_compare(str, str10), string_compare(str, str5));

    printf("str = %s\n", str    );
    printf("str5 = %s\n", str5);
    printf("str10 = %s\n", str10);
    printf("str15 = %s\n", str15);

    return 0;
}