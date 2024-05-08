// Inclui todos os arquivos necessários

#include <iostream>
#include "stock.h"
#include "text.h"
#include "color.h"
using namespace std;

// Função para exibir um resumo da carteira de investimentos, recebe um vetor de empresas e o tamanho do vetor e retorna um ponto flutuante
float showWallet(Company vet[], int size)
{
    /*
    Criação e inicilização das variaveis
        result -> é o resultado da soma de todos os investimentos
        amountT -> é a soma das quauntidades de transações feitos por empresa 
        averagePrice -> é o preço médio por empresa
        invested -> valor investido por empresa
    */
    float result = 0, amountT, averagePrice, invested;
    
    // Utiliza das funções de alinhamento e criação de linhas para fazer o layout da carteira
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
    showText(" Preço Médio ", Black, GreenF);
    generateLine(' ', Black, BlackF, 5);
    showText(" Investido ", Black, GreenF);
    resetColor();
    cout << endl;
    // }

    // Laço que repete se processo baseado no parâmetro de tamanho
    for (int i = 0; i < size; i++)
    {
        // inicializa os valores das variaveis e depois de uma empresa reseta para a outra empresa
        amountT = 0, averagePrice = 0, invested = 0;
        // repete baseado no valor da quantidade de transações de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // soma o amountT mais a quantidade a cada transação por empresa
            amountT += vet[i].trans[j].amount;
        // também repete baseado no valor da quantidade de transações de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // soma o valor investido mais (a quantidade a cada tranção vezes o preço de cada uma)
            invested += (vet[i].trans[j].amount * vet[i].trans[j].price);
        //  também repete baseado no valor da quantidade de transações de empresa vinda do vetor
        for (int j = 0; j < vet[i].amountTran; j++)
            // calcula o preço médio dividindo o investido pelo quantidade de transações 
            averagePrice = invested / amountT;

        // soma o resultado de todos os investimentos
        result += invested;

        // define a precisão dos valores exibidos
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

    // gera a linha final com a informação do total investtido
    generateLine('-', Green, BlackF, 68);
    cout << endl;
    alignmentText("Total Investido: ", Black, GreenF, 0);
    cout << fixed;
    cout.precision(2);
    alignmentFloat(result, Black, GreenF, 51);
    resetColor();

    return result;
}

