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

int mostrarMenu(){
	int opcao;
	printf( "\n ----------------  \n");
      printf( "| 1) Adicionar   | \n");
      printf( "| 2) Remover     | \n");
      printf( "| 3) Imprimir    | \n");
      printf( "| 0) Sair        | \n");
      printf( " ----------------  \n");
    printf( "Digite sua opção:  \n");
    scanf("%d" , &opcao);
    return opcao;
}


int main()
{
    No *inicio = NULL;
    No *fim = NULL;
    char nome[20];
    int op;
    
    do{
      	op = mostrarMenu();
        switch( op ){
            case 1:
            	printf("Digite o nome: ");
                scanf(" %[^\n]" , &nome );
                No *nodo = gerarEnd( nome );
                if( inicio == NULL ){
                	inicio = nodo;
                	fim = nodo;
				}else{
					fim->prox = nodo;
					fim = nodo;
				}
				break;
			case 2:
				if( inicio == NULL ){
					printf("A fila esta vazia!");
				}else{
					No *aux = inicio;
					inicio = inicio->prox;
					free( aux );
				}
				break;
			case 3:
				if( inicio == NULL )
                    printf( "\nFila Vazia! " );
                else{
                    No* aux = inicio;
                    while( aux != NULL){
                       printf("%s - " , aux->dado);
                       aux = aux->prox;
                    }
                }
                break;
			case 0:
				printf( "\nBye-bye" );
				break;
			default:
				printf( "\nOpcao nao permitida" );        
        }
    }while( op != 0);
    
    return 0;
}

// FUAQ implementa uma fila de carros em um lava-jato
// cada carro terá o modelo, a placa e o ano
// implemente um método para adicionar carros na fila 
// e um método para lavar carro.
// Implemente também um método para mostrar a fila de carros
// e um método que ao informar a placa, é retornada qual posição ,
// da fila está o carro












