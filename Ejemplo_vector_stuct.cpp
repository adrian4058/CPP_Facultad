#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
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
vector<persona>GetListaPorSexo(vector<persona>v,string sexo);
pair<persona,persona>GetDosMayores(vector<persona>v);
tuple<persona,persona>GetDosMayoresTupla(vector<persona>v);
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
	for (int i = 0;i<sublista.size();i++){
		cout<<sublista[i].nombre<<"     dni "<<sublista[i].dni<<"   -  "<<sublista[i].ciudad<<endl;
	}

	cout<<endl<<endl;
	pair<persona,persona>par = GetDosMayores(v);
	cout<<par.first.nombre<<" tiene "<<par.first.edad<<" años "<<endl;
	cout<<par.second.nombre<<" tiene "<<par.second.edad<<" años "<<endl;
	
	cout<<endl<<endl;
	cout<<"DOS MAYORES CON TUPLA"<<endl;
	persona p1,p2;
	tie(p1,p2) = GetDosMayoresTupla(v);
	cout<<p1.nombre<<" tiene "<<p1.edad<<" años "<<endl;
	cout<<p2.nombre<<" tiene "<<p2.edad<<" años "<<endl;
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
vector<persona>GetListaPorSexo(vector<persona>v,string sexo){
	// crear un vector auxiliar vacio 
	vector<persona>aux;
	for (int i = 0;i<v.size();i++){
		if (v[i].sexo == sexo){
			/// agrego todo el registro a aux
			aux.push_back(v[i]);
		}
	}
	return aux;
}

pair<persona,persona>GetDosMayores(vector<persona>v){
	persona pm1,pm2;
	pair<persona,persona>may;
	pm1.edad = 0;pm2.edad = 0;
	for (int i = 0;i<v.size();i++){
		if (v[i].edad > pm1.edad){
			pm2 = pm1;pm1 = v[i];}
		else{
			if (v[i].edad > pm2.edad){
				pm2 = v[i];
			}
		}
	}
	may.first = pm1;
	may.second = pm2;
	return may;
}
tuple<persona,persona>GetDosMayoresTupla(vector<persona>v){
	persona pm1,pm2;
	pm1.edad = 0;pm2.edad = 0;
	for (int i = 0;i<v.size();i++){
		if (v[i].edad > pm1.edad){
			pm2 = pm1;pm1 = v[i];}
		else{
			if (v[i].edad > pm2.edad){
				pm2 = v[i];
			}
		}
	}
	return make_tuple(pm1,pm2);
}
