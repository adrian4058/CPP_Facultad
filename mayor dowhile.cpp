#include <iostream>
using namespace std;

//ingresar 10 valores numericos e informar el mayor

int main(int argc, char *argv[]) {
	int nro;
	int mayor = 0;
	int c = 0;
	
	do {
		c++;
		cout<<"Ingrese número a evaluar"<<endl;
		cin>>nro;
		
		if (nro>mayor) mayor = nro;
		
	} while (c < 10);
	
	cout<<endl<<endl;
	cout<<"El nro mayor es el nro: "<<mayor<<endl;
	
	
	return 0;
}

