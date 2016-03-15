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

//CallBack function pointer here!
typedef int (*compare_cb)(int a, int b);

//a bubble sort thing, that uses CB function.
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));
    if(!target) die("Memory error."); //check if target == NULL
    memcpy(target, numbers, count * sizeof(int));
    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

//Thing to display what CB function the program invokes.
char cbFuncName[200];

// Some functions for COMPARE_CB callback function pointer.
int sorted_order(int a, int b)
{
    strcpy(cbFuncName, "Sorted order.");
    return (a-b);
}
int reverse_order(int a, int b)
{
    strcpy(cbFuncName, "Reverse order.");
    return (b-a);
}
int kek_order(int a, int b)
{
    strcpy(cbFuncName, "Kek order.");
    return (a%(b+1));
}

//main testing function here:
void test_sorting(int *src_a, int size, compare_cb cmp)
{
    int *sorted = bubble_sort(src_a, size, cmp);
    if(!sorted) die("Failed to sort as requested."); //anotha amazing error stuff
    printf("%s\n", cbFuncName);
    for(int i = 0; i < size; i++) {
        printf("%d ", sorted[i]);
    }
    puts("");
    //Free allocated memory.
    free(sorted);
}

int main()
{
    int testArr[] = {2,6,2,7,2,96,3,123,642,23,64,21,86};
    int arrItemsCount = sizeof(testArr)/sizeof(int);
    test_sorting(testArr, arrItemsCount, sorted_order);
    test_sorting(testArr, arrItemsCount, reverse_order);
    test_sorting(testArr, arrItemsCount, kek_order);
    return 0;
}
