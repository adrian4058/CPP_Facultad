#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct llamado{
	string cliente;
	int codope, duracion;
	string motivo;
};

vector<llamado>lista_llamados(int codope, vector<llamado>v);

int main(int argc, char *argv[]) {
	vector<llamado>v;
	string cliente;
	
	cout<<"Ingrese cliente: "; cin>>cliente;
	while(cliente != "FIN"){
		llamado aux;
		aux.cliente = cliente;
		cout<<"Codigo de operacion: "; cin>>aux.codope;
		cout<<"Motivo: "; cin>>aux.motivo;
		cout<<"Duracion: "; cin>>aux.duracion;
		v.push_back(aux);
		cout<<"Ingrese cliente: "; cin>>cliente;
	}
	cout<<endl<<endl;
	int codope;
	cout<<"Codigo de operario para sublista:: "; cin>>codope;
	vector<llamado>v2=lista_llamados(codope, v);
	
	return 0;
}


vector<llamado>lista_llamados(int codope, vector<llamado>v){
	vector<llamado>sublista;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].codope == codope){
			sublista.push_back(v[i]);
		}
	}
	return sublista;
}
