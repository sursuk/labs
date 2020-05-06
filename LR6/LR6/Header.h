#pragma once

typedef struct{
    int value;
    struct Node* next;
} Node;

int pop(Node **head);
void push(Node **head, int data);
void deleteList(Node **head);
