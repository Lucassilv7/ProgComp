// Inclui o arquivo data
#include "date.h"

// Registro contendo a informa��es necessarias para fazer uma transa��o (data, quantidade e pre�o)
struct Transaction
{
	Date date;
	int amount;
	float price;
};

// Registro de uma empresa, as informa��es contidas s�o:
struct Company
{
	// nome da empresa
	char name[40];
	// c�digo de identifica��o
	char code[6];
	// quantidade de transa��es
	int amountTran;
	// transa��o
	Transaction* trans;
};

// Fun��o que mostra a carteira de investimentos 
float showWallet(Company[], int);