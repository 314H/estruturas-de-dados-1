#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para system("cls")
#include <conio.h>// para getch()
#include <string.h>// para strcmp()
#include <ctype.h>// para isdigit() 

#define TAM 10 // constante tamanho vetor

typedef struct tipo_item{
	int cod; // ser� �nico
	char nome[30];
	int quant;
};

typedef struct tipo_pilha{
	tipo_item itens[TAM];
	int topo;
};

int menu(){
	int op; 
	char c;
	
	while(1){ // La�o infinito at� que o usu�rio digite de 0 a 9
		printf("\n\n UTILIZA��O DE PILHA COM VETOR");
	
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

void fpvazia(tipo_pilha *pilha){
	pilha -> topo = 0;
}

int vazia(tipo_pilha *pilha){
	return(pilha -> topo == 0);
}

int cheia(tipo_pilha *pilha){
	return(pilha -> topo == TAM);
}


tipo_item inserirItem(){
	
	static int cod = 1; // cod n�o vai repetir
	
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
	
	if(cheia(pilha)){
		printf("\n\n Imposs�vel empilhar! Motivo: A PILHA EST� CHEIA!!!");
		getch();
		return;
	}	
		
	pilha -> itens[pilha->topo] = inserirItem();
	
	pilha -> topo++;
	
	printf("\n\n ITEM EMPILHADO COM SUCESSO!!!");
	
	getch();
}


void mostrarTopo(tipo_pilha *pilha){
	if(vazia(pilha)){
		printf("\n\n Imposs�vel mortrar a pilha. Motivo: A PILHA EST� VAZIA !!!");
		getch();
		return;
	}
	
	printf("\n\n === Total de itens na pilha: %d ===", pilha->topo);
		
	printf("\n\n === ITEM DO TOPO ===");
		
	printf("\n Cod: %d", pilha->itens[pilha->topo -1].cod);
		
	printf("\n Nome: %s", pilha->itens[pilha->topo - 1].nome);
		
	printf("\n Quantidade: %d", pilha->itens[pilha->topo - 1].quant);
		
	getch();
}

void mostrarItem(tipo_item item){
	
	printf("\n\n ===== ITEM DESEMPILHADO ===");
	
	printf("\n C�digo: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}

void desempilhar(tipo_pilha *pilha){
	
	if( vazia(pilha) ){
		printf("\n\n Imposs�vel desempilhar. Motivo: A PILHA EST� VAZIA !!!");
		getch();
		return;
	}
	
	tipo_item removido = pilha->itens[pilha->topo - 1];
	
	mostrarItem(removido);
	
	pilha->topo--;	
		
    printf("\n\n Item desempilhado com sucesso !!!");
	
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
    		        
    		case 4: fpvazia(&pilha); 
			        printf("\n\n PILHA ESVAZIADA COM SUCESSO!!!");
					getch();   		        
    		        break;		
			
			default: 
			    printf("\n\n OP��O INV�LIDA !!!");
			    getch();
		}    	
    	
	}while(1);	

	return(0);
}

