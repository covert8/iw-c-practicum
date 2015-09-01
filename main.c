#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/**
 * Returns 1 if the given character is a lower case alphabetic character, 0
 * otherwise. You are not allowed to use islower()!
 */
int char_is_lower(char c)
{
    int ascii = (int) c;
    if (ascii > 96 && ascii < 123){
        return 1;
    } else {
        return 0;
    }
}

/**
 * Returns 1 if the given character is an upper case alphabetic character, 0
 * otherwise. You are not allowed to use isupper()!
 */
int char_is_upper(char c)
{
    int ascii = (int) c;
    if (ascii < 91 && ascii > 64){
        return 1;
    } else {
    return 0;
    }
}

/**
 * If an upper case character is given, the lower case version is returned and
 * vice versa. If the given character is not alphabetic, it is returned
 * unchanged. you are not allowed to use toupper() or tolower()!
 */
char char_change_case(char c)
{
    if (char_is_upper(c) == 1){
        int ascii =  c;
        ascii += 32;
        return (char) ascii;
    }
    if (char_is_lower(c) == 1){
        int ascii = c;
        ascii -= 32;
        return (char) ascii;
    }
    return c;
}

/**
 * Returns a new string where each character has the opposite case as the
 * corresponding character in the given string. The same case changing rules
 * apply as for char_change_case(). If the given string is NULL or there is not
 * enough memory to create the new string, NULL is returned.
 */
char* string_change_case(const char* s)
{
    if (s == NULL){
        return NULL;
    }
    if (*s == NULL){
        char* c = malloc(sizeof (char));
        return c;
    }
    char* string = malloc(sizeof s);
    for (int i = 0; *s != '\0';i++){
        *(string + i) = char_change_case(*s++);
    }
    return string;
}

int test_string_change_case(const char* input, const char* expected_output)
{
    char* output = string_change_case(input);
    int result = strcmp(output, expected_output) == 0;
    free(output);
    return result;
}

int main()
{
    // assert() gives an error if the given expression is not true
    assert(char_is_lower('l'));
    assert(!char_is_lower('L'));
    assert(!char_is_lower('@'));
    assert(char_is_upper('U'));
    assert(!char_is_upper('u'));
    assert(!char_is_upper('%'));
    assert(char_change_case('J') == 'j');
    assert(char_change_case('c') == 'C');
    assert(char_change_case('&') == '&');
    assert(test_string_change_case("Foo+Bar!", "fOO+bAR!"));
    assert(test_string_change_case("", ""));
    assert(string_change_case(NULL) == NULL);

    puts("All tests passed!");
    return EXIT_SUCCESS;
}

