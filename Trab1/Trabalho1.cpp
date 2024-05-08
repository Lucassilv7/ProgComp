// Trabalho Pr�tico 01
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cores.h"
#include "pacote.h"
#include "rede.h"

using namespace std;

// Prot�tipos das fun��es
void desenhar(int, int);
void WhiteSpace(int);

int main() {
	// Cria��o das vari�veis a serem utilizadas.
	unsigned int posA, posB, velocidadeA, velocidadeB, corA, corB, estadoA, estadoB, receberA, receberB;
	float velocidade_mediaA, velocidade_mediaB;
	// Utiliza��o da fun��o para gerar um n�mero ale�torio
	srand(unsigned(time(NULL)));
// Inicializa dados:
// - Posi��o
 	   posA = 0;
	   posB = 0;
// - Velocidade
	   velocidadeA = 0;
	   velocidadeB = 0;
	   velocidade_mediaA = 0;
	   velocidade_mediaB = 0;
// - Cores
	   corA = Cyan;
	   corB = Purple;
// - Estado da pista
	   estadoA = 0;
	   estadoB = 0;
// --------------------
	float passo = 0;
	do
	{		
			// ------------------
			// Limpa tela
			// Desenha caminh�es
			// ------------------ 
			system("cls");
			desenhar(posA, corA);
			desenhar(posB, corB);
			cout << endl;

			// ------------------------
			// Atualiza velocidade
			// Atualiza estado da pista
			// ------------------------
			velocidadeA = rand() % 10 + 1;
			velocidadeB = rand() % 10 + 1;
			estadoA = rand() % 2;
			estadoB = rand() % 2;
		
			
			// ----------------------------------
			// Transmite, recebe e processa dados
			// Calcula Pr�xima posi��o
			// ----------------------------------
			ResetarCor();
			cout << "Transmitindo dados..." << endl;
			transmitir(passo, corA, posA, velocidadeA, estadoA);
			ResetarCor();
			cout << "Recebendo dados..." << endl;
			receberA = receber();
			ResetarCor();
			cout << "Processando dados..." << endl;
			AjustarCor(corA, Black_F);
			posA = processar(receberA);
			cout << "Proxima posi��o: " << posA;
			cout << endl;
			// Parte de cima para as fun��es do primeiro caminh�o e a de baixo para o segundo caminh�o
			cout << endl;
			ResetarCor();
			cout << "Transmitindo dados..." << endl;
			transmitir(passo, corB, posB, velocidadeB, estadoB);
			ResetarCor();
			cout << "Receber dados..." << endl;
			receberB = receber();
			ResetarCor();
			cout << "Processando dados..." << endl;
			AjustarCor(corB, Black_F);
			posB = processar(receberB);
			cout << "Proxima posi��o: " << posB;
			cout << endl;
			ResetarCor();
			// -------------------------------
			// Aguarda pressionamento de tecla
			// -------------------------------
			cout << endl;
			system("pause");

			passo = passo + 1;
	} while (posA <= 100 && posB <= 100);
	// --------------------
	// Limpa tela
	// Desenha caminh�es
	// Exibe resultados
	// --------------------
	system("cls");
	desenhar(posA, corA);
	desenhar(posB, corB);
	cout << endl;

	// Mostra a quantidade de passos que teve no programa
	cout << "Passos " << passo << endl;
	cout << endl;

	// Mostra os resultados, contendo a posi��o final e a velociadade m�dia do caminh�o 1
	AjustarCor(Black_L, corA + 10);
	cout << "Posi��o";
	AjustarCor(corA, Black_F);
	cout << " " << posA << " ";
	AjustarCor(Black_L, corA + 10);
	cout << "Velociadade M�dia";
	velocidade_mediaA = posA / passo;
	// Para mostrar apenas at� duas casas decimais da velocidade.
	cout << fixed;
	cout.precision(2);
	AjustarCor(corA, Black_F);
	cout << " " << velocidade_mediaA << endl;

	// Mostra os resultados, contendo a posi��o final e a velociadade m�dia do caminh�o 2
	cout << endl;
	AjustarCor(Black_L, corB + 10);
	cout << "Posi��o";
	AjustarCor(corB, Black_F);
	cout << " " << posB << " ";
	AjustarCor(Black_L, corB + 10);
	cout << "Velociadade M�dia";
	velocidade_mediaB = posB / passo;
	// Para mostrar apenas at� duas casas decimais da velocidade.
	cout << fixed;
	cout.precision(2);
	AjustarCor(corB, Black_F);
	cout << " " << velocidade_mediaB;

	ResetarCor();
}

void desenhar(int posi, int cor) {
	AjustarCor(cor, Black_F);
	
	// Utiliza caracteres gr�ficos para desenhar o caminh�o
	WhiteSpace(posi);
	// Forma engra�ada: cout << "\t \xDC\xE2 \n";
	// Forma correta: cout << "         \xDC\xE2 \n";
	cout << "\t \xDC\xE2 \n";
	WhiteSpace(posi);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xC3\xDC\n";
	WhiteSpace(posi);
	cout << "\xDFOO\xDF\xDF\xDFO\xDF\xEE\xDF\xDFO";
	cout << "\n";
	cout << "--------------------------------------------------------------------------------------------------|--------------------";
	cout << "\n \t\t\t\t\t\t\t\t\t\t\t\t 100";
	cout << "\n";
	ResetarCor();
}

void WhiteSpace(int qtd) {
	// Respons�vel por fazer ele "andar" visualmente
	while (qtd-- > 0) cout << ' ';
}