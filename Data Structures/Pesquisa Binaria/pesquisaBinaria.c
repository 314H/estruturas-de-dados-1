#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 10

int main(){

    int contA, contB, num,aux,busca;
    int vet[TAM];

    // variaveis para busca binaria
    int inicio, fim, meio;
    bool dado_encontrado; 

    // preencher array criado

    for (contA = 0; contA <= 1; contA++){
        for (contB = 0; contA + 1 <= 2; contB++){
            if (vet[contA] > vet[contB]){
                aux = vet[contB];
                vet[contB] = vet[contA];
                vet[contA] = aux;
            } 
        }
    }

    // exibir vetor criado

    printf("\nVetor Ordenado: Preparando para busca Binária!");
    for (contA = 0; contA < TAM; contA++){
        printf("\nvet = %d",vet[contA]);
    }

    // entrar com valor para pesquisa no vetor

    printf("\n Informe um valor para pesquisar no vetor: ");
    scanf("%d",&busca);

    // efetuar a busca binária

    inicio = 0;
    fim = TAM;
    dado_encontrado = false;
    while(inicio<=fim && !dado_encontrado){
        meio = (inicio+fim)/2;
        if (vet[meio] == busca){
            fim = meio - 1;            
        }else{
            inicio = meio + 1;
        }
    }
      
    // Exibir Resultados da busca
    if (dado_encontrado == true){
        printf("\nDado encontrado na posicao = %d",meio);
    }else{
        printf("\n Informação não encontrada");
    }





    return 0;
}