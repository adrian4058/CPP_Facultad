#include <iostream>
#include <vector>
using namespace std;
/**
Existe una ficha de personas con los datos DNI, nombre, sexo, edad, ciudad
Cargar un vector de struct hasta que el nombre sea la palabra "FIN"
**/

///STRUCT ES UN  ¡¡¡TIPO DE DATO!!!!
struct persona{
	int dni;
	string nom, sex, city;
	int edad;
};

///codificar una funcion que retorne una sublista con las personas de una ciudad que se ingresa como parámetro
vector<persona>get_ciudad(vector<persona>v, string city);

///HACER GET LISTA POR SEXO

int main(int argc, char *argv[]) {
	//tipo de dato Persona almacenado en p;
	persona p;
	
/// un VECTOR del tipo PERSONA, o sea un ARREGLO de PERSONAS del tipo STRUCT 
	vector<persona>v;
	string nom; //declaro la variable nom que luego le asigno al atributo nom del tipo persona
	
	cout<<"Ingrese nombre: "; getline(cin, nom);
	while (nom != "FIN") {
		//creo una instancia nueva de la persona
		persona p;
		p.nom = nom;
		cout<<"DNI: "; cin>>p.dni;
		cout<<"Sexo (F o M): "; cin>>p.sex;
		cout<<"Edad: "; cin>>p.edad;
		cin.ignore();
		cout<<"Ciudad: "; getline(cin,p.city);
		v.push_back(p); //pusheo la nueva persona al vector v
		cout<<"Ingrese nombre: "; getline(cin, nom);
	}
	
	for(int i = 0; i < v.size(); i++) {
		cout<<v[i].nom<<"   DNI: "<<v[i].dni<<"  -  "<<v[i].city<<endl;
	}
	
	///llamamos a la lista por ciudad
	cout<<endl<<endl;
	string city;
	cout<<"Ingrese la ciudad a buscar: "; getline(cin,city);
	vector<persona>list_city = get_ciudad(v, city);
	
	for(int i = 0; i < v.size(); i++) {
		cout<<list_city[i].nom<<"   DNI: "<<list_city[i].dni<<"  -  "<<list_city[i].city<<endl;
	}
	
	return 0;
}

vector<persona>get_ciudad(vector<persona>v, string city){
	vector<persona>aux;
	
	for(int i = 0; i < v.size(); i++) {
		//si es igual a la funcion que recibo por parámetro lo pusheo al vector aux
		if(v[i].city == city) aux.push_back(v[i]);
	}
	return aux;
}



