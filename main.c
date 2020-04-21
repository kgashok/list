#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "list.h"

void list_print(list_node *);

typedef struct node_data { 
    char *type; 
    void *data; 
} node_data;

node_data *create_node_data(const char *type, void *data);

int main() { 
    int a = 5;
    node_data *na = create_node_data("%d", &a);
    list_node *alist = list_create(na);
    int b = 10;
    node_data *nb = create_node_data("%d", &b);
    list_insert_end(alist, nb);
    int c = 20;
    node_data *nc = create_node_data("%d", &c);
    list_insert_end(alist, nc);
    list_print(alist);

    a = 200; b = 100; c = 500; 
    list_print(alist);

    int d = 1000;
    node_data *nd = create_node_data("%d", &d);
    alist = list_insert_beginning(alist, nd);

    list_print(alist);

    char *some_string = "I am a string";
    node_data *ns = create_node_data("%s", some_string);
    list_insert_end(alist, ns);

    list_print(alist);
}


node_data *create_node_data(const char *format, void *data) {
    node_data *nd = malloc(sizeof(node_data *));
    nd->type = malloc(30);
    strcpy(nd->type, format);
    nd->data = data;
    return nd;
}


void print_node_data(node_data *nd) { 
    const char *format = nd->type;
    //printf("format is %s - ", format);
    if (strcmp(format, "%d") == 0) {
        int *data = (int *)nd->data; 
        printf(format, *data);
    }
    else { 
        printf(format, nd->data);
    }
}

/* Print a list
 * Arguments: A pointer to a list
 */
void list_print(list_node *list) 
{
    printf("[");
    while (list) { 
        node_data *n = list->data;
        print_node_data(n);
        list = list->next;
        if (list)
            printf(", ");
    }
    printf("]\n");
}