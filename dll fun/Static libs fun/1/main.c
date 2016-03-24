#include <stdio.h>
#include <stdlib.h>

// lib functions!
// Get them from libhfsecurity.a
void encrypt(char *message);
int checksum(char *message);

int main()
{
    char s[] = "Hello my friend!";
    encrypt(s);
    printf("Message encrypted into %s\n", s);
    printf("Checksum: %i\n", checksum(s));
    encrypt(s);
    printf("Encrypted back to %s\n", s);
    printf("Checksum: %i\n", checksum(s));

    return (0);
}
