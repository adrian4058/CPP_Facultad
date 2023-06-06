#include <iostream>using namespace std;
int facto(int nro){	int cumulo=1;	for (int i=1;i<=nro;i++){		cumulo*=i;	}	return cumulo;}
	int main(int argc, char *argv[]) {		int num;		cout<<"Ingrese un número para sacar el factorial: "; cin>>num;		cout<<"El factorial del número es: "<<facto(num);		return 0;}
	
