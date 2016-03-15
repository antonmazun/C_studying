#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//Really nice method to get your own error messages!!!
//Really should keep this stuff in mind.
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

int add_items(int a, int b)
{
    return (a+b);
}

int main()
{
    int (*tester_fp)(int a, int b);
    tester_fp = add_items;
    printf("TEST: %d is same as %d\n\n", tester_fp(5,5), add_items(5,5));


    return 0;
}
