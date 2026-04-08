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
    printf( "Digite sua opcao:  ");
    scanf("%d" , &opcao);
    return opcao;
}


int main()
{
    No *topo = NULL;
    char nome[20];
    int op;
    
    do{
      	op = mostrarMenu();
        switch( op ){
            case 1:
            	printf("Digite o nome: ");
                scanf(" %[^\n]" , &nome );
                No *nodo = gerarEnd( nome );
            
                nodo->prox = topo;
                topo = nodo;                
                
				break;
			case 2:
				if( topo == NULL ){
					printf("A Pilha esta vazia!");
				}else{
					No *aux = topo;
					topo = topo->prox;
					free( aux );
				}
				break;
			case 3:
				if( topo == NULL )
                    printf( "\nPilha Vazia! " );
                else{
                    No* aux = topo;
                    while( aux != NULL){
                       printf("\n%s" , aux->dado);
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

//## FUAQ implementa uma pilha de livro.
//# Cada livro deverá conter o título, a quantidade de página e 
//# o autor, sendo que o autor deverá conter nome, 
//# e ano de nascimento.
//# Implemente um método para adicionar livros na pilha,
//# um método para imprimir a pilha de livros,
//# um método para remover um livro da pilha 
//# e um método que o usuário informa o nome do autor e 
//# lhe é informado quantos livros tem na pilha com este autor












