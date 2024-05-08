// Inclui a biblioteca para utilizar o cout
#include <iostream>
using namespace std;

void AjustarCor(int corTexto, int corFundo) {
	// A fun��o vai mudar a cor do texto seguinte. A forma descrita abaixo � a padr�o para altera��o de cor
	cout << "\033[;" << corTexto << ";" << corFundo << "m";
}

void ResetarCor(void) {
	// Usa a mesma forma padr�o para voltar para cor original do texto
	cout << "\033[;30;m";
}