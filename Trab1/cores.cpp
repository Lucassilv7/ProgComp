// Inclui a biblioteca para utilizar o cout
#include <iostream>
using namespace std;

void AjustarCor(int corTexto, int corFundo) {
	// A função vai mudar a cor do texto seguinte. A forma descrita abaixo é a padrão para alteração de cor
	cout << "\033[;" << corTexto << ";" << corFundo << "m";
}

void ResetarCor(void) {
	// Usa a mesma forma padrão para voltar para cor original do texto
	cout << "\033[;30;m";
}