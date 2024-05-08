#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "text.h"
#include "ordered.h"
#include "stock.h"
using namespace std;

int main(int argc, char ** argv) {
	// Variaveis
	// Vetores de produtos, pedidos e totais
	Product* vet;
	Ordered* general;
	double* total;
	// tamanho do vetor
	unsigned short tam = 0;
	// leitura e escrita dos arquivos
	ifstream fin;
	ofstream fout;

	// Condição para saber se entra na parte de estoque ou pedido
	if (argc == 1) {
		// c = contador para gravar no arquivo txt; exit = variavel para saida
		int c = 1; char exit;

		// leitura do arquivo binario
		fin.open("estoque.bin", ios_base::in | ios_base::binary);
		if (!fin.is_open())
		{
			// caso não exista arquivo para ler
			vet = nullptr;
			total = nullptr;
			cout << "Não há estoque!\nVolte em outro momento, obrigado!!";
			return 0;
		}
		else {
			// caso a leitura funcione
			// pega o valor do tamanhdo do vetor salvo no arquivo
			fin.read((char*)&tam, sizeof(unsigned short));
			// cria três vetores dinâmicos
			vet = new Product[tam];
			total = new double[tam];
			general = new Ordered[tam];
			// lê os valores para a variável vet
			fin.read((char*)vet, sizeof(Product) * tam);
			fin.close();
		}
		// laço para passar os valores para o vetor general
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				general[i].name[j] = vet[i].name[j];
			}
			general[i].amount = 0;
			general[i].price = vet[i].price;
		}
		// condição de entrada
		do
		{
			// Menu
			cout << "   RapThor";
			menu(vet, tam);
			// variaveis para leitura
			char ch, dh; cin >> ch;
			// variaveis para calcular o preço final a pagar
			double pay = 0, deliveryFee = 4.00, discount;

			system("cls");

			while (!(ch == 's' || ch == 'S'))
			{
				// variaveis para mostrar a letra para escolha
				char Cod = 65, cod = 97;
				// Codiçoes para a opçao escolhida
				for (int i = 0; i < tam; i++)
				{
					if (ch == cod || ch == Cod)
					{
						total[i] = showOrdered(general, i);
						system("cls");
					}
					cod++;
					Cod++;
				}
				cout << fixed;
				cout.precision(2);
				// menu mostrando as opçoes escolhidas
				cout << "   RapThor";
				cout << "\n ===========\n";
				for (int i = 0; i < tam; i++)
				{
					if (general[i].amount > 0)
					{
						if (i > 0)
						{
							cout << endl;
						}
						cout << " " << general[i].amount << " x " <<
							general[i].name << " de R$" <<
							general[i].price << " = R$" <<
							total[i];
					}
				}
				menu(vet, tam);
				cin >> ch;
				system("cls");
			}
			// Condição para caso não seja feito nenhum pedido e escolhido a opção sair o programa encerrar
			int getout = 0;
			for (int i = 0; i < tam; i++)
			{
				if (general[i].amount == 0)
				{
					getout++;
				}
			}
			if (getout == tam)
			{
				return 0;
			} // fim da condição
			system("cls");
			// calculando o total a pagar
			for (int i = 0; i < tam; i++)
			{
				if (total[i] > 0)
				{
					pay += total[i];
				}
			}
			// mostrando o total a pagar
			cout << "   RapThor";
			cout << "\n ===========\n";
			for (int i = 0; i < tam; i++)
			{
				if (general[i].amount > 0)
				{
					cout << " " << general[i].amount << " x " <<
						general[i].name << " de R$" <<
						general[i].price << " = R$" <<
						total[i] << endl;
				}
			}
			// mostrando o total com a taxa de entrega
			cout << " Taxa de entrega = R$" << deliveryFee;
			pay = menuPayment(pay, deliveryFee);
			cin >> dh;
			system("cls");
			
			// Calculando discontos 
			cout << "   RapThor";
			cout << "\n ===========\n";
			for (int i = 0; i < tam; i++)
			{
				if (general[i].amount > 0)
				{
					cout << " " << general[i].amount << " x " <<
						general[i].name << " de R$" <<
						general[i].price << " = R$" <<
						total[i] << endl;
				}
			}
			if (dh == 'p' || dh == 'P')
			{
				discount = pay * 0.1;
				cout << " Desconto de 10% = R$" << discount;
			}
			else if (dh == 'c' || dh == 'C')
			{
				discount = pay * 0.05;
				cout << " Desconto de 5% = R$" << discount;
			}
			cout << "\n ===========\n";
			cout << " Total = R$" << pay - discount << endl;
			// confirmando pedido
			cout << "\n Confirmar Pedido (S/N): [ ]\b\b";
			cin >> ch;

			// variavel para o nome do arquvio texto
			char name[13] = "pedido_";
			name[7] = '0' + c;

			// escrita do arquivo texto
			if (ch == 's' || ch == 'S')
			{
				strcat(name, ".txt");
				fout.open(name);
				fout.setf(ios_base::fixed, ios_base::floatfield);
				fout.precision(2);
				fout << "Pedido #" << c;
				fout << "\n--------------------------------------------------\n";
				for (int i = 0; i < tam; i++)
				{
					if (general[i].amount > 0)
					{
						fout << " " << general[i].amount << " x " <<
							general[i].name << " de R$" <<
							general[i].price << " = R$" <<
							total[i] << endl;
					}
				}
				fout << "Taxa de entrega = R$" << deliveryFee;
				if (dh == 'p' || dh == 'P')
				{
					fout << "\nDesconto de 10% = R$" << discount;
				}
				else if (dh == 'c' || dh == 'C')
				{
					fout << "\nDesconto de 5% = R$" << discount;
				}
				fout << "\n--------------------------------------------------\n";
				fout << "Total = R$" << pay - discount;

				fout.close();
			}
			c++;

			// Condição para saber e será feito um novo pedido
			system("cls");
			cout << "Deseja sair do aplicativo (S/N) [ ]\b\b";
			cin >> exit;
			system("cls");

			for (int i = 0; i < tam; i++)
			{
				if (general[i].amount > 0)
				{
					general[i].amount = 0;
				}
			}
			fout.open("estoque.bin", ios_base::out | ios_base::binary);
			fout.write((char*)&tam, sizeof(unsigned short));
			fout.write((char*)vet, sizeof(Product)* tam);
			fout.close();
		} while (!(exit == 's' || exit == 'S'));
		delete[] total;
		delete[] general;
		delete[] vet;
	}
	else if (argc == 2) {
		char name[24]; int TorF, amount; float price;

		fin.open("estoque.bin", ios_base::in | ios_base::binary);
		if (!fin.is_open())
		{
			vet = nullptr;
		}
		else {
			fin.read((char*) &tam, sizeof(unsigned short));
			vet = new Product[tam];
			fin.read((char*)vet, sizeof(Product) * tam);
			fin.close();
		}
		cout << " Painel de Controle";
		menuControll();
		char chC; cin >> chC;
		while (!(chC == 's' || chC == 'S'))
		{
			switch (chC)
			{
			case 'A':
			case 'a':
				system("cls");
				cout << "Adcionar\n---------\n";

				if (tam == 0)
				{
					vet = plusVet(vet, tam);
					cout << "Produto: ";
					cin >> vet[tam - 1].name;
					cout << "Preço: ";
					cin >> vet[tam - 1].price;
					cout << "Quantidade: ";
					cin >> vet[tam - 1].amount;
				}
				else
				{
					cout << "Produto: ";
					cin >> name;
					cin.get();
					TorF = validationProduct(vet, name, tam);
					if (TorF >= 0)
					{
						cout << "Preço: ";
						cin >> price;
						cout << "Quantidade: ";
						cin >> amount;

						vet[TorF].price = price;
						vet[TorF].amount = amount;
					}
					else {
						vet = plusVet(vet, tam);
						for (int i = 0; name[i] != 0; i++)
						{
							vet[tam - 1].name[i] = name[i];
						}
						cout << "Preço: ";
						cin >> vet[tam - 1].price;
						cout << "Quantidade: ";
						cin >> vet[tam - 1].amount;
					}
				} 
				system("cls");
				break;
			case 'E':
			case 'e':
				system("cls");
				cout << "Excluir\n--------\n";
				for (int i = 0; i < tam; i++)
				{
					cout << i + 1 << ") " << vet[i].name << endl;
				}
				cout << "\nProduto: [ ]\b\b";
				int choice; cin >> choice;
				cout << "Deseja excluir " << '"' << vet[choice - 1].name << '"' << " (S/N)? ";
				char del; cin >> del;
				if (del == 's' || del == 'S')
				{
					vet = minusVet(vet, tam, choice);
				}
				system("cls");
				break;
			case 'L':
			case 'l':
				system("cls");
				cout << "Listagem\n--------\n";
				cout << fixed;
				cout.precision(2);
				for (int i = 0; i < tam; i++)
				{
					cout << vet[i].name << "\t- R$" << vet[i].price <<
						" - " << vet[i].amount << " und.\n";
				}
				cout << endl;
				system("pause");
				system("cls");
				break;
			default:
				cout << "\nOpção inválida\n";
				break;
			}
			cout << " Painel de Controle";
			menuControll();
			cin >> chC;
		}
		fout.open("estoque.bin", ios_base::out | ios_base::binary);
		fout.write((char*)&tam, sizeof(unsigned short));
		fout.write((char*) vet, sizeof(Product) * tam);
		fout.close();

		delete[] vet;
	}
}