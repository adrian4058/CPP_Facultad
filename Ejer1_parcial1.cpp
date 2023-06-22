//En una carrera de ciclismo por etapas, el ganador es el competidor que acumula menor
//	cantidad de tiempo sumando sus tiempos de todas las etapas. Escriba un programa que permita ingresar la
//	cantidad de competidores de una carrera de tres etapas y a continuación, por cada competidor, ingresar primero
//	nombre y apellido, y luego los tres tiempos (uno por cada etapa). Cada tiempo se ingresa mediante dos enteros,
//	que corresponden a minutos y segundos. El programa debe mostrar el nombre del ganador y su tiempo total en
//	minutos y segundos. Advertencia: 40m 40s + 50m 50s no es 90m 90s, sino 91m 30s
#include <iostream>
#include <vector>
using namespace std;

struct Competidor{
	string nom_ape;
	int etapa1_min;
	int etapa1_seg;
	int etapa2_min;
	int etapa2_seg;
	int etapa3_min;
	int etapa3_seg;
	int tiempo_total;
};

Competidor nom_ganador(vector<Competidor>competidores);

int main(int argc, char *argv[]) {
	int cant_competidores;
	cout<<"Ingrese la cantidad de competidores que participan: "; cin>>cant_competidores;
	cin.ignore();
	vector<Competidor>competidores(cant_competidores);//array
	
	for(int i = 0; i < competidores.size(); i++){
		cout<<"Nombre del competidor: "; getline(cin,competidores[i].nom_ape);
		cout<<competidores[i].nom_ape<<endl;
		cout<<"Minutos etapa 1: "; cin>>competidores[i].etapa1_min;
		cout<<"Segundos etapa 1: "; cin>>competidores[i].etapa1_seg;
		cout<<"Minutos etapa 2: "; cin>>competidores[i].etapa2_min;
		cout<<"Segundos etapa 2: "; cin>>competidores[i].etapa2_seg;
		cout<<"Minutos etapa 3: "; cin>>competidores[i].etapa3_min;
		cout<<"Segundos etapa 3: "; cin>>competidores[i].etapa3_seg;
		cin.ignore();
	}
	
	Competidor ganador_competidor = nom_ganador(competidores);
	cout<<"El ganador es "<<ganador_competidor.nom_ape<<" con "<<ganador_competidor.tiempo_total/60<<" minutos y "<<ganador_competidor.tiempo_total%60<<" segundos"<<endl;
	
	return 0;
}

Competidor nom_ganador(vector<Competidor>competidores){
	Competidor ganador;

	for(int i = 0; i < competidores.size(); i++){
		int tiempo_total = 0;
		tiempo_total += competidores[i].etapa1_min * 60;
		tiempo_total += competidores[i].etapa2_min * 60;
		tiempo_total += competidores[i].etapa3_min * 60;
		tiempo_total += competidores[i].etapa1_seg;
		tiempo_total += competidores[i].etapa2_seg;
		tiempo_total += competidores[i].etapa3_seg;
		competidores[i].tiempo_total = tiempo_total;
		if(tiempo_total < ganador.tiempo_total){
			ganador.nom_ape = competidores[i].nom_ape;
			ganador.tiempo_total = competidores[i].tiempo_total;
		}
	}
	return ganador;	
}




