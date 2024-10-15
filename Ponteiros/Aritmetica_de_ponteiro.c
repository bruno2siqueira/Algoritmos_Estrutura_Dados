#include <stdio.h>
#include <stdlib.h>
int main()
{
    float m[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 15.0};
    float *p1;
    float *p2;
    p1 = &m[7];
    p2 = m;
    printf("Diferenca de posicoes %d", p1 - p2);

    return 0;
}