#include <stddef.h>

#include "string_functions.h"

void string_reverse(char * str)
{
    char * end = str;
    // get to the end of the string
    while(*(end++));
    end--;
    // reverse string
    while(str < --end)
    {
        *str ^= *end;
        *end ^= *str;
        *str++ ^= *end;
    }
}

size_t string_length(const char * str)
{
    const char * str_end = str;
    while(*str_end++);
    return str_end - str - 1;
}

void string_copy(const char * source, char * destination, size_t number_of_characters)
{
    while(number_of_characters-- && (*destination++ = *source++)){};
    // if the string is not terminated add a string terminator at the end of the string
    if(*(destination - 1))
        *destination = 0;
}

int string_compare(const char * str1, const char * str2)
{
    while(*str1 && *str2 && *str1++ == *str2++);

    if(*str1 && *str2)
        str1--, str2--;
    return *str1 - *str2;
}

void string_swap(char * str1, char * str2, size_t no_of_characters)
{
    for(; no_of_characters; no_of_characters--)
    {
        *str1 ^= *str2;
        *str2 ^= *str1;
        *str1++ ^= *str2++;
    }
}