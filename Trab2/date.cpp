// Inclui o arquivo data 

#include <iostream>
#include "date.h"
using namespace std;

// Função para exibir variaveis do tipo data
ostream& operator<<(ostream& os, Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;

	return os;
}

// Função para ler variaveis do tipo data
istream& operator>>(istream& is, Date& date)
{
	is >> date.day;
	is.ignore(1);
	is >> date.month;
	is.ignore(1);
	is >> date.year;

	return is;
}
