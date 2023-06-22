//Escriba un programa en C++ que simule un sistema de control de acceso por contrase�a de
//la siguiente manera: a) En una primer etapa debe permitir cargar los datos de los usuarios v�lidos (pares de
//datos: nombre y contrase�a). No se conoce la cantidad de usuarios v�lidos y los datos terminan con el usuario
//�ZZZ�. En esta carga inicial, debe verificar mediante un funci�n validar_contrase�a que la contrase�a no sea
//"1234", "asdf", "pass" ni la cadena vac�a; mostrando un mensaje de error y solicitando el reingreso de la misma
//en estos casos. (nota: proponga usted el prototipo de la funci�n e implem�ntela). 
#include <iostream>
#include <vector>
using namespace std;

struct personas {
	string user, password;
};

void user_password(vector<personas>& usuarios, string user, string& password);
void existe(vector<personas>usuarios, string user, string password);

int main(int argc, char* argv[]) {
	vector<personas> usuarios;
	string user, password;
	
	cout << "Ingrese su usuario: ";
	cin >> user;
	user_password(usuarios, user, password);
	
	for (int i = 0; i < usuarios.size(); i++) {
		cout << usuarios[i].user << " " << usuarios[i].password << endl;
	}
	
	cout<<endl;
	cout<<"Ingrese al sistema"<<endl; cout<<"Ingrese su usuario: "; cin>>user;
	cout<<"Ingrese su contrase�a: "; cin>>password;
	
	existe(usuarios, user, password);
	
	
	return 0;
}

void user_password(vector<personas>& usuarios, string user, string& password) {
	personas newUser;

	while (user != "ZZZ") {
		cout << "Ingrese su contrase�a: ";
		cin >> password;
		
		if (password != "1234" && password != "asdf" && password != "pass") {
			newUser.user = user;
			newUser.password = password;
			usuarios.push_back(newUser);
		} else {
			cout << "Contrase�a inv�lida, vuelta a intentar" << endl;
			cout << "Ingrese su usuario (o 'ZZZ' para salir): ";
			cin >> user;
			continue;  // Vuelve al inicio del bucle sin solicitar una nueva contrase�a
		}
		
		cout << "Ingrese su usuario (o 'ZZZ' para salir): ";
		cin >> user;
	}
}

//b) Luego, simular el verdadero
//intento de acceso al sistema. El programa debe mostrar el mensaje "Por favor, identif�quese:" y solicitar nombre
//y contrase�a. Si se ingresa un par nombre+contrase�a existente (que coincida con los cargados en el apartado a)
//se debe mostrar el mensaje "Bienvenido al sistema sr X" (reemplazando X por el nombre del usuario); sino,
//luego de 5 intentos fallidos debe mostrar el mensaje "Fuera bicho!".

void existe(vector<personas> usuarios, string user, string password) {
	int intentos = 0;
	bool accesoExitoso = false;
	
	while (intentos < 5 && accesoExitoso == false) {
		cout << "Por favor, identif�quese:" << endl;
		cout << "Nombre: ";
		cin >> user;
		cout << "Contrase�a: ";
		cin >> password;
		
		for (int i = 0; i < usuarios.size(); i++) {
			if (usuarios[i].user == user && usuarios[i].password == password) {
				cout << "Bienvenido al sistema, sr " << usuarios[i].user << endl;
				accesoExitoso = true;
				break;
			}
		}
		
		if (accesoExitoso == false) {
			intentos++;
			cout << "Intento fallido. Intentos restantes: " << 5 - intentos << endl;
		}
	}
	
	if (accesoExitoso == false) {
		cout << "Fuera bicho!" << endl;
	}
}

