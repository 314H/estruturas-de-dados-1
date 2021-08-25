#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para system("cls")
#include <conio.h>// para getch()
#include <string.h> 

//typedef struct tipo_item{ // alguns compiladores exigem o typdef
struct tipo_item {
	int cod;
	char nome[30];
	int quant;
} ; 

//typedef struct tipo_no {// alguns compiladores exigem o typdef
struct tipo_no {	
	tipo_item item;
	tipo_no *esq;
	tipo_no *dir;
} ; 

int menu(){
	int op; 
	
	printf("\n\n ********* MENU *********");
    	
    printf("\n [1] - INSERIR");    	
    printf("\n [2] - MOSTRAR");    	
    printf("\n [3] - PESQUISAR");    	
    printf("\n [4] - EXCLUIR");      	
    printf("\n [0] - SAIR");

    printf("\n\n Digite sua opção: ");
    scanf("%d", &op);
	
	return(op);
}

tipo_item preencher_item(){
	
	tipo_item item;
	printf("\n\n ***** PREENCHENDO ITEM A SER INSERIDO *****");
	
	printf("\n\n Digite o código: ");
	scanf("%d", &item.cod);
	
	fflush(stdin); // limpar o buffer do teclado
	printf("\n\n Digite o nome do item: ");
	fgets(item.nome,strlen(item.nome),stdin);
	
	printf("\n\n Digite a quantidade: ");
	scanf("%d", &item.quant);
	
	return(item);
}

tipo_no* inserir(tipo_item x, tipo_no *raiz, tipo_no *r){
  	
  	if(!r){
  		r = (tipo_no *) malloc(sizeof(tipo_no));
  		if(!r){
  			printf("\n\n ERRO: Problema de espa�o na mem�ria !!!");
			getch(); // segura a tela
			exit(0); // fecha o programa	
		}
		
		r->esq = NULL;
		r->dir = NULL;
		//r->esq = r->dir = NULL; // atribui��o multipla
		r->item = x; 
		
		if(!raiz){
		  printf("\n\n Item inserido com sucesso!!!");
          getch();
		 return r; // primeira entrada => raiz da �rvore
		}
		
		if(x.cod < raiz->item.cod) raiz->esq = r;
			
		else raiz->dir = r;
		
		printf("\n\n Item inserido com sucesso!!!");
        getch();
		
		return r;
		
	}
	
	if(x.cod < r->item.cod) inserir(x , r, r->esq);
	
	else if(x.cod > r->item.cod)  inserir(x , r, r->dir);
	
	else{
		printf("\n\n IMPOSSÍVEL INSERIR !!!"); 	
	    printf("\n\n MOTIVO: JÁ existe um item com o código %d na árvore", x.cod);
		getch(); // segura a tela
	}		
} // fim inserir()

void mostrar(tipo_no *raiz){	
	
	if(!raiz) return;
	
	mostrar(raiz->esq);
	
	printf("\n**********************");
		
	printf("\n Cod: %d  ", raiz->item.cod);
	
	printf("\n Nome: %s  ", raiz->item.nome);
	
	printf("\n Quantidade: %d  \n", raiz->item.quant);
	
	mostrar(raiz->dir);
}


void pesquisar(int codPesq, tipo_no *raiz){	 
	
	if(!raiz) {		
		printf("\n\n O item de código %d não está na árvore", codPesq);  		
		return; 
	}

	if(codPesq < raiz->item.cod){	
	   pesquisar(codPesq, raiz->esq);
	   return;
    }
    
    if(codPesq > raiz->item.cod)	
	   pesquisar(codPesq, raiz->dir);   		

    else{	
		printf("\n\n *** ITEM ENCONTRADO ***");
		printf("\n\n C�digo: %d  ", raiz->item.cod);
		printf("\n\n Nome: %s  ", raiz->item.nome);
		printf("\n\n Quantidade: %d  ", raiz->item.quant);		 
	}
}


tipo_no* excluir(int *achou, int cod, tipo_no *raiz){
	
	tipo_no *p, *p2;
	
	if(!raiz) return raiz; // n�o encontrado
	
	if(raiz->item.cod == cod){ // apaga a raiz. A �rvore ficar� vazia
		
		*achou = 1;
		
		if(raiz->esq == raiz->dir){
			free(raiz);
			return NULL;
		}
		
		// ou se uma sub�rvore for nula
		else if(raiz->esq == NULL){
			p = raiz->dir;
			free(raiz);
			return p;
		}
		else if(raiz->dir == NULL){
			p = raiz->esq;
			free(raiz);
			return p;
		}
		
		// ou as duas sub�rvores est�o presentes
		else{
			p2 = raiz->dir;			
			p = raiz->dir;
			
			while(p->esq) p = p->esq;
			
			p->esq = raiz->esq;
			
			free(raiz);
			
			return p2;
		}
	}
	
	if(raiz->item.cod < cod) 
		raiz->dir = excluir(achou, cod, raiz->dir); 
	else
	    raiz->esq = excluir(achou, cod, raiz->esq); 
	    
	return raiz;
}


int main( ) { 
    setlocale(LC_ALL, "");
    
    int op, cod, achou; 

    tipo_no *raiz = NULL;
    
    tipo_item aux;
        
    do{
    	system("cls");
    	
    	op = menu();
    	
    	switch(op){
    		
    		case 0: printf("\n\n\n\t Fim do Programa. \n\n");	
					return(0);
					
			case 1: aux = preencher_item();	
					if(!raiz) raiz = inserir(aux, raiz, raiz);					
					else inserir(aux, raiz, raiz);
    		        break;
    		        
    		case 2: printf("\n\n CONTEÚDO DA ÁRVORE: ");
					mostrar(raiz);    		        
    				getch(); // segura a tela
    		        break;
    		        
    		case 3:	printf("\n\n PESQUISA NA ÁRVORE ");
    				printf("\n\n Digite o código do item a pesquisar: ");
    				scanf("%d", &cod);    		
					pesquisar(cod, raiz);  					
					getch(); // segura a tela	   				
    		        break;
    		        
    		case 4: printf("\n\n EXCLUIR DA ÁRVORE ");
    				printf("\n\n Digite o código do item a excluir: ");
    				scanf("%d", &cod);
    				achou = 0;
    				raiz = excluir(&achou, cod, raiz);
    				if(!achou) printf("\n\n O item de código %d não está na árvore", cod);
    				else printf("\n\n O item de código %d foi excluído com sucesso !!!", cod);
    				getch(); // segura a tela
    		        break;					
    		
			default: 
			    printf("\n\n OPCAO INVALIDA !!!");
			    getch();
		}// fim switch      	    	
	}while(1);//fim do-while	
	return(0);
}// fim main

