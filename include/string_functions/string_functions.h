/*  reverses a string e.g in: "string", out: "gnirts"
    */
void string_reverse(char * str);

/*  Copies the first (number_of_characters) from the source character string into the destination string,
    if the source string is shorter than str_length, only characters up to the source length are copied followed by the string terminator (0 or \0)
    */
void string_copy(const char * source, char * destination, size_t number_of_characters);

/*  Compares Two character Strings ASCII values from left to right and returns:
    a positive value if the first string is of higher ASCII value e.g "asb" > "asa"
    a negative value if the second string is of higher ASCII value e.g "asw" < "asa"
    a 0 if both strings are of the same value 
    */
int string_compare(const char * str1, const char * str2);

//todo
/*  Compares Two character Strings Alphabetical values then ASCII values from left to right and returns:
    a positive value if the first string is of higher Alphabetical value e.g "Asb" > "AsA"
    a negative value if the second string is of higher Alphabetical value e.g "Asw" < "asA"
    a 0 if both strings are of the same value
    Notes:
        Alphabitical characters have higher value than all other ASCII values,
        if the characters compared are not alphabatical, their ASCII values are compared.
    */
int string_alphabetic_compare(const char * str1, const char * str2);

/*  returns the length of a character string, number of characters in the string
    */
size_t string_length(const char * str);

/*  swaps two string characters up to the (no_of_characters) index
    */
void string_swap(char * str1, char * str2, size_t no_of_characters);