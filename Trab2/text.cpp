#include <iostream>
using namespace std;

// Recebe 4 par�metros, o caracterer a ser exibido, as cores de fundo e de texto e o quantidade de caracteres a ser mostrado
void generateLine(char ch, int colorText, int colorBackGround, int tam)
{
	// define as cores que ser�o mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// exibe os caracteres pelo tamanho recebido
	for (int i = 0; i < tam; i++)
	{
		cout << ch;
	}
}

// Recebe um texto e as cores em que ele ser� mostrado, a de fundo e a do texto
void showText(const char ch[], int colorText, int colorBackGround)
{
	// define as cores que ser�o mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	cout << ch;
}

// Recebe um texto, as cores em que ele ser� mostrado, a de fundo e a do texto, e quantidade de caracteres que ter� que andar
void alignmentText(const char ch[], int colorText, int colorBackGround, int amount)
{
	// define as cores que ser�o mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// anda a quantidade definida
	cout.width(amount);
	cout << ch;
}

// Recebe um inteiro, as cores em que ele ser� mostrado, a de fundo e a do texto, e quantidade de caracteres que ter� que andar
void alignmentInt(int in, int colorText, int colorBackGround, int amount)
{
	// define as cores que ser�o mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// anda a quantidade definida
	cout.width(amount);
	cout << in;
}

// Recebe um inteiro, as cores em que ele ser� mostrado, a de fundo e a do texto, e quantidade de caracteres que ter� que andar
void alignmentFloat(float flt, int colorText, int colorBackGround, int amount)
{
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// anda a quantidade definida
	cout.width(amount);
	cout << flt;
}

// Recebe o texto a ser convertido
void convertUpperCase(char ch[])
{
	/*
	Cria as variaveis
		convert -> � do tipo inteiro para ser comparado
		retur -> � a vari�vel que ser� retornada
	*/
	int convert;
	char retur;

	// la�o que ser� executado at� encontrar o caractere \n
	for (int i = 0; ch[i];  i++)
	{
		// transforma cada caracterer em um inteiro da tabela ASCII
		convert = ch[i];
		// Condi��o para transformar apenas o alfabeto, baseado na tabela ASCII
		if (convert >= 97)
		{
			// Subtrai 32 que � a quantidade necess�ria para achar o alfabeto maisc�lo na tabela
			convert = convert - 32;
			// transfor de volta em um caractere
			retur = convert;
			cout << retur;
		}
		// exucuta se o caracterer j� for maisc�lo
		else
		{
			cout << ch[i];
		}
	}
}

