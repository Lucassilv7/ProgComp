#include <iostream>
using namespace std;

// Registro que contém os valores relacionados a data (dia, mês e ano)
struct Date
{
	int day;
	int month;
	int year;
};

// Funções para que o compilador consiga ler e exibir informações do tipo data
ostream& operator<<(ostream&, Date&);
istream& operator>>(istream&, Date&);