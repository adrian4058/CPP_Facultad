#include <iostream>
#include <vector>
using namespace std;
/**
Existe una ficha de personas con los datos
DNI,nombre,sexo,edad,ciudad
Cargar un vector de struct hasta que el nombre sea la
palabra "FIN"
**/

/// definir un struct equivale a crear un tipo de dato.
struct persona{
	int dni;
	string nombre,sexo,ciudad;
	int edad;
};
/// codificar una función que retorne una sublista con las personas de una
/// ciudad que se ingresa como parámetro
vector<persona>GetListaPorCiudad(vector<persona>v,string ciudad);
int main() {
    
	vector<persona>v;
	string nombre;
	
	cout<<"Ingrese nombre : ";getline(cin,nombre);
	while (nombre != "FIN"){
		persona p;
		p.nombre = nombre;
		cout<<"DNI ";cin>>p.dni;
		cout<<"Sexo (F o M) : ";cin>>p.sexo;
		cout<<"Edad ";cin>>p.edad;
		cin.ignore(); /// saca el ENTER del buffer de teclado para el proximo getline
		cout<<"Ciudad : ";getline(cin,p.ciudad);
		v.push_back(p); /// agrego la variable de tipo persona a la lista
		cout<<"Ingrese nombre : ";getline(cin,nombre);
	}
	
	/// Mostrar en pantalla
	for (int i = 0;i<v.size();i++){
		cout<<v[i].nombre<<"     dni "<<v[i].dni<<"   -  "<<v[i].ciudad<<endl;
	}
    /// llamado de la sublista por ciudad
	cout<<endl<<endl;
	string ciudad;
	cout<<"Ciudad a buscar: ";getline(cin,ciudad);
	vector<persona>sublista = GetListaPorCiudad(v,ciudad);
	for (int i = 0;i<v.size();i++){
		cout<<sublista[i].nombre<<"     dni "<<sublista[i].dni<<"   -  "<<sublista[i].ciudad<<endl;
	}
	
	return 0;
}
vector<persona>GetListaPorCiudad(vector<persona>v,string ciudad){
	/// crear un vector auxiliar vacio 
	vector<persona>aux;
	for (int i = 0;i<v.size();i++){
		if (v[i].ciudad == ciudad){
			/// agrego todo el registro a aux
			aux.push_back(v[i]);
		}
	}
	return aux;
}
