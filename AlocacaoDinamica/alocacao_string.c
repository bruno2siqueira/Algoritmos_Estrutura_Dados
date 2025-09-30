/*4. Faça um programa que receba do usuário o tamanho de uma string (variavel tam) e chame uma função para  alocar dinamicamente essa string (malloc para a string).  Em seguida, o usuário deverá informar o conteúdo dessa string.
O programa imprime a string sem suas vogais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string; // ponteiro para string
int tam;      // tamanho da string

// funcão para alocar dinamicamente a string
int aloca_string(int tam)
{
    string = malloc(tam * sizeof(char));
    if (string == NULL)
    {
        printf("Erro ao alocar memória!\n");
        return 0;
    }
    return 1;
}
int main()
{

    printf("Digite o tamanho da String: ");
    scanf("%d", &tam);
    aloca_string(tam); // chama a função para alocar a string
    printf("Digite a String: ");
    scanf("%s", string); // lê a string
    printf("String sem vogais: ");
    for (int i = 0; i < strlen(string); i++)
    { // strlen retorna o tamanho da string
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' &&
            string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U')
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
    free(string); // libera a memória alocada
    return 0;
}