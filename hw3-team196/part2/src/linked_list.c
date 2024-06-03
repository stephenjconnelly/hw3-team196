#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? print_function(list->head->data) :
                         (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ? print_function(list->tail->data) :
                         (void)printf("NULL");
    printf("}\n\n");
}

linked_list* create_linked_list() {
    linked_list* ll = malloc(sizeof(linked_list));
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
    return ll;
}

void free_list(linked_list* ll, void (*free_data)(void *)) {
    if (ll->head == NULL) {
        //list is empty
        return;
    }
    
    node *curr = ll->tail->prev;
    while (curr != NULL) {
        
        free_node(ll->tail, free_data);
        ll->tail = curr;
        curr = curr->prev;
    }
    free_node(ll->head, free_data);
}

bool insert_in_order(linked_list *list, void *data,
                    int (*cmp)(const void*, const void*)) {
    
    node* new_node = create_node(data);
    
    if (list->head == NULL) {
        
        list->head = new_node;
        list->tail = new_node;
        return true;
    }

    

    node *list_node = list->head;
    //compare with head, then head's pointer ...

    do {
        int cmp_result = cmp(list_node->data, data);
        
        //if listnode.data is greater than new_node.data
        if (cmp_result > 0) {
            //if listnode.data is head
            if (list_node == list->head) {
                //new node becomes new head
                new_node->next = list->head;
                list->head->prev = new_node;
                list->head = new_node;
                break;
            } else {
                //newnode goes after listnode
                list_node->prev->next = new_node;
                new_node->prev = list_node->prev;
                list_node->prev = new_node;
                new_node->next = list_node;
                break;
            }

        }

        //if listnode is tail
        if (list_node == list->tail) {
            //if listnode is less than tail
            if (cmp_result < 0){
                new_node->prev = list->tail;
                list->tail->next = new_node;
                list->tail = new_node;
                break;
            }
            
        }
        list_node = list_node->next;
    } while (list_node != NULL);
    
    return false;
}