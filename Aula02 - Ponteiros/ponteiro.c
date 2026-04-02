/******************************************************************************

25/02/2026

Construa um algoritmo usando ponteiros que tenha 2 funções:

1) Função que recebe 2 endereços de memória e some estes 2 valor e guarde o ,
resultado em um terceiro endereço de memória

2) Função que recebe 2 endereços de memória e inverta os valores destes endereços
*******************************************************************************/
#include <stdio.h>

void somar(int *v1, int *v2 , int *resultado){
    *resultado = *v1 + *v2;
}
void trocar(int *v1, int *v2 ){
    int a = *v1;
    *v1 = *v2;
    *v2 = a;
}
                                           //dontpad.com/ed20261
int main()
{
    int x = 2, y = 3;
    int soma;
    somar(&x , &y, &soma);
    printf("Soma: %d" , soma);
    trocar(&x , &y);
    printf("\nNovo valor de x: %d", x);
    printf("\nNovo valor de y: %d", y);
    return 0;
}

