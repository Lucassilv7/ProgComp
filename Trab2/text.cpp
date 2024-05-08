#include <iostream>
using namespace std;

// Recebe 4 parâmetros, o caracterer a ser exibido, as cores de fundo e de texto e o quantidade de caracteres a ser mostrado
void generateLine(char ch, int colorText, int colorBackGround, int tam)
{
	// define as cores que serão mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// exibe os caracteres pelo tamanho recebido
	for (int i = 0; i < tam; i++)
	{
		cout << ch;
	}
}

// Recebe um texto e as cores em que ele será mostrado, a de fundo e a do texto
void showText(const char ch[], int colorText, int colorBackGround)
{
	// define as cores que serão mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	cout << ch;
}

// Recebe um texto, as cores em que ele será mostrado, a de fundo e a do texto, e quantidade de caracteres que terá que andar
void alignmentText(const char ch[], int colorText, int colorBackGround, int amount)
{
	// define as cores que serão mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// anda a quantidade definida
	cout.width(amount);
	cout << ch;
}

// Recebe um inteiro, as cores em que ele será mostrado, a de fundo e a do texto, e quantidade de caracteres que terá que andar
void alignmentInt(int in, int colorText, int colorBackGround, int amount)
{
	// define as cores que serão mostradas
	cout << "\033[;" << colorText << ";" << colorBackGround << "m";
	// anda a quantidade definida
	cout.width(amount);
	cout << in;
}

// Recebe um inteiro, as cores em que ele será mostrado, a de fundo e a do texto, e quantidade de caracteres que terá que andar
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
		convert -> é do tipo inteiro para ser comparado
		retur -> é a variável que será retornada
	*/
	int convert;
	char retur;

	// laço que será executado até encontrar o caractere \n
	for (int i = 0; ch[i];  i++)
	{
		// transforma cada caracterer em um inteiro da tabela ASCII
		convert = ch[i];
		// Condição para transformar apenas o alfabeto, baseado na tabela ASCII
		if (convert >= 97)
		{
			// Subtrai 32 que é a quantidade necessária para achar o alfabeto maiscúlo na tabela
			convert = convert - 32;
			// transfor de volta em um caractere
			retur = convert;
			cout << retur;
		}
		// exucuta se o caracterer já for maiscúlo
		else
		{
			cout << ch[i];
		}
	}
}

