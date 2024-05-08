#include <iostream>
#include "ordered.h"
using namespace std;

// Fun��o mostra como est� o pedido atutal do cliente. Recebe o vetor dos pedidos e a posi��o do vetor relacionada ao produto
float showOrdered(Ordered* ordered, int position) {

	cout << fixed;
	cout.precision(2);
	cout << " Pedido";
	cout << "\n =======\n";
	// Mostra o nome do produto pedido
	cout << " " << ordered[position].name << endl;
	// Mostra o pre�o
	cout << " R$" << ordered[position].price;
	cout << "\n =======\n";
	cout << " Quantidade: [ ]\b\b";
	// Recebe do usuario a quantidade
	cin >> ordered[position].amount;

	// Faz a conta para saber o total e retorna
	float total = ordered[position].price * ordered[position].amount;
	return total;
}