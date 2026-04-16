#include <stdio.h>

int somarAte( int valor){
	if( valor == 1 ) 
		return 1;
	return valor + somarAte( valor - 1 );
}

int fatorial( int valor){
	if( valor == 1 ) 
		return 1;
	return valor * fatorial( valor - 1 );
}

int main(){

	printf( "Soma de 1 ate 5: %d", somarAte(5) );
	printf( "\nSoma de 1 ate 10: %d", somarAte(10) );
	printf( "\nFatorial de 5 eh: %d", fatorial(5) );
	printf( "\nFatorial de 10 eh: %d", fatorial(10) );
	
	return 0;
	
}