#include <iostream>
#include "text.h"
using namespace std;

// Mostra o menu para pedido iformando quem n�o est� mais disp�nivel
void menu(Product* vet, unsigned short tam)
{
	char cod = 65;
	cout << "\n ===========\n";
	for (int i = 0; i < tam ; i++)
	{
		if (vet[i].amount <= 0)
		{
			cout << " (" << cod << ") " << vet[i].name << " - INDISPON�VEL\n";
		}
		else
		{
			cout << " (" << cod << ") " << vet[i].name << endl;
		}

		if (cod == 'R')
		{
			cod += 2;
		}
		else
		{
			cod += 1;
		}
	}
	cout << " (S) Sair";
	cout << "\n ===========\n";
	cout << " Op��o: [ ]\b\b";
}

// Mostra o menu de pagamento
double menuPayment(double pay, double delivery)
{
	cout << "\n  ===========\n";
	cout << " Total = R$" << pay + delivery << endl;
	cout << "\n (P) Pix\n";
	cout << " (C) Cart�o";
	cout << "\n  ===========\n";
	cout << " Pagamento: [ ]\b\b";

	return pay + delivery;
}

// Mostra o menu de controle para o estoque
void menuControll(void)
{
	cout << "\n ===================\n";
	cout << " (A)dicionar\n";
	cout << " (E)xcluir\n";
	cout << " (L)istar\n";
	cout << " (S)air";
	cout << "\n ===================\n";
	cout << " Op��o: [ ]\b\b";
}


