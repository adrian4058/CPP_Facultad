#include <iostream>
#include <vector>
using namespace std;
// Defina un struct equipoF1 para guardar los datos de un equipo de Formula 1 que tiene 4
// miembros: nombre del equipo, nombre piloto titular1. nombre piloto titular 2, piloto de reserva 
// b)Escriba una funcion sustituir_piloto que reciba un vector del tipo equipoF1 y el nombre de un piloto titular
// de uno de los equipos. La función debe buscar en el vector al piloto por su nombre e intercambiarlo
// por el piloto de reserva de ese mismo equipo. La función debe retornar el vector de equipos con la 
// modificacion realizada, o la cadena "no encontrado" en caso de que no se encuentre al piloto a reemplazar dentro 
// de la lista. c)Escriba un programa cliente para probar la funcion: que permita cargar una lista de equipos, 
// sustituir un piloto que elija el usuario, mostar la nueva lista (o mensaje de error si la sustitución no se realiza)

struct EquipoF1{
	string nom_equipo;
	string pil_titular;
	string pil_titular2;
	string pil_reserva;
};

void cargar_datos(vector<EquipoF1>& v){
	EquipoF1 newTeam;
	string nom_equipo, pil_titular, pil_titular2, pil_reserva;
	
	cout<<"Ingrese nombre del equipo (FIN Termina): "; cin>>nom_equipo;
	while(nom_equipo != "FIN"){
		newTeam.nom_equipo = nom_equipo;
		cout<<"Nombre piloto titular 1: "; cin>>pil_titular;
		newTeam.pil_titular = pil_titular;
		cout<<"Nombre piloto titular 2: "; cin>>pil_titular2;
		newTeam.pil_titular2 = pil_titular2;
		cout<<"Nombre piloto suplente: "; cin>>pil_reserva;
		newTeam.pil_reserva = pil_reserva;
		v.push_back(newTeam);
		cout<<"Ingrese nombre del equipo (FIN Termina): "; cin>>nom_equipo;
	}
}

vector<EquipoF1> sustituir_piloto(vector<EquipoF1>&v, string nombre){ //poner anversan deaaa
	EquipoF1 nom_aux;
	bool encontrado = false;
	
	for(int i = 0; i < v.size(); i++){
		if(v[i].pil_titular == nombre){
			cout<<"Encontrado"<<endl;
			nom_aux = v[i];
			v[i].pil_titular = v[i].pil_reserva;
			v[i].pil_reserva = nom_aux.pil_titular;
			encontrado = true;
		}
	}
	if(!encontrado) {
		cout<<"Nombre no encontrado"<<endl;
	}else{
		cout<<"Lista de equipos"<<endl;
		for(int i = 0; i < v.size(); i++){
			cout<<i<<": "<<v[i].nom_equipo<<" |  "<<v[i].pil_titular<<"   "<<v[i].pil_titular2<<"   "<<v[i].pil_reserva<<endl;
		}
	}

	return v;
}

int main(int argc, char *argv[]) {
	vector<EquipoF1>v;
	
	cargar_datos(v);
	cout<<endl;
	
	cout<<"Lista de equipos"<<endl;
	for(int i = 0; i < v.size(); i++){
		cout<<i<<": "<<v[i].nom_equipo<<" |  "<<v[i].pil_titular<<"   "<<v[i].pil_titular2<<"   "<<v[i].pil_reserva<<endl;
	}
	cout<<endl;
	
	string nombre;
	cout<<"Nombre del piloto a sustituir: "; cin>>nombre;
	sustituir_piloto(v, nombre);
	
	
	return 0;
}

