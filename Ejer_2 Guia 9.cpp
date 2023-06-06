#include <iostream>
#include <vector>
using namespace std;
//Generar aleatoriamente un arreglo lineal de 20 posiciones de 20 elementos numericos, con enteros aleatorios
//entre 100 y 150 y mostrarlo en pantall. Luego leer dos valores en las variables m y p.
//EL valor m debe ser insertado en la posicion p del arrreglo.
//Mostrar el arreglo modificado

int main(int argc, char *argv[]) {
	int m, p;
	vector<int> v(20);
	
	for (unsigned int i = 0; i < v.size(); i++) {
		v[i] = 100 + (rand()%50);
		cout<<v[i]<<" "<<endl;
	}
	
	cout<<"Ingrese el valor del numero a instertar"<<endl; cin>>m;
	cout<<"Ingrese la posicion donde se inserta el numero"<<endl; cin>>p;
	
	v.resize(v.size()+1); //Le agrego 1 mas al tamaño original del arreglo
	
	for (unsigned int i = v.size()-1; i >=p; i--) { //ultima posicion del arreglo en size-1 
		v[i] = v[i-1];	
	}

	v[p] = m;
	
	for (unsigned int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" "<<endl;
	}
	cout<<"Tamaño del arreglo"<<v.size()<<endl;
	
	return 0;
}

