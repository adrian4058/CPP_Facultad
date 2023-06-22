//Una empresa distribuidora comercializa 25 art�culos. Posee 4 sucursales y desea
//analizar el desempe�o de las mismas. Para ello se ingresan los datos
//correspondientes a las ventas efectuadas en cierto per�odo: c�digo sucursal (1...4),
//c�digo art�culo (1...25), cantidad unidades vendidas. Determine e informe:
//a. Las cantidades de unidades vendidas por la empresa de cada art�culo.
//b. El total de unidades vendidas por la sucursal 3, sumando todos los
//art�culos.
//c. La cantidad vendida por la sucursal 1 del art�culo 6.
//d. La sucursal que vendi� m�s unidades del art�culo 8.
#include <iostream>
#include <matrix>
using namespace std;

int main(int argc, char *argv[]) {
	matrix<int>ventas(2,2,0);
	int cod_art, cod_suc;
	
	int cant = ventas.size(0) * ventas.size(1);  ///??���
	
	for (int i = 0; i < cant; i++) {
		cout<<"Ingrese codigo de articulo: "; cin>>cod_art;
		cout<<"Ingrese codigo de sucursal: "; cin>>cod_suc;
		cout<<"Cantidad: "; cin>>ventas[cod_art-1][cod_suc-1];
	}
	
	for(int i = 0; i < ventas.size(0); i++){
		int suma = 0;
		for(int j = 0; j < ventas.size(1); j++){
			suma += ventas[i][j];
		}
		cout<<"Del articulo "<<i<<" se vendieron "<<suma<<endl;
	}
	
	int sumasuc3 = 0;
	for(int i = 0; i < ventas.size(0); i++){
		sumasuc3 += ventas[i][2]; //2 pq el indice empieza en 0 en c++ chavalin, sigan viendo
	}
	cout<<"La sucursal 3 vendio: "<<sumasuc3<<endl;
	
	return 0;
}

