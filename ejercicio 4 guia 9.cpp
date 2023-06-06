#include <iostream>
#include <vector>
#include <string>

///PUSHBACK, GETLINE, IGNORE 

using namespace std;
//Leer los nombres y calificaciones de un grupo de alumnos que asistieron a una
//evaluación de programación. Los datos finalizan con la calificación 0. Generar un
//vector con los nombres de los alumnos aprobados (calificación>=6) y otro con los
//nombres de los no aprobados. Mostrar luego ambos vectores


int main(int argc, char *argv[]) {
	string alumno; int nota; 
	
	vector<string>aprobados;
	vector<string>noaprobados;
	
	cout<<"Ingrese nota del alumno"; cin>>nota;	
	
	while(nota != 0) {
		
		cout<<"Ingrese nombre alumno a evaluar"; cin>>alumno;
		
		if(nota > 5) {
			aprobados.push_back(alumno);
		} else { 
			noaprobados.push_back(alumno);
		}
		cout<<"Ingrese nota del alumno"; cin>>nota;
	};
	
	for (unsigned int i = 0; i < aprobados.size(); i++) {
		cout<<"Aprobados: "<<aprobados[i]<<" ";
	}
	for (unsigned int i = 0; i < noaprobados.size(); i++) {
		cout<<"NoAprobados: "<< noaprobados[i]<<" ";
	}
	

	return 0;
}

