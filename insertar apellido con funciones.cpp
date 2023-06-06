#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Se lee un arreglo ordenado en forma creciente de 100 palabras (orden alfabético) y
//se desea insertar un nuevo elemento de forma que se preserve el orden alfabético.
//Codifique dos funciones llamadas busca_pos() e inserta(). La primera debe
//localizar y devolver la posición en la que debería insertarse un elemento para
//mantener el arreglo ordenado, mientras que la segunda debe recibir el elemento y
//la posición e insertarlo en el arreglo.	

///declaro funciones
int busca_pos(vector<string>v, string nombre);
void inserta(vector<string>&v, string nombre);

int main(int argc, char *argv[]) {
	string nom, nombre;
	vector<string>v(5);
	
	///ingreso los 5 apellidos
	for(unsigned int i = 0; i < v.size(); i++) {
		cin>>nom;
		v[i] = nom;
	}
	
	cout<<" "<<endl;
	
	///leo los 5 apellidos
	for(unsigned int i = 0; i < v.size(); i++) {
		cout<<v[i]<<endl;
	}
	
	cout<<" "<<endl;
	
	///ingreso nuevo apellido a insertas
	cout<<"Ingrese apellido a insertar: "; cin>>nombre;
	inserta(v, nombre); ///llamo a la funcion inserta para colocar el apellido en la posición correcta
	
	cout<<" "<<endl;
	
	cout<<"Nueva lista: "<<endl;
	for(unsigned int i = 0; i < v.size(); i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}

///desarrollo las funciones
int busca_pos(vector<string>v, string nombre){
}
int pos = 0;
	for(unsigned int i = 0; i < v.size(); i++) {
		if (v[i] > nombre) {
		pos = i;
		return pos;
		}
	}
	return -1;
}

void inserta(vector<string>&v, string nombre){
	int pos = busca_pos(v,nombre);
	if(pos == -1) {
		v.push_back(nombre);
	} else{
		v.resize(v.size()+1);
		for(int i = v.size()-1; i > pos; i--) {
			v[i] = v[i-1];
		}
		v[pos] = nombre;
	}
}




