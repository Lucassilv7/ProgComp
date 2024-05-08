// Inclui os arquivos necessários

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
			normal[] -> salva a normalização
			counter[] -> salva valores como contador para a construção do gráfico
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

	// Incialização mostrando o título e recebendo a quantidade de empresas
	cout << " ";
	showText(" Carteira de Ações ", Black, GreenF);
	resetColor();
	cout << endl;

	showText("\nQuantidade de empresas [ ]\b\b", Green, BlackF);
	resetColor();
	cin >> cp;
	generateLine('-', Green, BlackF, 26);

	// Cria um vetor dinâmico do tipo empresa do tamanho da variável cp
	Company * vet = new Company [cp];
	// Laço que roda baseado no cp
	for (int i = 0; i < cp; i++)
	{
		// Ler do usuário as informações das empresas e salva no vetor de empresas
		cout << "\nEmpresa: ";
		resetColor();
		cin.ignore(1);
		cin.getline(vet[i].name, 40);
		showText("Ticker: ", Green, BlackF);
		resetColor();
		cin.getline(vet[i].code, 6);
		showText("Transações: ", Green, BlackF);
		resetColor();
		cin >> vet[i].amountTran;
		generateLine('-', Green, BlackF, 26);
	}

	// Após a leitura das empresas entra na parte das transações
	cout << " " << endl;
	showText("\n Transações Realizadas ", Black, GreenF);
	resetColor();
	cout << " " << endl;
	
	// Repete também baseado na variável cp
	for (int i = 0; i < cp; i++)
	{
		// Mostra o nome da empresa relacionada a transação
		cout << " " << endl;
		showText(vet[i].name, Green, BlackF);
		cout << " - ";
		// Mostra o código convertido para letras maiscúlas
		convertUpperCase(vet[i].code);
		cout << ":\n" << endl;

		// Cria outro vetor dinâmico do tipo transação com o tamanho baseado na quantidade de transações
		vet[i].trans = new Transaction[vet[i].amountTran];
		// Laço baseado na qantidade de transações
		for (int j = 0; j < vet[i].amountTran ; j++)
		{
			// Lê as informações da transação e salva na transações das empresas
			showText("Data: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].date;

			showText("Quantidade: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].amount;

			showText("Preço: ", Green, BlackF);
			resetColor();
			cin >> vet[i].trans[j].price;
			cout << endl;	
		}
	}
	// Limpa a tela
	system("cls");
	// Motra o resumo da carteira e salva no investimento na posição 0
	invested[0] = showWallet(vet, cp);
	// Coloca a linha do Prescione para continuar
	generateLine(' ', Green, BlackF, 0);
	cout << endl;
	// Da uma pausa e esperar o úsuario para continuar
	system("pause");
	// Limpa a tela
	system("cls");

	// Pede ao úsuario para informar o aporta anual e o rendimento anual
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
	showText("Gráfico", Black, GreenF);
	generateLine(' ', Black, GreenF, 23);
	resetColor();
	cout << endl;
	
	// Atribui a valor inicial investido ao inicial acumulado
	accumulated[0] = invested[0];
	// Laço que repete até i ser 20
	for (int i = 0; i < 20; i++)
	{
		// Calcula o investeimendo, rendimento e acumulado de cada ano e salva a partir da segunda posição
		invested[j] = invested[i] + annualContribution;
		income[j] = (accumulated[i] + annualContribution) * (annualIncome / 100);
		accumulated[j] = accumulated[i] + annualContribution + income[j];
		// Condiação para ele aumentar o contador j e não dar erro de mémoria externa acessada
		if (j < 20)
		{
			j++;
		}
	}
	// Laço que repete até i ser 21
	for (int i = 0; i < 21; i++)
	{
		// Calcula a normalização e salva no vetor normal, se o divisão for igual a 1 ele nao acrescente mais um após a multiplicação
		if (accumulated[i] / accumulated[20] == 1)
		{
			normal[i] = (accumulated[i] / accumulated[20]) * 21;
		}
		else {
			normal[i] = ((accumulated[i] / accumulated[20]) * 21) + 1;
		}
	}
	// Laço que repete até z ser igual a 0
	for (int z = 21, i = 0; z > 0; i++, z--)
	{
		// Laço que repete até w ser igual a 21
		for (int w = 0; w < 21; w++)
		{
			// Se o valor de z passado incialmente for menor que o valor da normalização ma posição w
			if (z <= normal[w])
			{
				// adiciona mais um no vetor contador na posição i
				counter[i]++;
			}
		}
	}
	// Laço que repete ate i ser igual a 21
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
		// Exibição do gráfico, se o valor da normalização na posição i for menor que 22
		if (normal[i] < 22)
		{
			// Cria e inicializa a variável m
			int m = 0;
			// Laço que repete a l ser maior que o valor de counter na posição i
			for (int l = 0; l < counter[i]; ++l)
			{
				// Se m for igual a zero ele vai passar o alinhamento onde deverá ser impresso
				if (m == 0)
				{
					// Para saber a quantidade ele pega o último valor do vetor contador e subtrai da valor da posição i e logo depois multiplica por 2,
					// devido o tamanho de caracteres definidos foi preciso multiplicar
					generateLine(' ', None, None, (counter[20] - counter[i]) * 2);
				}
				// Exibi o caracter do gráfico
				showText("\xDF ", Green, BlackF);
				resetColor();
				// Soma mais um a m para que ele não entre no if quando voltar para o início e só ajeitar o alinhamento uma vez
				++m;
			}
		}
		cout << endl;
	}
	// Linha do final
	generateLine('-', Green, BlackF, 85);
	
	// Laço que repete pela quantidade de empresas
	for (int a = 0; a < cp; a++)
	{
		// deleta os vetores dinâmicos de transação
		delete[] vet[a].trans;
	}

	// deleta o vetor dinâmico de empresas
	delete[] vet;
}