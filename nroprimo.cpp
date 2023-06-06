#include <iostream>
#include <cmath>
using namespace std;

//a) Leer un número natural N. Determinar con un mensaje alusivo si es primo.
//	b) Determine los 1000 primeros primos.

/// si en algun momento el modulo da 0 quiere decir que no es primo

int main() {
	
	int N, tope;
	cout<<"Ingrese N: "; cin>>N;
	tope = sqrt(N);

	for (int i = 2; i <= tope; i++){
		if( N%i == 0){ 
			cout<<"El numero no es primo: "<<endl;
			break;
		} else {
			cout<<"El numero es primo: "<<endl;
			break;
		}
	}   	
	
	return 0;
}

