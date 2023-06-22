//Leer las calificaciones de un grupo de 30 alumnos que asistieron a una evaluación
//de programación. Mostrar las notas de los alumnos que se encuentren por encima
//del promedio
#include <iostream>
#include <vector>
#include <string>
using namespace std;

///declaro las funciones
vector<int>prom_encima(vector<int>nota);
vector<string>nom_encima(vector<string>alumnos);

int main(int argc, char *argv[]) {
	string nombre, notas;
	
	vector<int>nota(5);
	vector<string>alumnos(5);
	
	for (int i = 0; i < nota.size(); i++){
		cout<<"Alumno: "; getline(cin, nombre); alumnos[i] = nombre;
		cout<<"Nota: "; cin>>nota[i];
		cin.ignore();
	}
	for (int i = 0; i < nota.size(); i++){
		cout<<nota[i]<<" "<<alumnos[i]<< " "<<endl;
	}
	
	vector<int>poencima = prom_encima(nota);
	
	for (int i = 0; i < poencima.size(); i++){
		cout<<poencima[i]<<" "<<endl;
	}

	return 0;
}

vector<int>prom_encima(vector<int>nota){
	vector<int>prom;
	int suma = 0;
	for(int i = 0; i < nota.size(); i++){
		suma += nota[i];
	}
	int promedio = suma / nota.size();
		
	for(int i = 0; i < nota.size(); i++){
		if(nota[i] > promedio) prom.push_back(nota[i]);
	}

	return prom;
}
	
vector<string>nom_encima(vector<string>alumnos);





