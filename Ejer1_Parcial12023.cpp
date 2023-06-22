#include <iostream>
#include <vector>
using namespace std;
//escriba una funcion buscar que reciba un vector de strings v, un string s, y una posicion p
//. La funcion debe buscar el valor de s en el vector v, solo desde la posicion p en adelante
// y retornar la primera posicion donde lo encuentre, o -1 en caso de no encontrarlo.
// b)Utilizando la funcion buscar, escriba una funcion reemplazar que reciba un vector de strings,
// y dos strings s1 y s2. La funcion debe reemplazar todas las ocurrencias de s1 en el vector por s2
// y retornar la cantidad de reemplazo realizados.	

int buscar(vector<string>v, string s, int pos = 0);
int reemplazar(vector<string>&v, string s1, string s2);

int main(int argc, char *argv[]) {
	vector<string>v;   v.push_back("perro");v.push_back("gato");v.push_back("manzana");v.push_back("computadora");v.push_back("pelota");
	v.push_back("sol");v.push_back("mesa");v.push_back("libro");v.push_back("telefono");v.push_back("casa");v.push_back("perro");v.push_back("perro");
	
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<" - ";
	}
	
	string s; int pos;
	cout<<"Ingrese la palabra a buscar: "; cin>>s;
	cout<<"Ingrese desde que posición: "; cin>>pos;
	cout<<endl;
	
	int numero = buscar(v, s, pos);
	cout<<"Coincidencia en la posicion: "<<numero<<endl;
	
	string s1, s2;
	cout<<"Ingrese la palabra a reemplazar: "; cin>>s1;
	cout<<"Ingrese la palabra nueva: "; cin>>s2;
	int cant_reemplazos = reemplazar(v, s1, s2);
	cout<<"Cantidad de reeplazos"<<cant_reemplazos;
	cout<<endl;
	cout<<"Nuevo arreglo:"<<endl;
	for(int i = 0; i < v.size(); i++){
		cout<<v[i]<<" - ";
	}
	
	return 0;
}

int buscar(vector<string>v, string s, int pos){
	for(int i = pos; i < v.size(); i++){
		if(v[i] == s){
			pos = i;
			return pos;
		}
	}
	return -1;
}

int reemplazar(vector<string>&v, string s1, string s2){
	int reemplazos;
	int pos = buscar(v, s1);
	while(pos != -1){
		v[pos] = s2;
		reemplazos++;
		pos = buscar(v,s1,pos+1);
	}
	return reemplazos;
}




