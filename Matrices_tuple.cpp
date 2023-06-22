//En una olimp�ada estudiantil compiten N alumnos en 3 pruebas (1: matem�ticas, 2:
//f�sica y 3: computaci�n). Se ingresan por cada inscripto el DNI y su n�mero
//asignado para la competencia (entre 1 y N). Luego, sin orden alguno, se van
//ingresando ternas con los puntajes de cada prueba: n�mero de participante, c�digo
//de prueba, y puntaje en la actividad. Escriba un algoritmo que determine: a) El DNI
//del ganador de la competencia y el puntaje total obtenido. b) El DNI del estudiante
//que ocup� el 2do lugar y su puntaje. c) �Qu� puntaje obtuvo en Computaci�n el
//ganador de la competencia?
#include <iostream>
#include <vector>
#include <matrix>
#include <tuple>
using namespace std;

tuple<int, int, int, int>ganador (matrix<int>notas, vector<int>DNIs);

int main(int argc, char *argv[]) {
	int N, c = 0, nro_asignado, nro_dni, nota, codmateria;
	cout<<"Ingrese la cantidad de alumnos: "; cin>>N;
	vector<int>DNIs(N);
	matrix<int>notas(N,3);
	
	//nro de participante es su pocision en el arreglo
	//codigo de prueba de 1 a 3
	while(c < N){
		cout<<"Ingrese n�mero asignado para la competencia: "; cin>>nro_asignado;
		cout<<"Ingrese n�mero de DNI del participante: "; cin>>nro_dni;
		c++;
		DNIs[nro_asignado-1] = nro_dni;
	}
	
	for(int i = 0; i<N*3; i++){
		cout<<"Codigo de alumno: "; cin>>nro_asignado;
		cout<<"Codigo de materia: "; cin>>codmateria;
		cout<<"Nota: "; cin>>notas[nro_asignado-1][codmateria-1];
	}
	
	int mayor_dni1, puntaje_mayor1, mayor_dni2, puntaje_mayor2;
	tie(mayor_dni1, puntaje_mayor1, mayor_dni2, puntaje_mayor2) = ganador(notas, DNIs);
	cout<<"El puntaje mayor 1 es: "<<puntaje_mayor1<<" con el DNI: "<<mayor_dni1<<endl;
	cout<<"El puntaje mayor 2 es: "<<puntaje_mayor2<<" con el DNI: "<<mayor_dni2<<endl;
	
	return 0;
}

tuple<int, int, int, int>ganador (matrix<int>notas, vector<int>DNIs){
	int mayor_dni1, puntaje_mayor1, mayor_dni2, puntaje_mayor2;
	
	for (int i = 0; i < DNIs.size(); i++){
		int suma = 0;
		for (int j = 0; i < notas.size(1); j++){ //notas.size(1) es la cantidad de columnas o sea = 1
			suma += notas[i][j];
		}
		if(suma > puntaje_mayor1){
			puntaje_mayor2 = puntaje_mayor2;
			puntaje_mayor1 = suma; 
		} else {
			if (suma > puntaje_mayor2) puntaje_mayor2 = suma;
		}
	}
	
	return make_tuple(mayor_dni1, puntaje_mayor1, mayor_dni2, puntaje_mayor2);
}

