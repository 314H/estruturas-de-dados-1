#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para system("cls")
#include <conio.h>// para getch() e getche
#include <string.h>// para strcmp()
#include <ctype.h>// para isdigit() 

typedef struct tipo_item {
   int cod;
   char nome[30];
   int quant;
};

typedef struct tipo_celula {

	tipo_item item;

	tipo_celula *prox;
};

typedef struct tipo_fila{

	tipo_celula *frente;

	tipo_celula *tras;

	int total;
};

void flvazia(tipo_fila *fila){
	
	fila->frente = (tipo_celula *)malloc(sizeof(tipo_celula));
	fila->tras = fila->frente;
	fila->frente->prox = NULL;	
	fila->total = 0;
}

int vazia(tipo_fila *fila){
	return(fila->total == 0);
	// return(fila->frente == fila->tras); // tamb�m est� certo
}

int menu(){
	int op; 
	char c;
	
	while(1){ // La�o infinito at� que o usu�rio digite de 0 a 9
		
		printf("\n\n UTILIZA��O DE FILA ENCADEADA");
	
		printf("\n\n ********* MENU *********");
    	
    	printf("\n [1] - ENFILEIRAR");
    	
    	printf("\n [2] - MOSTRAR FRENTE");
    	
    	printf("\n [3] - DESENFILEIRAR");
    	
   		printf("\n [4] - ESVAZIAR A FILA");
    
    	printf("\n [0] - SAIR"); 
    
    	fflush(stdin);	// Limpando o buffer de entrada
    	
    	printf("\n\n Digite sua op��o: ");
   
    	c = getche();

		if(isdigit(c))	{// � d�gito
			op = (int)c - 48; // Transformando o caracter em inteiro
/* Os d�gitos v�o de 48 a 57 na tabela ASCII. Se subtrair 48 do valor da tabela 
teremos o valor n�merico do d�gito. Exemplo: O d�gito 5 equivale a 53 na 
tabela ASCII. Logo, 53 - 48 = 5.  */
		    break;  // quebra o la�o se for d�gito de 0 a 9
		}
		
		printf("\n\n %c � UMA OP��O INV�LIDA !!! ", c); 
		getch();  
		system("cls");
	}
	
	return(op);
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

void enfileirar(tipo_fila *fila){
	
	fila->tras->prox = (tipo_celula *)malloc(sizeof(tipo_celula));
		
	fila->tras = fila->tras->prox;
	
	fila->tras -> item= inserirItem();
	
	fila->tras -> prox = NULL;			
	
	fila -> total++;
	
	printf("\n\n ITEM INSERIDO COM SUCESSO!!!");
	
	getch();
}

void mostrarFrente(tipo_fila *fila){
	if(vazia(fila)){
		printf("\n\n Imposs�vel mostrar a frente da fila. Motivo: A FILA EST� VAZIA !!!");
		getch();
		return;
	}
	
	tipo_celula *aux;
	
	aux = fila -> frente -> prox;
	
	printf("\n\n === Total de itens na fila: %d ===", fila->total);
		
	printf("\n\n === ITEM DA FRENTE ===");
		
	printf("\n Cod: %d", aux->item.cod);
		
	printf("\n Nome: %s", aux->item.nome);
		
	printf("\n Quantidade: %d", aux->item.quant);     
		
	getch();
}


void mostrarItem( tipo_item item ){	

	printf("\n\n ===== ITEM DESENFILEIRADO ===");	
	    
	printf("\n C�digo: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}


void desenfileirar(tipo_fila *fila){
	
	if(vazia(fila)){
		printf("\n\n Imposs�vel desenfileirar. Motivo: A FILA EST� VAZIA !!!");
		getch();
		return;
	}

	tipo_celula *aux = fila->frente->prox;	
	
	tipo_item removido = aux->item;	
	
	mostrarItem( removido );	
	
	fila->frente->prox = aux->prox;
			
	free(aux); // libera a c�lula da frente
	
	fila->total--;
	
    printf("\n\n Item desenfileirado com sucesso !!!");
	
	getch();
}

void esvaziar(tipo_fila *fila){
	
	if( fila->total  == 0 ){		
		printf("\n\n A fila j� est� vazia !!!");	
		getch();
		return;
	}
	
	tipo_celula *aux;
	
	for(int i = 1; i <= fila -> total; i++){
		
		aux = fila->frente;
		
		fila->frente = fila->frente->prox ; // Percorrendo at� a pen�tima c�lula 
		
		free(aux); // liberando as c�lulas a partir da primeira
	}
	/* Ao terminar o la�o acima, os ponteiros primeira e �ltima estar�o apontando para a �ltima c�lula, por�m seu conte�do 
	ser� considerado como lixo, pois esta c�lula ser� agora a nova c�lula cabe�a   
	*/
		
	fila -> total = 0;
	
	printf("\n\n Fila esvaziada com sucesso !!!");

	getch();
}

int main( ) { 
    setlocale(LC_ALL, "");
    
    int op;
    
    tipo_fila fila;
    
    flvazia(&fila);
    
    do{
    	system("cls");
    	
    	op = menu();
    	
    	switch(op){
    		
    		case 0: return(0);
    		        break;
    		        
			case 1: enfileirar(&fila);
    		        break;
    		        
    		case 2: mostrarFrente(&fila);
    		        break;
    		        
    		case 3: desenfileirar(&fila);
    		        break;
    		        
    		case 4: esvaziar(&fila);    		        
    		        break;	
			
			default: 
			    printf("\n\n OP��O INV�LIDA !!!");
			    getch();   
    	}
	}while(1);	

	return(0);
}
