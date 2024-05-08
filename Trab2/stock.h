// Inclui o arquivo data
#include "date.h"

// Registro contendo a informações necessarias para fazer uma transação (data, quantidade e preço)
struct Transaction
{
	Date date;
	int amount;
	float price;
};

// Registro de uma empresa, as informações contidas são:
struct Company
{
	// nome da empresa
	char name[40];
	// código de identificação
	char code[6];
	// quantidade de transações
	int amountTran;
	// transação
	Transaction* trans;
};

// Função que mostra a carteira de investimentos 
float showWallet(Company[], int);