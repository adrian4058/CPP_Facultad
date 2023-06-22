#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
//El código fuente de un proyecto de software muy grande esta dividido en muchos archivos.
//Se desea analizar la longitud de cada uno y del proyecto completo. a)Escriba un programa
//que permita cargar por cada uno de los N(dato) archivos 3 valores: nombre, cant lineas de codigo
// y cantidad de funciones que define; y guarde toda esta información en un único vector. b)Luego debe
//informar por cada archivo el promedio de lineas por funcion. c)Los nombres de los dos archivos con mas
//lineas de código; y d)las cantidaddes totales de líneas y de funciones sumando todos los archivos.
//Resuelva implementando una funcion para cada uno de los items c y d que calcule lo que se requiere informar
//desde el programa principal main.

struct Archivo{
	string nombre;
	int cant_lineas;
	int cant_funciones;
};

void cargar_datos(vector<Archivo>&v){
	string nombre; int cant_lineas, cant_funciones;
	cout<<"Nombre del archivo (FIN termina): "; cin>>nombre;
	while(nombre != "FIN"){
		Archivo newArchivo;
		newArchivo.nombre = nombre;
		cout<<"Cantidad de lineas de código: "; cin>>cant_lineas;
		newArchivo.cant_lineas = cant_lineas;
		cout<<"Cantidad de funciones: "; cin>>cant_funciones;
		newArchivo.cant_funciones = cant_funciones;
		v.push_back(newArchivo);
		cout<<"Nombre del archivo (FIN termina): "; cin>>nombre;
	}
}

void prom_lineas(vector<Archivo>v){
	for(int i = 0; i < v.size(); i++){
		float prom = 0;
		prom = v[i].cant_lineas / v[i].cant_funciones;
		cout<<"Promedio de "<<prom<<" lineas de código del archivo: "<<i<<endl;
	}
}
	
//c)Los nombres de los dos archivos con mas lineas de código
tuple<Archivo, Archivo> get2_mayores(vector<Archivo>v){
	Archivo may1, may2;
	may1.cant_lineas = 0; may2.cant_lineas = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i].cant_lineas > may1.cant_lineas){
			may2 = may1;
			may1 = v[i];
		} else {
			if(v[i].cant_lineas > may2.cant_lineas) {
				may2 = v[i];
			}
		}
	}
	return make_tuple(may1, may2);
}

//d)las cantidades totales de líneas y de funciones sumando todos los archivos
tuple<int, int> cant_linfun(vector<Archivo>v){
	int may_lineas = 0, may_funciones = 0;
	
	for(int i = 0; i < v.size(); i++){
		may_lineas += v[i].cant_lineas;
		may_funciones += v[i].cant_funciones;
	}
	
	return make_tuple(may_lineas, may_funciones);
}

int main(int argc, char *argv[]) {
	vector<Archivo>v;
	string nombre;
	int cant_lineas, cant_funciones;
	
	cargar_datos(v);
	cout<<endl;
	
	for(int i = 0; i < v.size(); i++){
		cout<<i<<": "<<v[i].nombre<<".  -Cant de líneas: "<<v[i].cant_lineas<<".  -Cant funciones: "<<v[i].cant_funciones<<"."<<endl;
	}
	cout<<endl;

	prom_lineas(v);
	cout<<endl;
	
	cout<<"Mayor cantidad de lineas"<<endl;
	Archivo a1, a2;
	tie(a1, a2) = get2_mayores(v);
	cout<<a1.nombre<<endl;
	cout<<a2.nombre<<endl;
	cout<<endl;
	
	int l1, f1;
	tie(l1, f1) = cant_linfun(v);
	cout<<"Cantidad total de lineas: "<<l1<<endl;
	cout<<"Cantidad total de funciones: "<<f1<<endl;
	
	return 0;
}

