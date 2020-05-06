
#include<stdlib.h>
#include<stdio.h>
#include"Header.h"


void push(Node** head, int data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


int pop(Node** head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void deleteList(Node** head) {
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}


void printLinkedList(const Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


void merge(Node* a, Node* b, Node** c) {
    Node tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }

    if (a->value > b->value) {
        *c = a;
        a = a->next;
    }
    else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->value > b->value) {
            (*c)->next = a;
            a = a->next;
        }
        else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

int main() {
    Node* a = NULL;
    Node* b = NULL;
    Node* c = NULL;

    int size;
    printf_s("Input A size: "); scanf_s("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int date;
        scanf_s("%d", &date);
        push(&a, date);
    }
    printLinkedList(a);

    printf_s("Input B size: "); scanf_s("%d", &size);
    for (int i = 0; i < size; i++)
    {
        int date;
        scanf_s("%d", &date);
        push(&b, date);
    }
    printLinkedList(b);
    merge(a, b, &c);
    printLinkedList(c);

    return 0;
}


