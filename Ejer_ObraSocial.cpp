#include <iostream>
#include <vector>
using namespace std;

struct Paciente{
	int nro_historia, edad;
	string ape, nom, sexo;
	string obra_social;
};
//FUNCIONES
vector<Paciente>obrasocial_sexo (vector<Paciente>pacientes, string sexo, string obra_social);
int cant_obrasocial (vector<Paciente>pacientes, string nom_obrasocial);

//MAIN
int main(int argc, char *argv[]) {
	//CARGA DE DATOS
	vector<Paciente>pacientes;
	string ape, nom, sexo, obra_social;
	int nro_historia, edad;
	
	cout<<"Apellido: "; cin>>ape;
	while(ape != "FIN"){
	Paciente newPaciente;
	cout<<"Nombre: "; cin>>nom; newPaciente.nom = nom;
	cout<<"Nro Historia Clínica: "; cin>>nro_historia; newPaciente.nro_historia = nro_historia;
	cout<<"Edad: "; cin>>edad; newPaciente.edad = edad;
	cout<<"Sexo (F o M): "; cin>>sexo; newPaciente.sexo = sexo;
	cout<<"Obra social (atilra, osecac, uom): "; cin>>obra_social; newPaciente.obra_social = obra_social;
	pacientes.push_back(newPaciente);
	cout<<"Apellido: "; cin>>ape; newPaciente.ape = ape;
	}
	
	cout<<endl;
	
	for(int i = 0; i < pacientes.size(); i++){
		cout<<"-Nro Historia: "<<pacientes[i].nro_historia<<"  -Nombre: "<<pacientes[i].nom<<"  -Apellido: "<<pacientes[i].ape;
		cout<<"  -Sexo: "<<pacientes[i].sexo<<"  -Obra Social: "<<pacientes[i].obra_social<<"  -Edad: "<<pacientes[i].edad<<endl;
	}
	//BUSQUEDA OBRA SOCIAL Y SEXO
	string search_obra, search_sexo;
	cout<<"Ingrese Obra Social: "; cin>>search_obra;
	cout<<"Ingrese Sexo (F o M): "; cin>>search_sexo;
	vector<Paciente>sublista_sexo_obra = obrasocial_sexo(pacientes, search_sexo, search_obra);
	for(int i = 0; i < sublista_sexo_obra.size(); i++){
		cout<<"Nombre: "<<sublista_sexo_obra[i].nom<<"  -Apellido: "<<sublista_sexo_obra[i].ape;
		cout<<"  -Sexo: "<<sublista_sexo_obra[i].sexo<<"  -Obra Social: "<<sublista_sexo_obra[i].obra_social<<endl;
	}
	//CANTIDAD DE PERSONAS QUE POSEEN X OBRA SOCIAL
	string nom_obrasocial;
	cout<<"Ingrese obra social a consultad cantidad: "; cin>>nom_obrasocial; cout<<endl;
	int cantidad = cant_obrasocial(pacientes, nom_obrasocial);
	cout<<"Cantidad de personas que tienen la obra social "<<nom_obrasocial<<" es: "<<cantidad;
	
	return 0;
}

//MATCH SEXO OBRA SOCIAL
vector<Paciente> obrasocial_sexo(vector<Paciente> pacientes, string sexo, string obra_social) {
	vector<Paciente> aux;
	for (int i = 0; i < pacientes.size(); i++) {
		if (pacientes[i].sexo == sexo && pacientes[i].obra_social == obra_social) {
			aux.push_back(pacientes[i]);
		}
	}
	return aux;
}

//CANT PERSONAS QUE POSEEN X OBRA SOCIAL
int cant_obrasocial (vector<Paciente>pacientes, string nom_obrasocial){
	
	int suma = 0;
	for (int i = 0; i < pacientes.size(); i++) {
		if(pacientes[i].obra_social == nom_obrasocial) {
			suma++;
		}
	}
	
	return suma;
}
