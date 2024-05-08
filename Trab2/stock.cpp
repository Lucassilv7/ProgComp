// Inclui todos os arquivos necess�rios

#include <iostream>
#include "stock.h"
#include "text.h"
#include "color.h"
using namespace std;

// Fun��o para exibir um resumo da carteira de investimentos, recebe um vetor de empresas e o tamanho do vetor e retorna um ponto flutuante
float showWallet(Company vet[], int size)
{
    /*
    Cria��o e iniciliza��o das variaveis
        result -> � o resultado da soma de todos os investimentos
        amountT -> � a soma das quauntidades de transa��es feitos por empresa 
        averagePrice -> � o pre�o m�dio por empresa
        invested -> valor investido por empresa
    */
    float result = 0, amountT, averagePrice, invested;
    
    // Utiliza das fun��es de alinhamento e cria��o de linhas para fazer o layout da carteira
    // Linha incial
    alignmentText("Resumo da Carteira", Black, GreenF, 40);
    // caraceteres para completar o background no tamanho definido (68)
    generateLine(' ', Green, GreenF, 28);
    resetColor();
    cout << endl;
    // Cria as linhas de baixo 
    generateLine('-', Green, BlackF, 68);
    cout << endl;
    // Cria a estrutura das colunas e indica os devidos valores contidos nela {
    showText(" Empresa ", Black, GreenF);
    generateLine(' ', Black, BlackF, 7);
    showText(" Ticker ", Black, GreenF);
    generateLine(' ', Black, BlackF, 5);
    showText(" Qtd. ", Black, GreenF);
    generateLine(' ', Black, BlackF, 4);
    showText(" Pre�o M�dio ", Black, GreenF);
    generateLine(' ', Black, BlackF, 5);
    showText(" Investido ", Black, GreenF);
    resetColor();
    cout << endl;
    // }

    // La�o que repete se processo baseado no par�metro de tamanho
    for (int i = 0; i < size; i++)
    {
        // inicializa os valores das variaveis e depois de uma empresa reseta para a outra empresa
        amountT = 0, averagePrice = 0, invested = 0;
        // repete baseado no valor da quantidade de transa��es de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // soma o amountT mais a quantidade a cada transa��o por empresa
            amountT += vet[i].trans[j].amount;
        // tamb�m repete baseado no valor da quantidade de transa��es de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // soma o valor investido mais (a quantidade a cada tran��o vezes o pre�o de cada uma)
            invested += (vet[i].trans[j].amount * vet[i].trans[j].price);
        //  tamb�m repete baseado no valor da quantidade de transa��es de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // calcula o pre�o m�dio dividindo o investido pelo quantidade de transa��es 
            averagePrice = invested / amountT;

        // soma o resultado de todos os investimentos
        result += invested;

        // define a precis�o dos valores exibidos
        cout << fixed;
        // exibe os valores calculados na carteira
        alignmentText(vet[i].name, None, None, 0);
        cout << "    \t ";
        convertUpperCase(vet[i].code);
        cout.precision(0);
        alignmentFloat(amountT, None, None, 11);
        cout.precision(2);
        alignmentFloat(averagePrice, None, None, 15);
        alignmentFloat(invested, None, None, 20);
        cout << endl;
    }

    // gera a linha final com a informa��o do total investtido
    generateLine('-', Green, BlackF, 68);
    cout << endl;
    alignmentText("Total Investido: ", Black, GreenF, 0);
    cout << fixed;
    cout.precision(2);
    alignmentFloat(result, Black, GreenF, 51);
    resetColor();

    return result;
}

