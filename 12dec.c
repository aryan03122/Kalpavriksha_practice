// 🎬 Problem Statement: Movie Database Cleaner & Analyzer

// You are given a list of N movies, each with:

// <MovieName> <Year>


// Where:

// MovieName is a string (may contain mixed case)

// Year is an integer

// You must perform encoding + analysis on the movie names using the rules below.

// 🎥 Part A — Encode Movie Names

// For each movie name, apply all three encoding rules:

// Rule 1 — Remove consecutive duplicate characters
// "Avataaar" → "Avatar"
// "Jummmmanji" → "Jumanji"
// "MaTRIXXX" → "MaTRIX"

// Rule 2 — No two consonants can appear consecutively

// If they do, remove the second consonant.

// Consonants = all alphabets except AEIOU (case-insensitive)

// Examples:

// "Batman" → "Batan"
// "Doctor" → "Dotor"
// "Flash" → "Flas"
// "Brave" → "Brave" (no change: vowels between consonants)

// Rule 3 — Convert final movie name to lowercase
// "AvAtAr" → "avatar"
// "Matrix" → "matrix"

// Example Encoding

// Input movie name:

// "JUMMMMANJIII"


// Steps:

// Remove duplicates → "JUMANJI"

// Remove consecutive consonants → "JUMANI"

// Lowercase → "jumani"

// Output:

// jumani

// 🎥 Part B — Year Matrix

// Create a 2D matrix where:

// yearMatrix[i][0] = original release year
// yearMatrix[i][1] = decade (year / 10)


// Example:

// 1999 → decade = 199
// 2002 → decade = 200
// 1984 → decade = 198

// 📤 Final Output Format

// For each movie, print:

// EncodedMovieName  OriginalYear  Decade


// Example output:

// avatar 2009 200
// matrix 1999 199
// titanic 1997 199

// 📥 Sample Input
// 3
// Avataaar 2009
// MaTRIXXX 1999
// TiTaNNNnic 1997

// 📤 Sample Output
// avatar 2009 200
// matrix 1999 199
// titanic 1997 199
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encodeMovieName(char *input) {
    int n = strlen(input);
    char *temp = malloc(n + 1);
    int i = 0;
    int k = 0;

    while (input[i] != '\0') {

        char curr = input[i];

        if (curr >= 'A' && curr <= 'Z') {
            curr = curr + ('a' - 'A');
        }

        char prev;
        if (k == 0) {
            prev = '\0';
        } else {
            prev = temp[k-1];
        }

        if (k > 0 && curr == prev) {
            i++;
            continue;
        }

        int prevVowel = 0;
        if (prev=='a' || prev=='e' || prev=='i' || prev=='o' || prev=='u') {
            prevVowel = 1;
        }

        int currVowel = 0;
        if (curr=='a' || curr=='e' || curr=='i' || curr=='o' || curr=='u') {
            currVowel = 1;
        }

        if (k > 0 && prevVowel==0 && currVowel==0) {
            i++;
            continue;
        }

        temp[k] = curr;
        k++;
        i++;
    }

    temp[k] = '\0';
    return temp;
}

int** allocateYearMatrix(int n) {
    int **years = (int **)malloc(n * sizeof(int *));
    for(int i = 0 ; i < n ; i++){
        years[i] = (int *)malloc(2 * sizeof(int));
    }
    return years;
}

void fillMovieData(char **movies, int **years, int index, char *line) {
    char *token;
    char *save;
    token = strtok_r(line, " \n", &save);
    char *encoded = encodeMovieName(token);
    movies[index] = (char *)malloc(strlen(encoded) + 1);
    strcpy(movies[index], encoded);
    free(encoded);
    token = strtok_r(NULL, " \n", &save);
    int year = atoi(token);
    years[index][0] = year;
    years[index][1] = year / 10;
}

void printMovies(char **movies, int **years, int n) {
    for(int i = 0 ; i < n ; i++){
        printf("%s  %d  %d" , movies[i] , years[i][0] , years[i][1]);
        printf("\n");
    }
}

void freeAll(char **movies, int **years, int n) {
    for(int i = 0 ; i < n ; i++){
        free(years[i]);
        free(movies[i]);
    }
    free(movies);
    free(years);
}

int main() {

    int n;
    scanf("%d", &n);
    getchar();  

    char **movies = (char **)malloc(n * sizeof(char *));
    int **years = allocateYearMatrix(n);

    char buffer[200];

    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        fillMovieData(movies, years, i, buffer);
    }

    printMovies(movies, years, n);

    freeAll(movies, years, n);

    return 0;
}
