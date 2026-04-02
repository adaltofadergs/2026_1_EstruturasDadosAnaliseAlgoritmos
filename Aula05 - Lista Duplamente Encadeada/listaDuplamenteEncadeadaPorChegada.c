/*
Lista Duplamente Encadeada por ordem de chegada

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
	struct No* anterior;
    char dado[20];
    struct No* proximo;
}No;

No* gerarEnd( char _dado[20] ){
    No* novoNo = (No*) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
   
    strcpy( novoNo->dado, _dado );
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}


int main()
{
    No *inicio = NULL;
    No *fim = NULL;
    char nome[20];
    int op;
    
    do{
      printf( "\n -----------------------  \n");
        printf( "| 1) Adicionar          | \n");
        printf( "| 2) Remover            | \n");
        printf( "| 3) Imprimir           | \n");
        printf( "| 4) Imprimir Reverso   | \n");
        printf( "| 0) Sair               | \n");
        printf( " -----------------------  \n");
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
                    fim->proximo = nodo;
                    nodo->anterior = fim; 
                }
                fim = nodo;
                break;
            case 2:
            	if( inicio == NULL ){
            		printf("Lista Vazia!");
				}else{
					int removeu = 0;
					printf("Digite o nome: ");
                	scanf(" %[^\n]" , &nome );
                	if( strcmp( nome , inicio->dado) == 0 ){
                		No* aux = inicio;
                		inicio = inicio->proximo;
                		if( inicio != NULL )
                			inicio->anterior = NULL;
                		free( aux );
                		removeu = 1;
					}else{
						No* ant = inicio;
						No* aux = inicio->proximo;
						while( aux != NULL){
							if( strcmp( nome , aux->dado) == 0 ){
								ant->proximo = aux->proximo;
								if (aux->proximo != NULL){
									aux->proximo->anterior = ant;
								}
								free( aux );
								removeu = 1;
								break;
							}else{
								ant = aux;
								aux = aux->proximo;
							}
						}
					}
					removeu == 1 ? printf("%s encontrado e removido!", nome) : printf("%s não encontrado!", nome);
				}
                
                break;
            case 3:
                if( inicio == NULL )
                    printf( "\nLista Vazia! " );
                else{
                    No* aux = inicio;
                    while( aux != NULL){
                       printf("\n%s" , aux->dado);
                       aux = aux->proximo;
                    }
                }
                break;
            case 4:
                if( inicio == NULL )
                    printf( "\nLista Vazia! " );
                else{
                    No* aux = fim;
                    while( aux != NULL){
                       printf("\n%s" , aux->dado);
                       aux = aux->anterior;
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