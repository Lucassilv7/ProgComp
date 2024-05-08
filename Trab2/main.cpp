// Inclui os arquivos necess�rios

#include <iostream>
#include "color.h"
#include "text.h"
#include "stock.h"
using namespace std;

int main() {
	/*
	Cria as variaveis e vetores
		Tipo inteiro
			cp -> salva a quantidade de empresas a serem passadas
			j -> serve como contador
			normal[] -> salva a normaliza��o
			counter[] -> salva valores como contador para a constru��o do gr�fico
		Tipo ponto flutuante
			invested -> salva os valores investidos mostrados na rentabilidade 
			income -> salva os valores do rendimento mostrados na rentabilidade
			accumulated -> salva os valores acmulados mostrados na rentabilidade
			annualContribtion -> Aporte anual
			annualIncome -> Rendimento anual
	*/
	int cp, j = 1, normal[21], counter[21] = {0};
	float invested[21], income[21], accumulated[21], annualContribution, annualIncome;
	income[0] = 0;

	// Incializa��o mostrando o t�tulo e recebendo a quantidade de empresas
	cout << " ";
	showText(" Carteira de A��es ", Black, GreenF);
	resetColor();
	cout << endl;

	showText("\nQuantidade de empresas [ ]\b\b", Green, BlackF);
	resetColor();
	cin >> cp;
	generateLine('-', Green, BlackF, 26);

	// Cria um vetor din�mico do tipo empresa do tamanho da vari�vel cp
	Company * vet = new Company [cp];
	// La�o que roda baseado no cp
	for (int i = 0; i < cp; i++)
	{
		// Ler do usu�rio as informa��es das empresas e salva no vetor de empresas
		cout << "\nEmpresa: ";
		resetColor();
		cin.ignore(1);
		cin.getline(vet[i].name, 40);
		showText("Ticker: ", Green, BlackF);
		resetColor();
		cin.getline(vet[i].code, 6);
		showText("Transa��es: ", Green, BlackF);
		resetColor();
		cin >> vet[i].amountTran;
		generateLine('-', Green, BlackF, 26);
	}

	// Ap�s a leitura das empresas entra na parte das transa��es
	cout << " " << endl;
	showText("\n Transa��es Realizadas ", Black, GreenF);
	resetColor();
	cout << " " << endl;
	
	// Repete tamb�m baseado na vari�vel cp
	for (int i = 0; i < cp; i++)
	{
		// Mostra o nome da empresa relacionada a transa��o
		cout << " " << endl;
		showText(vet[i].name, Green, BlackF);
		cout << " - ";
		// Mostra o c�digo convertido para letras maisc�las
		convertUpperCase(vet[i].code);
		cout << ":\n" << endl;

		// Cria outro vetor din�mico do tipo transa��o com o tamanho baseado na quantidade de transa��es
		vet[i].trans = new Transaction[vet[i].amountTran];
		// La�o baseado na qantidade de transa��es
		for (int j = 0; j < vet[i].amountTran ; j++)
		{
			// L� as informa��es da transa��o e salva na transa��es das empresas
			showText("Data: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].date;

			showText("Quantidade: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].amount;

			showText("Pre�o: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].price;
			cout << endl;	
		}
	}
	// Limpa a tela
	system("cls");
	// Motra o resumo da carteira e salva no investimento na posi��o 0
	invested[0] = showWallet(vet, cp);
	// Coloca a linha do Prescione para continuar
	generateLine(' ', Green, BlackF, 0);
	cout << endl;
	// Da uma pausa e esperar o �suario para continuar
	system("pause");
	// Limpa a tela
	system("cls");

	// Pede ao �suario para informar o aporta anual e o rendimento anual
	showText("Aporte anual R$[    ]\b\b\b\b\b", Green, BlackF);
	resetColor();
	cin >> annualContribution;
	showText("Rendimento anual estimado [  ]%\b\b\b\b", Green, BlackF);
	resetColor();
	cin >> annualIncome;

	// Mostra o inicio da Rentabilidade da Carteira em forma de tabela 
	cout << endl;
	alignmentText("Rentabilidade da Carteira", Black, GreenF, 57);
	generateLine(' ', None, GreenF, 28);
	resetColor();
	cout << endl;
	generateLine('-', Green, BlackF, 85);
	cout << endl;
	showText(" Ano", Black, GreenF);
	generateLine(' ', Black, GreenF, 2);
	showText("Investido", Black, GreenF);
	generateLine(' ', Black, GreenF, 2);
	showText("Rendimento", Black, GreenF);
	generateLine(' ', Black, GreenF, 3);
	showText("Acumulado", Black, GreenF);
	generateLine(' ', Black, GreenF, 16);
	showText("Gr�fico", Black, GreenF);
	generateLine(' ', Black, GreenF, 23);
	resetColor();
	cout << endl;
	
	// Atribui a valor inicial investido ao inicial acumulado
	accumulated[0] = invested[0];
	// La�o que repete at� i ser 20
	for (int i = 0; i < 20; i++)
	{
		// Calcula o investeimendo, rendimento e acumulado de cada ano e salva a partir da segunda posi��o
		invested[j] = invested[i] + annualContribution;
		income[j] = (accumulated[i] + annualContribution) * (annualIncome / 100);
		accumulated[j] = accumulated[i] + annualContribution + income[j];
		// Condia��o para ele aumentar o contador j e n�o dar erro de m�moria externa acessada
		if (j < 20)
		{
			j++;
		}
	}
	// La�o que repete at� i ser 21
	for (int i = 0; i < 21; i++)
	{
		// Calcula a normaliza��o e salva no vetor normal, se o divis�o for igual a 1 ele nao acrescente mais um ap�s a multiplica��o
		if (accumulated[i] / accumulated[20] == 1)
		{
			normal[i] = (accumulated[i] / accumulated[20]) * 21;
		}
		else {
			normal[i] = ((accumulated[i] / accumulated[20]) * 21) + 1;
		}
	}
	// La�o que repete at� z ser igual a 0
	for (int z = 21, i = 0; z > 0; i++, z--)
	{
		// La�o que repete at� w ser igual a 21
		for (int w = 0; w < 21; w++)
		{
			// Se o valor de z passado incialmente for menor que o valor da normaliza��o ma posi��o w
			if (z <= normal[w])
			{
				// adiciona mais um no vetor contador na posi��o i
				counter[i]++;
			}
		}
	}
	// La�o que repete ate i ser igual a 21
	for (int i = 0; i < 21; i++)
	{
		// Mostra os valores a serem exibidos na tabela de Rentabilidade
		cout << fixed;
		cout.precision(2);
		alignmentInt(i, Black, GreenF, 3);
		showText(" ", Black, GreenF);
		alignmentFloat(invested[i], None, None, 11);
		alignmentFloat(income[i], None, None, 12);
		alignmentFloat(accumulated[i], None, None, 12);
		generateLine(' ', None, None, 5);
		// Exibi��o do gr�fico, se o valor da normaliza��o na posi��o i for menor que 22
		if (normal[i] < 22)
		{
			// Cria e inicializa a vari�vel m
			int m = 0;
			// La�o que repete a l ser maior que o valor de counter na posi��o i
			for (int l = 0; l < counter[i]; ++l)
			{
				// Se m for igual a zero ele vai passar o alinhamento onde dever� ser impresso
				if (m == 0)
				{
					// Para saber a quantidade ele pega o �ltimo valor do vetor contador e subtrai da valor da posi��o i e logo depois multiplica por 2,
					// devido o tamanho de caracteres definidos foi preciso multiplicar
					generateLine(' ', None, None, (counter[20] - counter[i]) * 2);
				}
				// Exibi o caracter do gr�fico
				showText("\xDF ", Green, BlackF);
				resetColor();
				// Soma mais um a m para que ele n�o entre no if quando voltar para o in�cio e s� ajeitar o alinhamento uma vez
				++m;
			}
		}
		cout << endl;
	}
	// Linha do final
	generateLine('-', Green, BlackF, 85);
	
	// La�o que repete pela quantidade de empresas
	for (int a = 0; a < cp; a++)
	{
		// deleta os vetores din�micos de transa��o
		delete[] vet[a].trans;
	}

	// deleta o vetor din�mico de empresas
	delete[] vet;
}