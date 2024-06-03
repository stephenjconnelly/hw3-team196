#include <stdio.h>
#include <string.h>
#include "linked_list.h"

void do_nothing(void* data) {}

void _print(void* data) {
    char *value = (char *)data;
    printf("\"%s\"", value);
}

int string_compare(const void* a, const void* b) {
    char *str1 = (char*) a;
    char *str2 = (char*) b;
    return strcmp(str1, str2);
}

int main(int argc, char **argv) {
    linked_list* ll = create_linked_list();
    print_list(ll, _print);
    for (int i = 1; i < argc; i++) {
        insert_in_order(ll, argv[i], string_compare);
        print_list(ll, _print);
    }
    
    free_list(ll, do_nothing);
    free(ll);
    return EXIT_SUCCESS;
}
