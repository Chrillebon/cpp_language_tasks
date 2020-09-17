#include <stdio.h>

// Udregner gennemsnittet af vores liste "arr"

/*
int main(void) {
    int arr[10] = {19,74,13,67,44,80,7,36,9,77},
    *p = arr;
    int i = -1;
    double val = 0.0;

    while(++i < 10)
        val += *(p++);

    val /= 10;

    printf("Value: %.2f\n",val);
    return 0;
}
*/

int main(void) {
    int arr[10] = {19,74,13,67,44,80,7,36,9,77},
    double val = 0.0;

    for(int i=0;i<10;i++)
    {
      val += arr[i];
    }
    val /= 10;

    printf("Value: %.2f\n",val);
    return 0;
}
