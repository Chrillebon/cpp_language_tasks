#include <stdio.h>

int main(void) {

    double arr[5] = {1.0, 0.1, -2.0, 3.0, -0.1};

    double cumulative = 0;

    int arrlength = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<arrlength;i++)
    {
      cumulative += arr[i];
      arr[i] = cumulative;
    }

    /* Test: print out values */
    for (int i=0; i < sizeof(arr)/sizeof(*arr); i++)
        printf("%.2f ", arr[i]);

    return 0;
}
