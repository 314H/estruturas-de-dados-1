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
	// return(fila->frente == fila->tras); // também está certo
}

int menu(){
	int op; 
	char c;
	
	while(1){ // Laço infinito até que o usuário digite de 0 a 9
		
		printf("\n\n UTILIZAÇÃO DE FILA ENCADEADA");
	
		printf("\n\n ********* MENU *********");
    	
    	printf("\n [1] - ENFILEIRAR");
    	
    	printf("\n [2] - MOSTRAR FRENTE");
    	
    	printf("\n [3] - DESENFILEIRAR");
    	
   		printf("\n [4] - ESVAZIAR A FILA");
    
    	printf("\n [0] - SAIR"); 
    
    	fflush(stdin);	// Limpando o buffer de entrada
    	
    	printf("\n\n Digite sua opção: ");
   
    	c = getche();

		if(isdigit(c))	{// É dígito
			op = (int)c - 48; // Transformando o caracter em inteiro
/* Os dígitos vão de 48 a 57 na tabela ASCII. Se subtrair 48 do valor da tabela 
teremos o valor númerico do dígito. Exemplo: O dígito 5 equivale a 53 na 
tabela ASCII. Logo, 53 - 48 = 5.  */
		    break;  // quebra o laço se for dígito de 0 a 9
		}
		
		printf("\n\n %c É UMA OPÇÃO INVÁLIDA !!! ", c); 
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
		printf("\n\n Impossível mostrar a frente da fila. Motivo: A FILA ESTÁ VAZIA !!!");
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
	    
	printf("\n Código: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}


void desenfileirar(tipo_fila *fila){
	
	if(vazia(fila)){
		printf("\n\n Impossível desenfileirar. Motivo: A FILA ESTÁ VAZIA !!!");
		getch();
		return;
	}

	tipo_celula *aux = fila->frente->prox;	
	
	tipo_item removido = aux->item;	
	
	mostrarItem( removido );	
	
	fila->frente->prox = aux->prox;
			
	free(aux); // libera a célula da frente
	
	fila->total--;
	
    printf("\n\n Item desenfileirado com sucesso !!!");
	
	getch();
}

void esvaziar(tipo_fila *fila){
	
	if( fila->total  == 0 ){		
		printf("\n\n A fila já está vazia !!!");	
		getch();
		return;
	}
	
	tipo_celula *aux;
	
	for(int i = 1; i <= fila -> total; i++){
		
		aux = fila->frente;
		
		fila->frente = fila->frente->prox ; // Percorrendo até a penútima célula 
		
		free(aux); // liberando as células a partir da primeira
	}
	/* Ao terminar o laço acima, os ponteiros primeira e última estarão apontando para a última célula, porém seu conteúdo 
	será considerado como lixo, pois esta célula será agora a nova célula cabeça   
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
			    printf("\n\n OPÇÃO INVÁLIDA !!!");
			    getch();   
    	}
	}while(1);	

	return(0);
}
