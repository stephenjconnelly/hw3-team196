#include <stddef.h>
#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Take an array of char* pointers and print each of the strings to standard
 * out. This function must use only pointer arithmetic and no array
 * subscripting. The output start with "[", ends with "]\n", and prints the
 * strings inside, each separated by a comma and space.
 * Example: [Hi, BYE, AP, COMSW 3157, FunTimes]
 */
void display_strings(char **strings) {
    printf("[");
    if (*strings != NULL) {
        printf("%s", *strings++);
        while (*strings != NULL) {             
            printf(", %s", *strings++);
        }
    }
    printf("]\n");
}

static char **copy_args_lowercase(int argc, char **argv) {

    char **copy = malloc((argc) * sizeof(char *));
    if (copy == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
    }
    for (int i = 1; i < argc; i++) {
        size_t length = my_strlen(argv[i]);
        copy[i-1] = malloc(length * sizeof(char) + 1);
        if (copy[i-1] == NULL) {
            fprintf(stderr, "Error: malloc failed\n");
        }
        my_strcpy(copy[i-1], argv[i]);
        my_strlower(copy[i-1]);
    }

    copy[argc-1] = NULL;

    return copy;
}

static void free_copy(char **copy) {
    //free everything using for loop 
    for(int i = 0; copy[i] != NULL; i++) {
    	free(copy[i]);
    }
    free(copy);
    return;
}


/**
 * DO NOT MODIFY main()
 */
int main(int argc, char **argv) {
    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments       : ");
    display_strings(argv + 1);

    printf("Lowercase arguments : ");
    display_strings(copy);

    free_copy(copy);

    return EXIT_SUCCESS;
}
