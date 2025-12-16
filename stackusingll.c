#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int count;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
    s->count = 0;
}

void push(Stack* s, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;

    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    s->count--;
    return val;
}

int peek(Stack* s) {
    if (s->top == NULL) return -1;
    return s->top->data;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void freeStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

// for strings--

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int count;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
    s->count = 0;
}

void push(Stack* s, const char* val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = malloc(strlen(val) + 1);
    strcpy(newNode->data, val);
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
}

char* pop(Stack* s) {
    if (s->top == NULL) return NULL;

    Node* temp = s->top;
    char* val = temp->data;
    s->top = temp->next;
    free(temp);
    s->count--;
    return val;
}

char* peek(Stack* s) {
    if (s->top == NULL) return NULL;
    return s->top->data;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void freeStack(Stack* s) {
    while (!isEmpty(s)) {
        char* str = pop(s);
        free(str);
    }
}
