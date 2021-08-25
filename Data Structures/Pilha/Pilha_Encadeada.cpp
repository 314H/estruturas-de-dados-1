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

typedef struct tipo_pilha{

	tipo_celula *prim;

	tipo_celula *ultima;

	int topo;
};

void fpvazia(tipo_pilha *pilha){
    // aloca��o da c�lula cabe�a:	
	pilha->prim = (tipo_celula *)malloc(sizeof(tipo_celula));
	pilha->ultima = pilha->prim;
	pilha->prim->prox = NULL;	
	pilha->topo = 0;
}

int vazia(tipo_pilha *pilha){
	return(pilha->topo == 0);
	// return(pilha->prim == pilha->ultima); // tamb�m est� certo
}

int menu(){
	int op; 
	char c;
	
	while(1){ // La�o infinito at� que o usu�rio digite de 0 a 9
	
		printf("\n\n UTILIZA��O DE PILHA ENCADEADA");
	
		printf("\n\n ********* MENU *********");
    	
    	printf("\n [1] - EMPILHAR");
    	
    	printf("\n [2] - MOSTRAR TOPO");
    	
    	printf("\n [3] - DESEMPILHAR");
    	
    	printf("\n [4] - ESVAZIAR A PILHA");    	
    	
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

void empilhar(tipo_pilha *pilha){
	
	pilha->ultima->prox = (tipo_celula *)malloc(sizeof(tipo_celula));
		
	pilha->ultima = pilha->ultima->prox;
	
	pilha->ultima -> item= inserirItem();
	
	pilha->ultima -> prox = NULL;			
	
	pilha -> topo++;
	
	printf("\n\n ITEM EMPILHADO COM SUCESSO!!!");
	
	getch();
}

void mostrarTopo(tipo_pilha *pilha){
	
	if(vazia(pilha)){
		printf("\n\n Imposs�vel mostrar. Motivo: A pilha EST� VAZIA !!!");
		getch();
		return;
	}
	
	tipo_celula *aux;
	

	
	printf("\n\n ====== MOSTRANDO O TOPO DA PILHA  ======");
	
	printf("\n\t Total de itens: %d ", pilha->topo);
	
	aux = pilha->ultima;
	
//	while( aux != NULL){
		printf("\n\n === ITEM TOPO ===");
		printf("\n C�digo: %d", aux->item.cod);
		printf("\n Nome: %s", aux->item.nome);
		printf("\n Quantidade: %d", aux->item.quant);
		
		aux = aux->prox;
//	}
	getch();
}

void mostrarItem( tipo_item item ){
	
	printf("\n\n ===== ITEM DESEMPILHADO ===" );
	    
	printf("\n C�digo: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}

void desempilhar(tipo_pilha *pilha){
	
	if(vazia(pilha)){
		printf("\n\n pilha est� vazia !!!");
		getch();
		return;
	}

	tipo_item removido = pilha -> ultima -> item; // Copiando a �ltima c�lula para o item removido
	
	tipo_celula *aux;
	
	aux = pilha->prim;

	for(int i = 1; i < pilha -> topo; i++)
		aux = aux->prox ; // Percorrendo at� a pen�tima c�lula 	

    free(pilha -> ultima); // Desalocando a �ltima c�lula 
    
    pilha -> ultima = aux; // Atualizando o ponteiro �ltima
    
    pilha -> ultima -> prox = NULL;
	
	mostrarItem( removido );		

	pilha->topo--;
	
    printf("\n\n Item desempilhado com sucesso !!!");
	
	getch();
}

void esvaziar(tipo_pilha *pilha){
	
	if( pilha -> topo == 0 ){		
		printf("\n\n Pilha j� est� vazia !!!");	
		getch();
		return;
	}
	
	tipo_celula *aux;
	
	for(int i = 1; i <= pilha -> topo; i++){
		
		aux = pilha->prim;
		
		pilha->prim = pilha->prim->prox ; // Percorrendo at� a pen�tima c�lula 
		
		free(aux); // liberando as c�lulas a partir da primeira
	}
	/* Ao terminar o la�o acima, os ponteiros primeira e �ltima estar�o apontando para a �ltima c�lula, por�m seu conte�do 
	ser� considerado como lixo, pois esta c�lula ser� agora a c�lula cabe�a   
	*/
		
	pilha -> topo = 0;
	
	printf("\n\n Pilha esvaziada com sucesso !!!");
	
	getch();
}


int main( ) { 
    setlocale(LC_ALL, "");
    
    int op;
    
    tipo_pilha pilha;
    
    fpvazia(&pilha);
    
    do{
    	system("cls");
    	
    	op = menu();
    	
    	switch(op){
    		
    		case 0: return(0);
    		        break;
    		        
			case 1: empilhar(&pilha);
    		        break;
    		        
    		case 2: mostrarTopo(&pilha);
    		        break;
    		        
    		case 3: desempilhar(&pilha);
    		        break;
    		        
    		case 4: esvaziar(&pilha);    		        
    		        break;		
    		
			default: 
			    printf("\n\n OP��O INV�LIDA !!!");
			    getch();                                             		} 
		   	
    	
	}while(1);	

	return(0);
}
