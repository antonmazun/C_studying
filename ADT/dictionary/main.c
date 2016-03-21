#include <stdio.h> //printf
#include "dict.h"

//example how to use a simple dictionary!
//from: Ben Klemens - "C programming language in 21th century"
int main()
{
    int zeroI = 0;
    float oneF = 1.0;
    char twoStr[] = "two";

    dictionary *d = dictionary_new();

    //add some items
    dictionary_add(d, "an int", &zeroI);
    dictionary_add(d, "a float", &oneF);
    dictionary_add(d, "a string", &twoStr);
    //print what`s inside
    printf("I saved an integer: %i\n", *(int*)dictionary_find(d, "an int"));
    printf("I saved a float: %.3f\n", *(float*)dictionary_find(d, "a float"));
    printf("I saved a string: %s\n", (char*)dictionary_find(d, "a string"));
    //free allocated memory
    dictionary_free(d);
    return 0;
}
