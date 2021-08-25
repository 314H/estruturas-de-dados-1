#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para system("cls")
#include <conio.h>// para getch()
#include <string.h>// para strcmp()
#include <ctype.h>// para isdigit() 

#define TAM 5 // constante tamanho vetor

typedef struct tipo_item{ 
	int cod; // ser� �nico
	char nome[30];
	int quant;
};

typedef struct tipo_fila{
	int frente;
	int tras;
	int total;
	tipo_item itens[TAM];	
};

int menu(){
	int op; 
	char c;
	
	while(1){ // La�o infinito at� que o usu�rio digite de 0 a 9
		printf("\n\n UTILIZA��O DE FILA COM VETOR");
	
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

void ffvazia(tipo_fila *fila){
	fila -> total = fila -> frente = fila -> tras = 0;
}

int vazia(tipo_fila *fila){
	return(fila -> total == 0);
}

int cheia(tipo_fila *fila){
	return(fila -> total == TAM);
}

/*
// A fun��o mostrarFila serve somente para testar a fila
mostrarFila(tipo_fila *fila){	

	printf("\n\n ===== MOSTRANDO A FILA: %d Itens ===", fila -> total);
	
	for(int i = fila->frente, j = 0; j < fila -> total ; i++, j++){
		
		if(i == TAM) i = 0; // reinicia i para a fila circular
				
		printf("\n\n ===== %d� ITEM ===", j+1);
		
		printf("\n C�digo: %d", fila->itens[i].cod);
	
		printf("\n Nome: %s", fila->itens[i].nome);
	
		printf("\n Quantidade: %d", fila->itens[i].quant);
		
	}
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
*/
void enfileirar(tipo_fila *fila){
	
	if(cheia(fila)){
		printf("\n\n Imposs�vel enfileirar! Motivo: A FILA EST� CHEIA!!!");
		getch();
		return;
	}	
		
	fila -> itens[fila->tras] = inserirItem();
	
	fila -> tras++; 
	
	// Se tras chegar a TAM e se frente n�o for 0
	if(fila -> tras == TAM && fila -> frente != 0)
	   fila -> tras = 0; // reinicia tras se o �ndice 0 estiver livre
	
	fila -> total++;
	
	printf("\n\n ITEM ENFILEIRADO COM SUCESSO!!!");
	
// ****** Mostrando a fila para testar se est� OK *********	
//	mostrarFila(fila);
	
	getch();
}

void mostrarFrente(tipo_fila *fila){
	if(vazia(fila)){
		printf("\n\n Imposs�vel mostrar a fila. Motivo: A FILA EST� VAZIA !!!");
		getch();
		return;
	}
	
	printf("\n\n === Total de itens na fila: %d ===", fila->total);
		
	printf("\n\n === ITEM DA FRENTE ===");
		
	printf("\n Cod: %d", fila->itens[fila->frente].cod);
		
	printf("\n Nome: %s", fila->itens[fila->frente].nome);
		
	printf("\n Quantidade: %d", fila->itens[fila->frente].quant);
		
	getch();
}

void mostrarItem(tipo_item item){
	
	printf("\n\n ===== ITEM DESENFILEIRADO ===");
	
	printf("\n C�digo: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}

void desenfileirar(tipo_fila *fila){
	
	if( vazia(fila) ){
		printf("\n\n Imposs�vel desenfileirar. Motivo: A FILA EST� VAZIA !!!");
		getch();
		return;
	}
	
	tipo_item removido = fila->itens[fila->frente];
	
	mostrarItem(removido);
	
	fila->frente++;	
	
	if(fila->frente == TAM)
	   fila->frente = 0;
	
	if(fila->tras == TAM)
	   fila->tras = 0;
	   
	fila -> total--;
    printf("\n\n Item desenfileirado com sucesso !!!");
	
// ****** Mostrando a fila para testar se est� OK *********	
//	mostrarFila(fila);

	getch();
}

void confirmar(tipo_fila *fila, char c){
	char op;
		
	if( c == 'E'){	
		printf("\n\n ==== ESVAZIAR A FILA ====");
		printf("\n\n Tem certeza que deseja esvaziar a fila? [s/n]: ");
	}
	else{	
		printf("\n\n ==== SAIR DO PROGRAMA ====");
		printf("\n\n Tem certeza que deseja sair do programa? [s/n]: ");
	}
		
	fflush(stdin);
	op = getchar();
	
	if((op == 's' || op == 'S') && (c == 'E')){		
		ffvazia(fila);     				
		printf("\n\n FILA ESVAZIADA COM SUCESSO!!!");
		getch();
	}		
	else 
	   if(op == 's' || op == 'S'){
	   	printf("\n\n SAINDO DO PROGRAMA!!!");
		getch();
		exit(0);
	   }    
}

int main( ) { 
    setlocale(LC_ALL, "");    
    int op;
    
    tipo_fila fila;
    
    ffvazia(&fila);
    
    do{
    	system("cls");
    	
    	op = menu();
    	
    	switch(op){
    		
    		case 0: confirmar(&fila, 'S');// confirma a sa�da					
    		        break;
    		        
			case 1: enfileirar(&fila);
    		        break;
    		        
    		case 2: mostrarFrente(&fila);
    		        break;
    		        
    		case 3: desenfileirar(&fila);
    		        break;
    		        
    		case 4: if(vazia(&fila)){
    					printf("\n\n A FILA J� EST� VAZIA !!!");
    					getch();
						break;
					}				
						
					confirmar(&fila, 'E'); // confirma o esvaziamento					   		        
    		        break;		
			
			default: 
			    printf("\n\n OP��O INV�LIDA !!!");
			    getch();
		}    	
    	
	}while(1);	
	
	return(0);
}

