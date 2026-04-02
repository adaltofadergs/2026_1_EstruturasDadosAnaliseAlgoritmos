/******************************************************************************
ALOCAÇÃO DINÂMICA DE MEMÓRIA  - 04/03/2026

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[10];
    struct Fruta *prox;
}Fruta;

Fruta* gerarEnd( char _nome[20] ){
    Fruta *novaFruta = (Fruta*) malloc( sizeof(Fruta));
    if( novaFruta == NULL ){
        printf("Erro ao tentar alocar memória");
        exit(1);
    }
    strcpy( novaFruta->nome , _nome);
    return novaFruta;
}


int main()
{
    int op = 0;
    char nomeDigitado[10];
    Fruta *inicio = NULL;
    do{
        printf("\nDigite o nome da fruta: ");
        scanf(" %[^\n]", &nomeDigitado );
        Fruta *novaFruta2 = gerarEnd( nomeDigitado );
        
        if( inicio != NULL) {
            novaFruta2->prox = (struct Fruta*) inicio;
        }
        inicio = novaFruta2;
        printf("\n-----------------------");
        printf("\nLista de Frutas:");
        Fruta *aux = inicio;
        while( aux != NULL ){
            printf("\n%s", aux->nome );
            aux = (Fruta*) aux->prox;
        }
        
        
        printf("\n\nDeseja continuar? 1-Sim  0-Não : ");
        scanf("%d", &op);
    }while( op != 0 );
    
    printf("Bye-bye!!!");

    return 0;
}

