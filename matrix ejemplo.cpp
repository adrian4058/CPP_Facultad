#include <iostream>
using namespace std;
//fila columna
matrix<int>generar_matriz(int fila, int columna);

matrix<int>generar_matriz(int fila, int columna){
	matrix<int>aux(fila,columna);
	for(int fila = 0; fila < aux.size(0) ; fila++){
		for (int columna = 0; columna < aux.size(0); columna++){
			aux[fila,col] = 100+ rand()%700;
		}
	}
	return aux;
}

int main(int argc, char *argv[]) {
	
	matrix<int>m= generar_matriz(8,8);
	

	
	
	
	return 0;
}

