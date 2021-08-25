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

typedef struct tipo_lista{

	tipo_celula *prim;

	tipo_celula *ultima;

	int total;
};

void flvazia(tipo_lista *lista){
	
	lista->prim = (tipo_celula *)malloc(sizeof(tipo_celula));
	lista->ultima = lista->prim;
	lista->prim->prox = NULL;	
	lista->total = 0;
}

int vazia(tipo_lista *lista){
	return(lista->total == 0);
	// return(lista->prim == lista->ultima); // também está certo
}

int menu(){
	int op; 
	char c;
	
	while(1){ // Laço infinito até que o usuário digite de 0 a 9
		
		printf("\n\n UTILIZAÇÃO DE LISTA ENCADEADA");
	
		printf("\n\n ********* MENU *********");
    	
    	printf("\n [1] - INSERIR");
    	
    	printf("\n [2] - MOSTRAR");
    	
    	printf("\n [3] - PESQUISAR");
    	
    	printf("\n [4] - REMOVER");
    
    	printf("\n [5] - INSERIR EM UMA POSIÇÃO");
    	
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

void inserir(tipo_lista *lista){
	
	lista->ultima->prox = (tipo_celula *)malloc(sizeof(tipo_celula));
		
	lista->ultima = lista->ultima->prox;
	
	lista->ultima -> item= inserirItem();
	
	lista->ultima -> prox = NULL;			
	
	lista -> total++;
	
	printf("\n\n ITEM INSERIDO COM SUCESSO!!!");
	
	getch();
}

void mostrar(tipo_lista *lista){
	
	if(vazia(lista)){
		printf("\n\n Impossível mostrar. Motivo: A LISTA ESTÁ VAZIA !!!");
		getch();
		return;
	}
	
	tipo_celula *aux;
	
	int i = 1;
	
	printf("\n\n ====== MOSTRANDO A LISTA ======");
	
	printf("\n\t Total de itens: %d ", lista->total);
	
	aux = lista->prim->prox;
	
	while( aux != NULL){
		printf("\n\n === %dº ITEM ===", i++);
		printf("\n Código: %d", aux->item.cod);
		printf("\n Nome: %s", aux->item.nome);
		printf("\n Quantidade: %d", aux->item.quant);
		
		aux = aux->prox;
	}
	getch();
}


void mostrarItem(tipo_item item, int pos){
	
	if(pos > 0)
		printf("\n\n ===== ITEM ENCONTRADO NA POSIÇÃO %d ===", pos);
	else
	    printf("\n\n ===== ITEM REMOVIDO ===" );
	    
	printf("\n Código: %d", item.cod);
	
	printf("\n Nome: %s", item.nome);
	
	printf("\n Quantidade: %d", item.quant);	
}

void pesqCod(tipo_lista *lista){
	
	int cod, achou = 0, i = 1;
	
	tipo_celula *aux;
	
	printf("\n\n Digite o Código para pesquisa: ");
	scanf("%d", &cod);	
	
	aux = lista->prim->prox;
	
	while( aux != NULL){		
		if(aux->item.cod == cod){		
		    mostrarItem(aux->item, i);
		    achou = 1;   //   return; // Se tiver certeza de que o campo não se repetirá
		}
		i++;
		aux = aux->prox;
	}
		
	if(!achou)
	    printf("\n\n O item de codigo %d não existe na lista !!!", cod);	
}

void pesqNome(tipo_lista *lista){
	
	char nomePesq[30], achou = 0, i = 1;
	tipo_celula *aux;
	
	fflush(stdin);
	printf("\n\n Digite o Nome para pesquisa: ");
	gets(nomePesq);	
	
	aux = lista->prim->prox;
	
	while( aux != NULL){		
		if(!strcmp(aux->item.nome, nomePesq)){		
		    mostrarItem(aux->item, i);
		    achou = 1;
		}
		i++;
		aux = aux->prox;
	}	
	if(!achou)
	    printf("\n\n O item de nome %s não existe na lista !!!", nomePesq);	
}

void pesqQuant(tipo_lista *lista){
	
	int quant, achou = 0, i = 1;
	tipo_celula *aux;	
	
	printf("\n\n Digite a Quantidade para pesquisa: ");
	scanf("%d", &quant);	
	
	aux = lista->prim->prox;
	
	while( aux != NULL){		
		if(aux->item.quant == quant){		
		    mostrarItem(aux->item, i);
		    achou = 1;
		}
		i++;
		aux = aux->prox;
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
	
	if(vazia(lista)){
		printf("\n\n Lista está vazia !!!");
		getch();
		return;
	}
	
	int pos, i;
	
	printf("\n\n Digite a posição do item para remover: ");
	scanf("%d", &pos);	

	if( pos < 1 || pos > lista->total ){
		printf("\n\n A posição é inválida !!!");
		getch();
		return;
	}
	
	tipo_item removido;
	
	tipo_celula *aux, *aux2;	
	
	aux = lista->prim;

	for(i = 1; i < pos; i++)
		aux = aux->prox ; // percorrendo até a posição anterior		
	
	aux2 = aux->prox;
	
	removido = aux2->item;
	
	mostrarItem(removido,0);	
	
	aux->prox = aux2->prox;
	
	if(aux2->prox == NULL){		
		lista->ultima = aux;		
		lista->ultima->prox = NULL;	
	}	
			
	free(aux2); // libera a célula alocada com malloc
	
	lista->total--;
	
    printf("\n\n Item excluído com sucesso !!!");
	
	getch();
}

void inserirPos(tipo_lista *lista){		
	int pos;
	
	printf("\n\n Digite a posição do item para inserir: ");
	scanf("%d", &pos);
	
	if(pos < 1 || pos > lista->total + 1){
		printf("\n\n Posição inválida !!! ");		
		getch();
		return;
	}
	
	if( pos == lista->total + 1 ){	
	    inserir(lista);
	    return;
	}
	
	tipo_celula *ant, *atual, *nova;
	
	atual = lista->prim->prox;
	
	ant = lista->prim; 
	
	nova = (tipo_celula *)malloc(sizeof(tipo_celula));
	
	nova->item = inserirItem();
	
	for( int i = 1 ; i < pos ; i++){
		
 		ant = atual;
 		
 		atual = atual->prox;
	}	
	
	ant->prox = nova; 
	
	nova->prox = atual;
	
	lista -> total++;
	
	printf("\n\n ITEM INSERIDO COM SUCESSO!!!");
	
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
			    getch();                                             		} 
		   	
    	
	}while(1);	

	return(0);
}
