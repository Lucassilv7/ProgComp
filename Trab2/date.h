#include <iostream>
using namespace std;

// Registro que cont�m os valores relacionados a data (dia, m�s e ano)
struct Date
{
	int day;
	int month;
	int year;
};

// Fun��es para que o compilador consiga ler e exibir informa��es do tipo data
ostream& operator<<(ostream&, Date&);
istream& operator>>(istream&, Date&);