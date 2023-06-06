#include <iostream>
#include <cmath>
using namespace std;


bool es_primo(int nro);


int main(int argc, char *argv[]) {
	int nro = 5;
	int cantPrimos = 0;
	bool primo;
	
	do{
		primo = es_primo(nro);
		if (primo == true){
			cout<<nro<<endl;
			cantPrimos++;
		}
		nro++;
	} while (nro < 50 );
	
	return 0;
}


bool es_primo(int nro){
	int tope = sqrt(nro);
	for(int i = 2; i <= tope; i++) {
		if (nro % i == 0) {
           //Si tiene resto 0 es porque no es primo
			return false;
		}
	}
};


