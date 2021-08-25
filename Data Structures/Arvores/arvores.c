#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod, quant;
    char nome[30];
}tipo_item;

typedef struct {
    tipo_item item;
    tipo_no *esq;
    tipo_no *dir;
}tipo_no;

/* Operações que podem ser realizados */
//inserir
// mostrar 
// pesquisar 
// excluir
// mostrar item


int main(){

    int op, cod, achou;
    tipo_no *raiz = NULL;
    tipo_item aux;

    do
    {
        system("clear");
        op = menu();
        switch (op){
            case 0: return 0;
            case 1: // funcao para inserir
            case 2: // funcao para mostrar conteudo
            case 3: // função para pesquisar
            
        }
    } while (1);
    


    return 0;
}