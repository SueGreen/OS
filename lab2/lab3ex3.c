//
// Created by Сюзанна on 05.09.2018.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


struct Node {
    int data;
    struct Node *next;
};

static int count = 0;

struct Node *head = NULL;
struct Node *current = NULL;

int insert_node(int value) {
    if (count == 0) {
        current = malloc(sizeof(struct Node));
        current->data = value;
        head = current;
        current->next = NULL;
    } else {
        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    count++;
    return 0;
}

void print_list() {
    struct Node *temp_current = head;
    for (int i = 0; i < count; ++i) {
        printf("%d, ", temp_current->data);
        temp_current = temp_current->next;
    }
}

int delete_elem(int value) {

    struct Node *temp_current = head;
    struct Node *prev = head;
    if (count == 0 || head == NULL) return -1;

    if (temp_current != NULL && temp_current->data == value) {
        head = temp_current->next;
        free(temp_current);
        return 0;
    }

    while ( temp_current!= NULL && temp_current->data != value) {
        prev = temp_current;
        temp_current = temp_current->next;
    }

    if (temp_current == NULL){
        free(temp_current);
        return -1;}
    prev->next = temp_current->next;
    free(temp_current);
    count--;
}

int main() {
    insert_node(1);
    insert_node(3);
    insert_node(6);
    print_list();
    delete_elem(3);
    printf("%s", "\n");
//    printf("%d", delete_elem(1));
    print_list();
}


