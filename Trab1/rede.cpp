// Bibliotecas importadas para o funcionamento.
#include <iostream>
#include "pacote.h"
#include "cores.h"
using namespace std;

// Cria��o da vari�vel global.
unsigned int rede;

void transmitir(unsigned int pass, unsigned int color, unsigned int position, unsigned int speed, unsigned int lane) {
	// A vari�vel global recebe o valor da fun��o empacotar, vindo da biblioteca pacote.
	rede = empacotar(pass, color, position, speed, lane);
	
	// Ajusta a cor do texto, imprime o valor que est� na vari�vel rede e logo ap�s resta a cor.
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
	cout << posi��o(rede) << " ";
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
	unsigned int posi��o_atual, velo, oleo, nova_posi��o;

	// Opera��o para pegar a nova posi��o do caminh�o. Os valores recebidos das vari�veis s�o os 
	// desempacotados.
	posi��o_atual = posi��o(info);
	velo = velocidade(info);
	oleo = pista(info);
	nova_posi��o = posi��o_atual + velo - oleo;

	return nova_posi��o;
}