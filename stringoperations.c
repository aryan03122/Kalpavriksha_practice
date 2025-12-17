#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    /* Manual checks */
    if (ch >= 'A' && ch <= 'Z')
        printf("Manual: Uppercase letter\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Manual: Lowercase letter\n");
    else if (ch >= '0' && ch <= '9')
        printf("Manual: Digit\n");
    else
        printf("Manual: Special character\n");

    /* Inbuilt checks */
    if (isupper(ch))
        printf("Inbuilt: Uppercase letter\n");
    if (islower(ch))
        printf("Inbuilt: Lowercase letter\n");
    if (isdigit(ch))
        printf("Inbuilt: Digit\n");
    if (!isalnum(ch))
        printf("Inbuilt: Special character\n");

    /* Case conversion */
    printf("Manual to upper: %c\n",
           (ch >= 'a' && ch <= 'z') ? ch - 32 : ch);
    printf("Inbuilt to upper: %c\n", toupper(ch));

    /* ---------------- STRING FUNCTIONS ---------------- */

    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    printf("\n--- String Functions Demo ---\n");

    /* strlen() */
    printf("Length of str1: %lu\n", strlen(str1));

    /* strcpy() */
    strcpy(str3, str1);
    printf("strcpy result: %s\n", str3);

    /* strcat() */
    strcat(str1, str2);
    printf("strcat result: %s\n", str1);

    /* strcmp() */
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));

    /* strchr() */
    printf("First occurrence of 'o' in str1: %s\n", strchr(str1, 'o'));

    /* strstr() */
    printf("Substring \"World\" in str1: %s\n", strstr(str1, "World"));

    /* strncpy() */
    strncpy(str3, str2, 3);
    str3[3] = '\0';
    printf("strncpy result: %s\n", str3);

    /* strncat() */
    strncat(str3, str1, 3);
    printf("strncat result: %s\n", str3);

    /* strncmp() */
    printf("strncmp(str1, str2, 3): %d\n", strncmp(str1, str2, 3));

    return 0;
}
