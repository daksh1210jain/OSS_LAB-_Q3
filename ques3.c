#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int count[MAX_WORDS] = {0};
    int num_words = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \t\n\r");
    while (token != NULL) {
        strcpy(words[num_words], token);
        num_words++;
        token = strtok(NULL, " \t\n\r");
    }

    // Count the frequency of each word
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            count[i]++;
        }
    }

    // Print the word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                break;
            }
        }
        if (j == i) {
            printf("%s: %d\n", words[i], count[i]);
        }
    }

    return 0;
}
