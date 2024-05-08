// Bibliotecas importadas para o funcionamento.
#include <iostream>
#include "pacote.h"
#include "cores.h"
using namespace std;

// Criação da variável global.
unsigned int rede;

void transmitir(unsigned int pass, unsigned int color, unsigned int position, unsigned int speed, unsigned int lane) {
	// A variável global recebe o valor da função empacotar, vindo da biblioteca pacote.
	rede = empacotar(pass, color, position, speed, lane);
	
	// Ajusta a cor do texto, imprime o valor que está na variável rede e logo após resta a cor.
	AjustarCor(Black_L, color + 10);
	cout << rede << endl;
	ResetarCor();
	
}
unsigned int receber(void) {
	unsigned int color, oleo;
	// Salva o valor desempacotado da cor.
	color = cor(rede);

	// Organiza todo o texto a ser mostrado, da parte de recebendo dados, ajeitando as cores 
	// baseado na variavel criada acima. Na parte do oleo como tinha que mostra "verdadeiro" ou 
	// "falso" usei um if para isso.
	AjustarCor(color, Black_F);
	cout << "Frame";
	AjustarCor(Black_L, color + 10);
	cout << passo(rede) << " ";
	AjustarCor(color, Black_F);
	cout << "Pos ";
	AjustarCor(Black_L, color + 10);
	cout << posição(rede) << " ";
	AjustarCor(color, Black_F);
	cout << "Vel ";
	AjustarCor(Black_L, color + 10);
	cout << velocidade(rede) << " ";
	AjustarCor(color, Black_F);
	cout << "Oil ";
	AjustarCor(Black_L, color + 10);
	oleo = pista(rede);
	if (oleo == 0)
	{
		cout << "False";
	}
	else
	{
		cout << "True";
	}
	cout << endl;

	// retorna o valor da rede.
	return rede;
}
unsigned int processar(unsigned int info) {
	unsigned int posição_atual, velo, oleo, nova_posição;

	// Operação para pegar a nova posição do caminhão. Os valores recebidos das variáveis são os 
	// desempacotados.
	posição_atual = posição(info);
	velo = velocidade(info);
	oleo = pista(info);
	nova_posição = posição_atual + velo - oleo;

	return nova_posição;
}