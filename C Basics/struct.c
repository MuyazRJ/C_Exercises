#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
} timestamp;

timestamp add_timestamps(timestamp t1, timestamp t2) {
    timestamp t3 = { t1.hour + t2.hour, t1.minute + t2.minute, t1.second + t2.second };
    return t3;
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Expected two timestamps.\n");
        return 1;
    }

    timestamp t1 = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) };
    timestamp t2 = { atoi(argv[4]), atoi(argv[5]), atoi(argv[6]) };
    timestamp t3 = add_timestamps(t1, t2);

    printf("%u %u %u\n", t3.hour, t3.minute, t3.second);

    return 0;
}