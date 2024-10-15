#include <stdio.h>
#include <stdlib.h>
int main()
{
    float m[] = {1.0, 3.0, 5.75, 2.345};
    float *p;
    p = &m[1];
    printf("p[-1] = %f\n", p[-1]);
    printf("p[0] = %f\n", p[0]);
    printf("p[1] = %f\n", p[1]);
    printf("p[2] = %f\n", p[2]);
    printf("p[3] = %f\n", p[3]);

    return 0;
}