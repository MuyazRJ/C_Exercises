#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

void convert_and_print(const char *str) {
    char *endptr;
    errno = 0;  // Initialize errno to 0 before the call to strtol

    long number = strtol(str, &endptr, 10);

    // Check for conversion errors
    if ((errno == ERANGE && (number == LONG_MAX || number == LONG_MIN)) ||
        (errno != 0 && number == 0)) {
        printf("under/overflow\n");
        return;
    }

    // Check for invalid input (no characters consumed)
    if (endptr == str) {
        printf("invalid string\n");
        return;
    }

    // Only valid input left; print the number
    printf("you have entered: %ld\n", number);
}

int main() {
    char str[100];

    printf("please enter an integer number (base 10): ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove the newline character, if present
        char *newline = strchr(str, '\n');
        if (newline != NULL)
            *newline = '\0';

        convert_and_print(str);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
