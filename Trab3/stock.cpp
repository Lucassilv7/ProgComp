#include "stock.h"

// Função para aumentar o tamanho do vetor, recebe o vetor e a referencia do tamanho e retorna o novo vetor
Product* plusVet(Product* vet, unsigned short &size)
{
    // aumenta o tamanho
    size++;

    Product* vet2 = new Product[size];

    // Passando os dados para o novo vetor
    for (int i = 0; i < size; i++)
    {
        vet2[i] = vet[i];
    }

    delete[] vet;

    return vet2;
}

// Mesma função da anterior só que essa é para diminuir o vetor, executa os mesmos passo (exeto o if de erro)
Product* minusVet(Product* vet, unsigned short &size, int choice)
{
    size--;

    Product* vet2 = new Product[size];

    for (int i = 0; i < size; i++)
    {
        if (i >= choice - 1)
        {
            vet2[i] = vet[i + 1];
        }
        else
        {
            vet2[i] = vet[i];
        }
    }

    delete[] vet;

    return vet2;
}

// Função para verificar se o produto já existe, recebe dois vetores de caracteres e o tamanho
int validationProduct(Product* vet, const char * name, int size)
{
    int cont = 0, cont2, position;

    // procura as opções que tem dentro do vetor de produtos
    for (int i = 0; i < size; i++)
    {   
        cont2 = 0;
        // Compara cada caractere dos vetores
        for (int j = 0; name[j]; j++, ++cont2)
        {
            if (vet[i].name[j] == name[j])
            {
                cont++;
                position = i;
            }
            else if (vet[i].name[j] == name[j] - 32 || vet[i].name[j] == name[j] + 32)
            {
                cont++;
                position = i;
            }
        }
    }

    // Se os dois contadores forem iguais retorna a posição
    if (cont == cont2)
    {
        return position;
    }
    else
    {
        return -1;
    }

}
