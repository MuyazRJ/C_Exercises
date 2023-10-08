#include <stdio.h>

enum day {
    MONDAY = 0,
    TUESDAY = 1,
    WEDNESDAY = 2,
    THURSDAY = 3,
    FRIDAY = 4,
    SATURDAY = 5,
    SUNDAY  = 6
};

int main(int argc, char **argv) {
    int d = 2;

    switch (d) {
        case MONDAY:
            printf("Today is Monday\n");
            break;
        case TUESDAY:
            printf("Today is Tuesday\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday\n");
            break;
        case THURSDAY:
            printf("Today is Thursday\n");
            break;
        case FRIDAY:
            printf("Today is Friday\n");
            break;
        case SATURDAY:
            printf("Today is Saturday\n");
            break;
        case SUNDAY:
            printf("Today is Sunday\n");
            break;
        default:
            printf("Invalid day\n");
            break;
    }

    return 0;
}
