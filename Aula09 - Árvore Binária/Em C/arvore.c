#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *esq;
    struct No *dir;
};

struct No* novoNo( int numero ){
    struct No* nodo = (struct No*) malloc( sizeof( struct No) );
    nodo->valor = numero;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}
struct QueueNo {
    struct No *treeNo;
    struct QueueNo *next;
};
struct Queue {
    struct QueueNo *front;
    struct QueueNo *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct No* treeNo) {
    struct QueueNo* newQNo = (struct QueueNo*)malloc(sizeof(struct QueueNo));
    if (newQNo == NULL) {
        perror("Memory allocation failed for queue node");
        exit(EXIT_FAILURE);
    }
    newQNo->treeNo = treeNo;
    newQNo->next = NULL;

    if (q->rear == NULL) {
        q->front = newQNo;
        q->rear = newQNo;
    } else {
        q->rear->next = newQNo;
        q->rear = newQNo;
    }
}

struct No* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    struct QueueNo* temp = q->front;
    struct No* treeNo = temp->treeNo;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNo;
}

int isQueueEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void imprimirOrdemNivel(struct No* raiz) {
    if (raiz == NULL) {
        return;
    }

    struct Queue* q = createQueue();
    enqueue(q, raiz);

    while (!isQueueEmpty(q)) {
        struct No* current = dequeue(q);
        printf("%d - ", current->valor);

        if (current->esq != NULL) {
            enqueue(q, current->esq);
        }
        if (current->dir != NULL) {
            enqueue(q, current->dir);
        }
    }
    printf("\n");

    free(q);
}


struct No* inserir( struct No* raiz , int numero ){
    if ( raiz == NULL ) 
        return novoNo( numero );
        
    if( numero < raiz->valor )
        raiz->esq = inserir( raiz->esq, numero);
        
    if( numero > raiz->valor )
        raiz->dir = inserir( raiz->dir , numero);
        
    return raiz;
}

void imprimirEmOrdem( struct No* raiz){
    if( raiz != NULL ){
        imprimirEmOrdem( raiz->esq );
        printf( "%d - ", raiz->valor );
        imprimirEmOrdem( raiz->dir );
    }
}

void imprimirReversa( struct No* raiz){
    if( raiz != NULL ){
        imprimirReversa( raiz->dir );
        printf( "%d - ", raiz->valor );
	imprimirReversa( raiz->esq );
    }
}

void imprimirPreOrdem( struct No* raiz){
    if( raiz != NULL ){
        printf( "%d - ", raiz->valor );
        imprimirPreOrdem( raiz->esq );
        imprimirPreOrdem( raiz->dir );
    }
}

void imprimirPosOrdem( struct No* raiz){
    if( raiz != NULL ){
        imprimirPosOrdem( raiz->esq );
        imprimirPosOrdem( raiz->dir );
        printf( "%d - ", raiz->valor );
    }
}




int main()
{
    
    struct No* raizArvore = NULL;
    raizArvore = inserir( raizArvore, 60 );
    inserir( raizArvore, 62 );
    inserir( raizArvore, 32 );
    inserir( raizArvore, 15 );
    inserir( raizArvore, 55 );
    inserir( raizArvore, 70 );
    printf("\nPré:      ");
    imprimirPreOrdem( raizArvore );
    printf("\nEm Ordem: ");
    imprimirEmOrdem( raizArvore );
    printf("\nPós:      ");
    imprimirPosOrdem( raizArvore );
    printf("\nRevesa:      ");
    imprimirReversa( raizArvore );
    printf("\nPor Nivel:      ");
	imprimirOrdemNivel(raizArvore);
    return 0;
}
