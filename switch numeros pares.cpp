#include <iostream>
using namespace std;

//Escriba un programa C++ que permita ingresar natural N como dato. Obtener
//	todos los pares menores a N. Tener en cuenta que el dato puede ser tanto par
//	como impar. Debe dar al usuario la posibilidad de seleccionar por un menú la
//	opción de visualizar el listado:
//	a) En forma creciente.
//	b) En forma decreciente

int main() {
	int nro, opc;
	
	cout<<"Ingrese número a evaluar "; cin>>nro;
	cout<<"Ingrese opción (1 Creciente, 2 Decreciente) "; cin>>opc;
	
	
	
	switch (opc) {
		case 1:
			for (int i = 1; i<nro; i++){
				if (i%2==0) cout<<i<<" ";
			}
		break;
	    case 2:
			for (int i = nro; i>1; i--){
				if(i%2==0) cout<<i<<" ";
			}
		break;
	}
	
	
	return 0;
}

