#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para malloc()

void inserir(int *vet, int n){
	
	int i;
	
	for( i = 0 ; i < n ; i++){
		
		printf("\n\n Digite o %dº nr: ", i + 1);
		
		scanf("%d", &vet[i]);
	}
} // fim inserir

void mostrar(int *vet, int n){
	
	int i;
	
	printf("\n\n Conteúdo do vetor: ");
	
	for( i = 0 ; i < n ; i++)
		
		printf("%d ", vet[i]);
		
} // fim mostrar

void selectionSort(int *vet, int n){
	
	int	i, j, min, aux;        
	           
	for	(i = 0; i < n - 1; i++){         
	      
		min = i;  		
		
     	for ( j = i + 1 ; j < n ; j++ ) 
     		
       		if(vet[j] < vet[min]) 
       		
         		min = j; // acha o índice do menor do vetor
     	     	
     	if (i != min) { // evita trocar na mesma posição
     	
       		aux = vet[i];
       		
       		vet[i] = vet[min];
       		
       		vet[min] = aux;
     	} 
     	
	}
} // fim selectionSort

int main( ) { 
    setlocale(LC_ALL, "");
    
    int n, *vet;
    
    printf("\n\n Digite o tamanho do vetor: ");
    
    scanf("%d", &n);
    
    // vetor definido dinamicamente:
    vet = (int *) malloc(sizeof(int)); 
    
    inserir(vet, n);
    
    printf("\n\n Vetor Original: ");
    
    mostrar(vet, n);
    
    selectionSort(vet, n); 
    
    printf("\n\n Vetor Ordenado: ");
 
	mostrar(vet, n);    
    
	return(0);
}

