#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[20];
    int idade;
}Pessoa;

int main()
{
    printf("Lista de Nomes: \n\n");
    Pessoa pessoas[3];
    
    for( int i = 0; i<3 ; i++){
        printf("\nDigite o nome da %dª pessoa: ", (i+1) );
        scanf(" %[^\n]", &pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
    }
    
    for( int i = 0; i<3 ; i++){
        printf("\n%dª pessoa: %s", (i+1), pessoas[i].nome);
        printf(" - Idade: %d", pessoas[i].idade);
    }
    return 0;
}
