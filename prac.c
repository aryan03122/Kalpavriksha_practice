#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char name[50];
    int roll_no;
    int score;
    struct Node *next;
}Node;

void insert(struct Node **head , char *name , int roll , int score){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> roll_no = roll;
    newNode -> score = score;
    strcpy(newNode -> name , name);
    newNode -> next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *mover = *head;
    while(mover -> next != NULL){
        mover = mover -> next;
    }
    mover -> next = newNode;
}

void encode(char *s){
    for(int i = 0 ; i != '\0' ; i++){
        if(isalpha(s[i])){
            s[i]++;
        }
    }
}

void printList(struct Node *head){
    if(head == NULL){
        print("Empty LL");
        return;
    }

    struct Node *mover = head;
    while(mover != NULL){
        printf("\n%d      %s      %d\n" , mover -> roll_no , mover -> name , mover -> score);
        mover = mover -> next;
    }
}

void freeList(struct Node *head){
    while(head != NULL){
        struct Node *temp = head;
        head = head -> next;
        free(temp);
    }
}

float computeAvg(struct Node *head){

    int sum = 0;
    int count = 1;
    struct Node *mover = head;
    while(mover -> next != NULL){
        sum = mover -> score + sum;
        count++;
        mover = mover -> next;
    }
    float avg;
    avg = (float)sum/count;
    return avg;
}

void reverseNames(char *ch){
    int length = strlen(ch);
    int start = 0;
    int end = length - 1;
    while(start < end){
        char temp;
        temp = ch[start];
        ch[start] = ch[end];
        ch[end] = temp;
        start++;
        end--;
    }
}

void findDuplicateNames(struct Node *head) {
    struct Node *i, *j;
    printf("Duplicate Encoded Names:\n");
    int found = 0;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) == 0) {
                printf("%s\n", i->name);
                found = 1;
            }
        }
    }

    if (!found) printf("None\n");
}

void encryptScores(struct Node *head) {
    while (head) {
        head->score = (head->score * 135) % 100;  
        head = head->next;
    }
}

int main(){
    char line[200];
    struct Node* ll = (struct Node *)malloc(sizeof(Node));
    while(fgets(line , sizeof(line) , stdin)!= NULL){
        char name[100];
        int roll;
        int score;

        char *remaining = line;
        char *token;

        token = strtok_r(remaining , ": " , &remaining);
        token = strtok_r(NULL , ":," , &remaining);
        while(*token == ' '){
            token++;
        }
        strcpy(name , token);

        
        token = strtok_r(NULL , ":," , &remaining);
        token = strtok_r(NULL , ":," , "&remaining");
        roll = atoi(token);

        token = strtok_r(NULL, ":,", &remaining);
        token = strtok_r(NULL, ":,", &remaining);
        score = atoi(token);

        encode(name);
        insert(&ll, name, age, score);
    }
    printList(ll);
    printf("\nAverage Score: %.2f\n", computeAverage(ll));

    freeList(ll);
    return 0;
}