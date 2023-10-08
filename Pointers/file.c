#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_word(FILE *input_file, FILE *output_file, const char *word) {
    char line[1000];  // Assuming a maximum line length of 1000 characters

    while (fgets(line, sizeof(line), input_file) != NULL) {
        char *pos = line;
        int word_len = strlen(word);

        while ((pos = strstr(pos, word)) != NULL) {
            // Shift characters to remove the word
            memmove(pos, pos + word_len, strlen(pos + word_len) + 1);
        }

        fprintf(output_file, "%s", line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_name> <word>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_name = argv[1];
    char *word = argv[2];

    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    char output_file_name[1000];
    snprintf(output_file_name, sizeof(output_file_name), "%s-processed.txt", file_name);

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    remove_word(input_file, output_file, word);

    printf("Processing complete. Output written to %s.\n", output_file_name);

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}
