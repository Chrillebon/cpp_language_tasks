#include <stdio.h>

int main(void) {
    int a=1, b=2;
    int *p1, *p2;

    p1 = &a;
    p2 = &b;

    printf("a=%i ", *p1);
    printf("b=%i", *p2);

    return 0;
}
