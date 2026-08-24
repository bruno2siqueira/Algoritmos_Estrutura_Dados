#include <stdio.h>
int main()
{
    struct Ponto
    {
        int x;
        int y;
    };

    struct Retangulo
    {
        struct Ponto p1;
        struct Ponto p2;
    };

    // Pontos dos 4 pontos que forma o triangulo no plano carteziano
    struct Retangulo r1;
    r1.p1.x = 10; // p1(x, y) = (10, 20)
    r1.p1.y = 20;
    r1.p2.x = 30; // p2(x, y) = (30, 40)
    r1.p2.y = 40;

    printf("Retangulo 1: Ponto 1: (%d, %d)\n", r1.p1.x, r1.p1.y);
    printf("Retangulo 1: Ponto 2: (%d, %d)\n", r1.p2.x, r1.p2.y);
    printf("Retangulo 1: %d bytes", sizeof(r1.p1.x) + sizeof(r1.p1.y) + sizeof(r1.p2.x) + sizeof(r1.p2.y));

    struct Retangulo r2 = {{10, 20}, {30, 40}}; // Inicialização direta
    printf("\nRetangulo 2: Ponto 1: (%d, %d)\n", r2.p1.x, r2.p1.y);
    printf("Retangulo 2: Ponto 2: (%d, %d)\n", r2.p2.x, r2.p2.y);
    printf("Retangulo 2: %d bytes", sizeof(r2.p1.x) + sizeof(r2.p1.y) + sizeof(r2.p2.x) + sizeof(r2.p2.y));

    return 0;
}
