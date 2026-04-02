/******************************************************************************
Lista Encadeada por ordem de chegada

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char dado[20];
    struct No* prox ;
}No;

No* gerarEnd( char _dado[20] ){
    No* novoNo = (No*) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
   
    strcpy( novoNo->dado, _dado );
    novoNo->prox = NULL;
    return novoNo;
}


int main()
{
    No *inicio = NULL;
    char nome[20];
    int op;
    
    do{
      printf( "\n ----------------  \n");
        printf( "| 1) Adicionar   | \n");
        printf( "| 2) Remover     | \n");
        printf( "| 3) Imprimir    | \n");
        printf( "| 0) Sair        | \n");
        printf( " ----------------  \n");
        printf( "Digite sua opção:  \n");
        scanf("%d" , &op);
        
        switch( op ){
            case 1:
                printf("Digite o nome: ");
                scanf(" %[^\n]" , &nome );
                No *nodo = gerarEnd( nome );
                if( inicio == NULL )
                    inicio = nodo;
                else{
                    No *aux = inicio;
                    while( aux->prox != NULL ){
                        aux = aux->prox;
                    }
                    aux->prox = nodo;
                }
                break;
            case 2:
            
                // implementar aqui o remover

                break;
            case 3:
                if( inicio == NULL )
                    printf( "\nLista Vazia! " );
                else{
                    No* aux = inicio;
                    while( aux != NULL){
                       printf("\n%s" , aux->dado);
                       aux = aux->prox;
                    }
                }
                break;
            case 0:
                printf("Bye-bye!");
                break;
            default:
                printf("Opção inválida!");
                
        }
        
    }while( op != 0 );
    

    return 0;
}
