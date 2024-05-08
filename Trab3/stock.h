#pragma once

// Registro para relacionado aos produtos
struct Product
{
	char name[24];
	float price;
	unsigned int amount;
};

// Prototipo das funções relacionadas ao estoque
Product* plusVet(Product*, unsigned short&);
Product* minusVet(Product*, unsigned short&, int);
int validationProduct(Product*, const char*, int);
