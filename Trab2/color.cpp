#include <iostream>
using namespace std;

// Função não recebe parâmetro nem retorna nada, apenas utiliza o código para resetar a cor padrão
void resetColor(){
	cout << "\033[m";
}
