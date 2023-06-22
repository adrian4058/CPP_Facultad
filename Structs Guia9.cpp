#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
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

tuple<persona, persona>may_tuple(vector<persona>v);
pair<persona, persona>get_mayores(vector<persona>v);

///lista por ciudad y por sexo en funciones
vector<persona>get_ciudad(vector<persona>v, string city);
vector<persona>get_sex(vector<persona>v, string sex);

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
	
	for(int i = 0; i < list_city.size(); i++) {
		cout<<list_city[i].nom<<"   DNI: "<<list_city[i].dni<<"  -  "<<list_city[i].city<<endl;
	}
	
	///llamamos a la lista por sexo
	cout<<endl<<endl;
	string sex;
	cout<<"Ingrese el sexo a buscar (F o M): "; cin>>sex;
	vector<persona>list_sex = get_sex(v, sex);
	
	for(int i = 0; i < list_sex.size(); i++) {
		cout<<list_sex[i].nom<<"   DNI: "<<list_sex[i].dni<<"  -  "<<list_sex[i].city<<"  - Sexo: "<<list_sex[i].sex<<endl;
	}
	
	//PAIR
	cout<<endl<<endl;
	pair<persona,persona>par = get_mayores(v);
	cout<<par.first.nom<<" tiene "<<par.first.edad<<" años "<<endl;
	cout<<par.second.nom<<" tiene "<<par.second.edad<<" años "<<endl;
	
	//TUPLE
	cout<<endl<<endl;
	cout<<"DOS MAYORES CON TUPLA"<<endl;
	persona p1,p2;
	tie(p1,p2) = may_tuple(v);
	cout<<p1.nom<<" tiene "<<p1.edad<<" años "<<endl;
	cout<<p2.nom<<" tiene "<<p2.edad<<" años "<<endl;
	
	return 0;
}

//GET CIUDAD
vector<persona>get_ciudad(vector<persona>v, string city){
	vector<persona>aux;
	for(int i = 0; i < v.size(); i++) {
		//si es igual a la funcion que recibo por parámetro lo pusheo al vector aux
		if(v[i].city == city) aux.push_back(v[i]);
	}
	return aux;
}
//GET SEXO
vector<persona>get_sex(vector<persona>v, string sex){
	vector<persona>sexo;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].sex == sex) sexo.push_back(v[i]);
	}
	return sexo;
}
//GET DOS MAYORES
pair<persona, persona>get_mayores(vector<persona>v){
	persona pm1, pm2;
	pair<persona, persona> may;
	pm1.edad = 0; pm2.edad = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i].edad > pm1.edad){
			pm2 = pm1;
			pm1 = v[i];
		} else {
			if(v[i].edad > pm2.edad) pm2 = v[i];
		}
	}
	may.first = pm1;
	may.second = pm2;
	return may;
}

tuple<persona, persona>may_tuple(vector<persona>v){
	persona pm1, pm2;
	pm1.edad = 0; pm2.edad = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i].edad > pm1.edad){
			pm2 = pm1;
			pm1 = v[i];
		} else {
			if(v[i].edad > pm2.edad) pm2 = v[i];
		}
	}
	return make_tuple(pm1, pm2);
}


