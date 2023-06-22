//Un struct definido como struct Evento { string tipo; int jugador; }; representa un evento
//ocurrido en un partido de tenis. tipo puede ser “ace”, “error no forzado”, “tiro ganador”, “doble falta”, y
//”quiebre”. jugador puede ser 1 o 2.a) Escriba una función llamada resumen_partido que reciba un
//arreglo/vector de structs de tipo Evento y un número de jugador, y retorne la cantidad de eventos de cada tipo
//para ese jugador.  b) Escriba un programa cliente que permita ingresar todos los eventos de un partido durante el
//mismo (sin conocer previamente la cantidad de eventos), y luego muestre en pantalla el resumen de cada jugador.
#include <iostream>
#include <vector>
using namespace std;

struct Evento{
	string tipo;
	int jugador;
};

void resumen_partido(vector<Evento>eventos, int nro_jugador);

int main(int argc, char *argv[]) {	
	vector<Evento>eventos;
	string tipo_evento;
	int tipo_jugador, nro_jugador;
	
//	“ace”, “error no forzado”, “tiro ganador”, “doble falta”, y ”quiebre”
	cout<<"Ingrese evento ocurrido: "; getline(cin, tipo_evento);
	while(tipo_evento != "FIN"){
		Evento event_new;
		event_new.tipo = tipo_evento;
		cout<<"Ingrese jugador: "; cin>>event_new.jugador;
		cin.ignore();
		eventos.push_back(event_new);
		cout<<"Ingrese evento ocurrido: "; getline(cin, tipo_evento);
	}
	
	cout<<"Ingrese jugador (1 o 2) del cual quiere obtener un resumen: "; cin>>nro_jugador;
	resumen_partido(eventos, nro_jugador);
	
	return 0;
}

void resumen_partido(vector<Evento>eventos, int nro_jugador){
	vector<Evento>aux;
	int aceCount = 0, errorCount = 0, tiroCount = 0, dobleCount = 0, quiebreCount = 0;
	for(int i = 0; i < eventos.size(); i++) {
		if(eventos[i].jugador == nro_jugador){
			if (eventos[i].tipo == "ace"){
				aceCount++;
			} else if (eventos[i].tipo == "error no forzado") {
				errorCount++;
			} else if (eventos[i].tipo == "tiro ganador") {
				tiroCount++;
			} else if (eventos[i].tipo == "doble falta") {
				dobleCount++;
			} else if (eventos[i].tipo == "quiebre"){
				quiebreCount++;
			}
		}
	}
	cout<<"Resumen para el jugador: "<<nro_jugador<<endl;
	cout<<"Cantidad de Aces: "<<aceCount<<endl;
	cout<<"Cantidad de Errores No Forzados: "<<errorCount<<endl;
	cout<<"Cantidad de Tiros Ganadores: "<<tiroCount<<endl;
	cout<<"Cantidad de Dobles Faltas: "<<dobleCount<<endl;
	cout<<"Cantidad de Quiebres: "<<quiebreCount<<endl;
}

