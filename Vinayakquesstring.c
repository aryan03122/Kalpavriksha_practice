#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} stack;

void initStack(stack *s) {
    s->top = NULL;
}

void push(stack *s, char ch) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(stack *s) {
    if (s->top == NULL)
        return '\0';

    Node *temp = s->top;
    char val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

void freeStack(stack *s) {
    while (s->top != NULL)
        pop(s);
}

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    stack s;
    initStack(&s);

    char str[200];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            push(&s, str[i]);
        } else {
            if (i > 0 && str[i - 1] != ' ')
                push(&s, ' ');
        }
    }

    int index = 0;
    int newWord = 1;

    while (s.top != NULL) {
        char ch = pop(&s);

        if (ch == ' ') {
            str[index] = '\n';
            index++;
            newWord = 1;
        } else {
            if (isVowel(ch))
                ch = toupper(ch);
            else if (newWord) {
                ch = toupper(ch);
                newWord = 0;
            } else
                ch = tolower(ch);

            str[index] = ch;
            index++;
        }
    }

    str[index] = '\0';

    printf("%s", str);

    freeStack(&s);
    return 0;
}