//## FUAQ implementa uma pilha de livro.
//# Cada livro deverá conter o título, a quantidade de página e 
//# o autor, sendo que o autor deverá conter nome, 
//# e ano de nascimento.
//# Implemente um método para adicionar livros na pilha,
//# um método para imprimir a pilha de livros,
//# um método para remover um livro da pilha 
//# e um método que o usuário informa o nome do autor e 
//# lhe é informado quantos livros tem na pilha com este autor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Autor{
    char nome[20];
    int ano ;
}Autor;

typedef struct Livro{
    char titulo[50];
    int paginas;
    struct Autor* autor;
    struct No* prox ;
}Livro;

Autor* gerarAutor( ){
    Autor* novoAutor = (Autor*) malloc( sizeof(Autor) );
    if( novoAutor == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    return novoAutor;
}

Livro* gerarLivro( ){
    Livro* novoLivro = (Livro*) malloc( sizeof(Livro) );
    if( novoLivro == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    //strcpy( novoNo->dado, _dado );
    novoLivro->prox = NULL;
    return novoLivro;
}

int mostrarMenu(){
	int opcao;
	printf( "\n -------------------------------  \n");
      printf( "| 1) Adicionar                  | \n");
      printf( "| 2) Remover                    | \n");
      printf( "| 3) Imprimir                   | \n");
      printf( "| 4) Contar Livros por autor    | \n");
      printf( "| 0) Sair                       | \n");
      printf( " -------------------------------  \n");
    printf( "Digite sua opcao:  ");
    scanf("%d" , &opcao);
    return opcao;
}



int main()
{
	char nomeAutor1[] =  "Machado de Assis";
	char nomeAutor2[] = "Erico Verissimo";
	char nome[20];
	int cont;
	
	Autor *a1 = gerarAutor();
	Autor *a2 = gerarAutor();
	strcpy( a1->nome , nomeAutor1);
	a1->ano = 1839;

	strcpy(a2->nome , nomeAutor2  );
	a2->ano = 1905;
	

    Livro *topo = NULL;
    char titulo[50];
    int paginas, indexAutor; 
    int op;
    
    do{
      	op = mostrarMenu();
        switch( op ){
            case 1:
            	printf("Digite título: ");
                scanf(" %[^\n]" , &titulo );
                printf("Digite a quantidade de páginas: ");
                scanf("%d" , &paginas );
                
                Livro *nodo = gerarLivro( );
                
                strcpy( nodo->titulo , titulo);
				nodo->paginas = paginas;
				
				printf("\n 1 - Machado de Assis"); 
				printf("\n 2 - Érico Veríssimo");
				printf("\n Escolha o autor: "); 
				scanf("%d", &indexAutor) ;
				if (indexAutor == 1 ) nodo->autor = a1; 
				if (indexAutor == 2 ) nodo->autor = a2; 
            
                nodo->prox = topo;
                topo = nodo;                
                
				break;
			case 2:
				if( topo == NULL ){
					printf("A Pilha esta vazia!");
				}else{
					Livro *aux = topo;
					topo = topo->prox;
					free( aux );
				}
				break;
			case 3:
				if( topo == NULL )
                    printf( "\nPilha Vazia! " );
                else{
                    Livro* aux = topo;
                    while( aux != NULL){
                       printf("\nTítulo: %s" , aux->titulo);
                       printf("\nPáginas: %d" , aux->paginas);
                       printf("\nAutor: %s" , aux->autor->nome);
                       printf(" - Ano: %d" , aux->autor->ano);
                       aux = aux->prox;
                    }
                }
                break;
            case 4:
            	if( topo == NULL ){
            		printf("Pilha Vazia: ");
				}else{
					printf("Digite nome do autor: ");
	                scanf(" %[^\n]" , &nome );
	                Livro *aux = topo;
	                cont = 0;
	                while( aux != NULL){
	                	if( strcmp( nome , aux->autor->nome) == 0){
	                		cont ++;
						}
						aux = aux->prox;
					}
					if( cont == 0 ){
						printf("\n%s não possui livros na pilha", nome);
					}else{
						printf("\n%s possui %d livros na pilha", nome, cont);
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














