#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node *next;
    char val;
}Node;

typedef struct{
    struct Node *top;
    int count;
} stack;

stack * initstack(){
    stack *s = (stack *)malloc(sizeof(stack));
    s -> count = 0;
    s -> top = NULL;
    return s;
}

int isEmpty(stack *s){
    if(s -> top == NULL){
        return 1;
    }
    return 0;
}

char peek(stack *s){
    if(s -> top == NULL){
        return '\0';
    }
    return(s -> top -> val);
}

void push(stack *s , char val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> val = val;
    newNode -> next = s -> top;
    s -> top = newNode;
    s -> count++;
}

char pop(stack *s){
    if(s -> top == NULL){
        return '\0';
    }
    Node *delNode = s -> top;
    char val = delNode -> val;
    s -> top = delNode -> next;
    free(delNode);
    s -> count--;
    return val;
}

void freeStack(stack *s) {
    while(!isEmpty(s)) pop(s);
    free(s);
}

char match(char c){
    if(c == ')'){
        return '(';
    }
    else if(c == '}'){
        return '{';
    }
    else if(c == ']'){
        return '[';
    }
    else{
        return '\0';
    }
}


bool isValid(char* s) {
    stack *st = initstack();
    for(int i = 0 ; s[i] != '\0' ; i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(st , ch);
        }
        else{
            if(isEmpty(st)){
                return 0;
            }
            if(peek(st) == match(ch)){
                pop(st);
            }
            else{
                return 0;
            }
        }
    }
    bool isValid = isEmpty(st);
    return isValid;
}