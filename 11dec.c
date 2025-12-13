// <!-- Music Playlist Manager Using Singly Linked List
// You must implement a music playlist manager using a singly linked list.
// Each song in the playlist contains:
// •	Title (string without spaces)
// •	Artist (string without spaces)
// •	Duration (integer, seconds)
// ________________________________________
// 📦 Data Structure
// struct Song {
//     char *title;
//     char *artist;
//     int duration;
//     struct Song *next;
// };
// You must dynamically allocate all strings and nodes using malloc.
// ________________________________________
// 📥 Input Format
// The input consists of multiple commands, each on a new line.
// The supported commands are:
// ________________________________________
// 1️⃣ ADD <Title> <Artist> <Duration>
// Adds a new song at the end of the playlist.
// Example:
// ADD Shallow LadyGaga 215
// ________________________________________
// 2️⃣ DELETE <Title>
// Deletes all songs with the given title.
// Example:
// DELETE ShapeOfYou
// If no matching song exists:
// Song not found
// ________________________________________
// 3️⃣ SEARCH <Title>
// Print all songs with this title in format:
// Title -> Artist (Duration)
// If not found:
// Not found
// ________________________________________
// 4️⃣ PLAYNEXT
// Plays (prints) the first song in the playlist and removes it.
// Format:
// Playing: <Title> by <Artist> (<Duration>s)
// If playlist empty:
// No songs
// ________________________________________
// 5️⃣ PLAYLAST ⭐ NEW FEATURE INCLUDED
// Plays (prints) the last song in the playlist and removes it.
// Format:
// Playing: <Title> by <Artist> (<Duration>s)
// If playlist empty:
// No songs
// ________________________________________
// 6️⃣ PRINT
// Prints the entire playlist from head to tail.
// Format:
// Title -> Artist (Duration)
// Title -> Artist (Duration)
// ...
// If playlist is empty:
// Playlist empty
// ________________________________________
// 7️⃣ EXIT
// Stop processing input and free all dynamically allocated memory.
// ________________________________________
// 🎯 Output Format Summary
// Use the exact print formats below:
// Operation	Output
// PLAYNEXT	Playing: <Title> by <Artist> (<Duration>s)
// PLAYLAST	Playing: <Title> by <Artist> (<Duration>s)
// SEARCH found	Title -> Artist (Duration)
// SEARCH not found	Not found
// DELETE none found	Song not found
// PRINT empty	Playlist empty
// ________________________________________
// 🧪 Sample Input
// ADD Shallow LadyGaga 215
// ADD BlindingLights Weeknd 199
// ADD ShapeOfYou EdSheeran 233
// SEARCH Shallow
// PLAYLAST
// DELETE Shallow
// PRINT
// EXIT
// 🧪 Sample Output
// Shallow -> LadyGaga (215)
// Playing: ShapeOfYou by EdSheeran (233s)
// Shallow -> LadyGaga (215)
// ________________________________________
// 📌 Constraints (HackerRank-style)
// •	1 ≤ number of commands ≤ 10⁵
// •	1 ≤ length of Title, Artist ≤ 50
// •	1 ≤ Duration ≤ 10000
// •	Use only singly linked list
// •	Must use dynamic memory allocation for every string and node
// •	Must free all memory before EXIT -->
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song {
	char *title;
    char *artist;
    int duration;
	struct Song *next;
};

void parseCommand(char *line, char *cmd, char *title, char *artist, int *duration) {

    char *token;
    char *save;

    token = strtok_r(line, " \n", &save);
    strcpy(cmd, token);

    if (strcmp(cmd, "ADD") == 0) {

        token = strtok_r(NULL, " \n", &save);
        strcpy(title, token);

        token = strtok_r(NULL, " \n", &save);
        strcpy(artist, token);

        token = strtok_r(NULL, " \n", &save);
        *duration = atoi(token);
    }

    else if (strcmp(cmd, "DELETE") == 0 || strcmp(cmd, "SEARCH") == 0) {

        token = strtok_r(NULL, " \n", &save);
        strcpy(title, token);
    }

    else {
        title[0] = '\0';
        artist[0] = '\0';
        *duration = -1;
    }
}

void addSong(struct Song **head, char *title, char *artist, int duration) {

    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));

    newSong->title = (char *)malloc(strlen(title) + 1);
    strcpy(newSong->title, title);

    newSong->artist = (char *)malloc(strlen(artist) + 1);
    strcpy(newSong->artist, artist);

    newSong->duration = duration;
    newSong->next = NULL;

    if (*head == NULL) {
        *head = newSong;
        return;
    }

    struct Song *mover = *head;
    while (mover->next != NULL) {
        mover = mover->next;
    }

    mover->next = newSong;
}

void deleteSong(struct Song **head, char *title) {

    if (*head == NULL) {
        printf("Song not found\n");
        return;
    }

    int deleted = 0;

    while (*head != NULL && strcmp((*head)->title, title) == 0) {

        struct Song *del = *head;
        *head = (*head)->next;

        free(del->title);
        free(del->artist);
        free(del);

        deleted = 1;
    }

    if (*head == NULL) {
        if (!deleted) printf("Song not found\n");
        return;
    }

    struct Song *temp = *head;

    while (temp->next != NULL) {

        if (strcmp(temp->next->title, title) == 0) {
            struct Song *del = temp->next;

            temp->next = del->next;

            free(del->title);
            free(del->artist);
            free(del);

            deleted = 1;
        }
        else {
            temp = temp->next;
        }
    }

    if (!deleted) printf("Song not found\n");
}

void searchSong(struct Song *head, char *title) {
    int found = 0;
    struct Song *mover = head;

    while (mover != NULL) {
        if (strcmp(mover->title, title) == 0) {
            printf("%s -> %s (%d)\n",
                  mover->title,
                  mover->artist,
                  mover->duration);
            found = 1;
        }

        mover = mover->next;
    }
    if (!found) {
        printf("Not found\n");
    }
}

void playNext(struct Song **head) {

    if (*head == NULL) {
        printf("No songs\n");
        return;
    }

    struct Song *temp = *head;

    printf("Playing: %s by %s (%ds)\n",
           temp->title,
           temp->artist,
           temp->duration);

    *head = (*head)->next;

    free(temp->title);
    free(temp->artist);
    free(temp);
}

void playLast(struct Song **head) {

    if (*head == NULL) {
        printf("No songs\n");
        return;
    }

    if ((*head)->next == NULL) {

        struct Song *temp = *head;

        printf("Playing: %s by %s (%ds)\n",
               temp->title, temp->artist, temp->duration);

        *head = NULL;

        free(temp->title);
        free(temp->artist);
        free(temp);

        return;
    }

    struct Song *curr = *head;

    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    struct Song *temp = curr->next;

    printf("Playing: %s by %s (%ds)\n",
           temp->title, temp->artist, temp->duration);

    curr->next = NULL;

    free(temp->title);
    free(temp->artist);
    free(temp);
}

void printPlaylist(struct Song *head) {

    if (head == NULL) {
        printf("Playlist empty\n");
        return;
    }

    while (head != NULL) {
        printf("%s -> %s (%d)\n",
               head->title, head->artist, head->duration);
        head = head->next;
    }
}

void freeAll(struct Song **head) {

    struct Song *curr = *head;

    while (curr != NULL) {
        struct Song *next = curr->next;
        free(curr->title);
        free(curr->artist);
        free(curr);
        curr = next;
    }

    *head = NULL;
}

int main() {

    struct Song *head = NULL;

    char line[200];
    char cmd[20];
    char title[100];
    char artist[100];
    int duration;

    while (1) {

        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        parseCommand(line, cmd, title, artist, &duration);

        if (strcmp(cmd, "ADD") == 0) {
            addSong(&head, title, artist, duration);
        }
        else if (strcmp(cmd, "DELETE") == 0) {
            deleteSong(&head, title);
        }
        else if (strcmp(cmd, "SEARCH") == 0) {
            searchSong(head, title);
        }
        else if (strcmp(cmd, "PLAYNEXT") == 0) {
            playNext(&head);
        }
        else if (strcmp(cmd, "PLAYLAST") == 0) {
            playLast(&head);
        }
        else if (strcmp(cmd, "PRINT") == 0) {
            printPlaylist(head);
        }
        else if (strcmp(cmd, "EXIT") == 0) {
            freeAll(&head);
            break;
        }
    }

    return 0;
}

