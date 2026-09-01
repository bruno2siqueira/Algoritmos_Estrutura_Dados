#include <stdio.h>
#include <string.h>

typedef struct Carro
{
    char modelo[50];
    float potencia;
    int anoFabricacao;
    int numPortas;
} Carro;
// Função para imprimir os dados do carro
void imprimeCarro(struct Carro c)
{
    printf("Modelo: %s \n", c.modelo); // string
    printf("Potência: %.2f \n", c.potencia);
    printf("Ano de Fabricação: %d \n", c.anoFabricacao);
    printf("Número de Portas: %d \n", c.numPortas);
}
// Funcao cadastrar/inserir dos dados carro
void preencherCarro(struct Carro *c)
{
    printf("Informe o Modelo do Carro: ");
    scanf("%s", c->modelo);
    fflush(stdin); // Limpar o buffer do teclado
    printf("Informe o Potencia do Carro: ");
    scanf("%f", &c->potencia);
    printf("Informe o Fabricacao do Carro: ");
    scanf("%d", &c->anoFabricacao);
    printf("Informe o Numero de portas do Carro: ");
    scanf("%d", &c->numPortas);
    printf("Carro cadastrado com sucesso!\n");
}

int main()
{
    Carro car;
    preencherCarro(&car);
    imprimeCarro(car);
    return 0;
}