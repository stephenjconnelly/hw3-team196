/* No additional imports are allowed */
#include "mystring.h"
#include <stddef.h>

/**
 * This function calculates the length of a character array passed in,
 * returning the length as a size_t. Calculation must be done via pointer
 * arithmetic. No credit will be given for calling strlen() in <string.h>.
 *
 * src: character array, possibly NULL (which will be considered length 0)
 *
 * return: length of src as a size_t
 */
size_t my_strlen(char *src){
    size_t length  = 0;
    if(*src == '\0'){

        length = 0;   
        return length;
    } 
    for (int i = 0; src[i] != '\0'; i++){
        length++;
    }

    return length;
}

/**
 * This function copies a character array src into dest. The caller must ensure
 * that the length of dst is at least length of src plus one. This function then
 * returns a pointer to dst. Computation must be done via pointer arithmetic.
 * No credit will be given for calling memcpy() in <string.h>.
 *
 * dst: target character array
 * src: source character array, possibly NULL
 *
 * return: pointer to dst
 *         If src is NULL, return NULL.
 */
char *my_strcpy(char *dst, char *src){
    while ((*dst = *src) != '\0'){
        src++;
        dst++;
    }
    *dst = '\0';
    return dst;
}

/**
 * This function loops over the character array src, converting any uppercase
 * character to lowercase. You must use tolower() from <ctype.h> in this
 * function's implementation.
 *
 * src: source character array, possibly NULL
 *
 * return: void
 */
void my_strlower(char *src){
    while (*src != '\0'){
	*src = tolower(*src);    
        src++;
    }
}
