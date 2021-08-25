#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para malloc()


void inserir(int *vet, int n){
	
	int i;
	
	for( i = 0 ; i < n ; i++){
		
		printf("\n\n Digite o %dº nr: ", i + 1);
		
		scanf("%d", &vet[i]);
	}
}

void mostrar(int *vet, int n){
	
	int i;
	
	printf("\n\n Conteúdo do vetor: ");
	
	for( i = 0 ; i < n ; i++)
		
		printf("%d ", vet[i]);
		
}

void bubbleSort(int *vet, int n){
	
	int i, j, aux;	
	
	for( j = 0 ; j < n ; j++)
		
		for( i = 0 ; i < n - 1 ; i++) // importante i < n - 1
		
		     if(vet[i] > vet[ i + 1 ]){			 
		        
		           aux = vet[i];
		           vet[i] = vet[ i + 1 ];
		           vet[ i + 1 ] = aux;	
			}
}

int main( ) { 
    setlocale(LC_ALL, "");
    
    int n, *vet;
    
    printf("\n\n Digite o tamanho do vetor: ");
    
    scanf("%d", &n);
    
    vet = (int *) malloc(sizeof(int)); // vet definido dinamicamente
    
    inserir(vet, n);
    
    printf("\n\n Vetor Original: ");
    
    mostrar(vet, n);
    
    bubbleSort(vet, n); 
    
    printf("\n\n Vetor Ordenado: ");
 
	mostrar(vet, n);    
    
	return(0);
}

