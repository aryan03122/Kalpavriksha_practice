// 🧾 Problem: Student Record Analyzer

// You are given student records where each line contains:

// <Roll_Number> <Name> <M1> <M2> <M3>


// Roll_Number → integer

// Name → string without spaces

// M1, M2, M3 → three subject marks (integers)

// You must:

// Store all student data using dynamic memory (malloc + realloc).
// Use a 1D dynamic array of struct Student.

// Create a 2D dynamic array (int**) to store only the marks of all students.

// Compute for each student:

// Average Marks = (M1 + M2 + M3) / 3.0


// Print the data in the format:

// Roll | Name | Avg | Highest Subject


// Where:

// Highest Subject = index of subject with max mark (0,1,2)

// 📥 Input Format
// N
// 101 Aryan 90 80 95
// 102 Sneha 78 88 92
// 103 Rahul 85 85 85


// Where:

// N is the number of students.

// 📤 Output Format
// 101 Aryan 88.33 2
// 102 Sneha 86.00 2
// 103 Rahul 85.00 0

// 🧩 Requirements Checklist
// Concept Required	Must Use
// Strings	Yes (name)
// 1D Array	Array of structures
// 2D Dynamic Array	int **marks
// Single Pointer	accessing fields/pointer arithmetic
// Double Pointer	marks[i][j] allocation
// Dynamic Memory	malloc, realloc, free
// 🧱 Code Templates (You Fill Step-by-Step)
// 📌 Step 1: Define Structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char *name;  
};

struct Student* allocateStudents(int n) {
    struct Student *arr = malloc(n * sizeof(struct Student));
    if (!arr) {
        printf("Memory Allocation failed\n");
        exit(1);
    }
    return arr;
}

int** allocateMarks(int n) {

    int **marks = malloc(n * sizeof(int*));
    if (!marks) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        marks[i] = malloc(3 * sizeof(int));
        if (!marks[i]) {
            printf("Row Allocation Failed\n");
            exit(1);
        }
    }

    return marks;
}

void fillData(struct Student *arr, int **marks, int index, char *line) {
    char *save;
    char *token;

    token = strtok_r(line, " \n", &save);
    arr[index].roll = atoi(token);

    token = strtok_r(NULL, " \n", &save);
    arr[index].name = malloc(strlen(token) + 1);
    strcpy(arr[index].name, token);

    for (int j = 0; j < 3; j++) {
        token = strtok_r(NULL, " \n", &save);
        marks[index][j] = atoi(token);
    }
}

float computeAvg(int *row) {

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += row[i];
    }

    return sum / 3.0;
}

int findHighest(int *row) {
  
    int high = -1;
    int index = -1;

    for (int i = 0; i < 3; i++) {
        if (row[i] > high) {
            high = row[i];
            index = i;
        }
    }
    return index;
}

void printRecords(struct Student *arr, int **marks, int n) {
    for (int i = 0; i < n; i++) {

        float avg = computeAvg(marks[i]);
        int highIndex = findHighest(marks[i]);

        printf("%d %s %.2f %d\n", 
               arr[i].roll, 
               arr[i].name, 
               avg, 
               highIndex);
    }
}

void freeAll(struct Student *arr, int **marks, int n) {

    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }

    for (int i = 0; i < n; i++) {
        free(marks[i]);
    }

    free(marks);
    free(arr);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    struct Student *students = allocateStudents(n);
    int **marks = allocateMarks(n);
    char buffer[100];
    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        fillData(students, marks, i, buffer);
    }
    printRecords(students, marks, n);
    freeAll(students, marks, n);
    return 0;
}
