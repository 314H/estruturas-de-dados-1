#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para system("cls")
#include <conio.h>// para getch()
#include <string.h>// para strcmp()

#define TAM 5 // constante tamanho vetor

typedef struct tipo_item{
	int cod; // será único
	char nome[30];
	int quant;
};

typedef struct tipo_lista{
	tipo_item itens[TAM];
	int ultimo;
};

int menu(){
	int op; 
	
	printf("\n\n ********* MENU *********");
    	
    printf("\n [1] - INSERIR");
    	
    printf("\n [2] - MOSTRAR");
    	
    printf("\n [3] - PESQUISAR");
    	
    printf("\n [4] - REMOVER");
    
    printf("\n [5] - INSERIR EM UMA POSIÇÃO");
    	
    printf("\n [0] - SAIR");
    	
    printf("\n\n Digite sua opção: ");
    scanf("%d", &op);
	
	return(op);
}

void flvazia(tipo_lista *lista){	
	lista -> ultimo = 0;
}

int vazia(tipo_lista *lista){
	return(lista -> ultimo == 0);
}

int cheia(tipo_lista *lista){
	return(lista -> ultimo == TAM);
}

tipo_item inserirItem(){
	
	static int cod = 1;
	
	tipo_item item;
	
	item.cod = cod;
	
	cod++;
	
	fflush(stdin);
	
	printf("\n\n Digite o nome do item: ");
		
	gets(item.nome);
	
	printf("\n\n Digite a quantidade do item: ");
	
	scanf("%d", &item.quant);	
	
	return(item);
}

void inserir(tipo_lista *lista){
	
	if(cheia(lista)){
		printf("\n\n Impossível inserir! Motivo: LISTA CHEIA!!!");
		getch();
		return;
	}	
		
	lista -> itens[lista->ultimo] = inserirItem();
	
	lista -> ultimo++;
	
	printf("\n\n ITEM INSERIDO COM SUCESSO!!!");
	
	getch();
}

void inserirPos(tipo_lista *lista){
	
	if(cheia(lista)){
		printf("\n\n Impossível inserir! Motivo: LISTA CHEIA!!!");
		getch();
		return;
	}	
	
	int pos, i;
	
	printf("\n\n Digite a posição do item para inserir: ");
	scanf("%d", &pos);	
	
	pos--;// pos = índice + 1
	
	if(pos < 0 || pos > lista->ultimo){
		printf("\n\n Lista está vazia ou a posição é inválida !!!");
		getch();
		return;
	}
	
	for(i = lista->ultimo; i > pos; i--)		    
	       lista->itens[i] = lista->itens[i - 1];
	       
	lista->itens[i] = inserirItem();
		
	lista -> ultimo++;
	
	printf("\n\n ITEM INSERIDO COM SUCESSO!!!");
	
	getch();
}


void mostrar(tipo_lista *lista){
	if(vazia(lista)){
		printf("\n\n Impossível mortrar a lista. Motivo: LISTA VAZIA !!!");
		getch();
		return;
	}
	
	printf("\n\n === Total de itens na lista: %d ===", lista->ultimo);
	
	for(int i = 0; i < lista->ultimo; i++){
		
		printf("\n\n === %dº ITEM ===", i + 1);
		
		printf("\n Cod: %d", lista->itens[i].cod);
		
		printf("\n Nome: %s", lista->itens[i].nome);
		
		printf("\n Quantidade: %d", lista->itens[i].quant);
	}
	
	getch();
}

void mostrarItem(tipo_item item, int pos){
	
	printf("\n\n ===== ITEM ENCONTRADO NA POSIÇÃO %d ===", pos);
	
	printf("\n Código: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}

void pesqCod(tipo_lista *lista){
	
	int cod, achou = 0, i;
	
	printf("\n\n Digite o Código para pesquisa: ");
	scanf("%d", &cod);	
	
	for(i = 0; i < lista->ultimo; i ++){
		if(lista->itens[i].cod == cod){		
		    mostrarItem(lista->itens[i], i+1);
		    achou = 1;
		}
	}
	
	if(!achou)
	    printf("\n\n O item de codigo %d não existe na lista !!!", cod);	
}

void pesqNome(tipo_lista *lista){
	
	char nomePesq[30], achou = 0, i;
	
	fflush(stdin);
	printf("\n\n Digite o Nome para pesquisa: ");
	gets(nomePesq);	
	
	for(i = 0; i < lista->ultimo; i ++){
		if( ! strcmp ( lista->itens[i].nome , nomePesq ) ) {		
		    mostrarItem(lista->itens[i], i+1);
		    achou = 1;
		}
	}
	
	if(!achou)
	    printf("\n\n O item de nome %s não existe na lista !!!", nomePesq);	
}

void pesqQuant(tipo_lista *lista){
	
	int quant, achou = 0, i;
	
	printf("\n\n Digite a Quantidade para pesquisa: ");
	scanf("%d", &quant);	
	
	for(i = 0; i < lista->ultimo; i ++){
		if(lista->itens[i].quant == quant){		
		    mostrarItem(lista->itens[i], i+1);
		    achou = 1;
		}
	}
	
	if(!achou)
	    printf("\n\n Não existe item com a quantidade %d na lista !!!", quant);	
}

void pesquisar(tipo_lista *lista){
	if(vazia(lista)){
		printf("\n\n Impossível pesquisar na lista. Motivo: LISTA VAZIA !!!");
		getch();
		return;
	}
	
	int op; 
	
	printf("\n\n ********* MENU DE PESQUISA *********");
    	
    printf("\n [1] - PESQUISAR POR CÓDIGO");
    	
    printf("\n [2] - PESQUISAR POR NOME");
    	
    printf("\n [3] - PESQUISAR POR QUANTIDADE");   
    	
    printf("\n [0] - SAIR DA PESQUISA");
    	
    printf("\n\n Digite sua opção: ");
    scanf("%d", &op);
	
	switch(op){
    		
    		case 0: return;
    		        break;    		        
			case 1: pesqCod(lista);
    		        break;    		        
    		case 2: pesqNome(lista);
    		        break;    		        
    		case 3: pesqQuant(lista);
    		        break;					        
    		default: 
			    printf("\n\n OPÇÃO INVÁLIDA !!!");
			    getch();
		}    	
	getch();
}

void remover(tipo_lista *lista){
	
	int pos, i;
	
	printf("\n\n Digite a posição do item para remover: ");
	scanf("%d", &pos);	
	
	pos--;// pos = índice + 1
	
	if(vazia(lista) || pos < 0 || pos > lista->ultimo -1){
		printf("\n\n Lista está vazia ou a posição é inválida !!!");
		getch();
		return;
	}
	
	tipo_item removido = lista->itens[pos];
	
	lista->ultimo--;
	
	for(i = pos; i < lista->ultimo; i++)
		lista->itens[i] = lista->itens[i+1] ;
		
    printf("\n\n Item excluído com sucesso !!!");
	
	getch();
}


int main( ) { 
    setlocale(LC_ALL, "");
    
    int op;
    
    tipo_lista lista;
    
    flvazia(&lista);
    
    do{
    	system("cls");
    	
    	op = menu();
    	
    	switch(op){
    		
    		case 0: return(0);
    		        break;
    		        
			case 1: inserir(&lista);
    		        break;
    		        
    		case 2: mostrar(&lista);
    		        break;
    		        
    		case 3: pesquisar(&lista);
    		        break;
    		        
    		case 4: remover(&lista);    		        
    		        break;
			
			case 5: inserirPos(&lista);
    		        break;		    
    		
			default: 
			    printf("\n\n OPÇÃO INVÁLIDA !!!");
			    getch();
		}    	
    	
	}while(1);	

	return(0);
}

