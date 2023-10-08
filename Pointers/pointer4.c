#include <stdio.h>

int main(int argc, char **argv) {
    char *string = "hello, world!\n";
    int offset = 0;

    while(*(string + offset) != '\0') {
        printf("%c", *(string + offset));
        offset++;
    }
    
    return 0;
}