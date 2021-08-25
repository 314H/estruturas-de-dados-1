#include <stdio.h>
#include <locale.h>
#include <stdlib.h>// para malloc()

#include <conio.h>

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

void insertionSort(int *vet, int n){
	
	int	i, j, aux;        
		           
	for	( i = 1 ; i < n ; i++ ){         
	      
		aux = vet[ i ]; 
		
		j = i - 1;

        while ( j >= 0 && aux < vet[ j ] ) {	
	 		
     		vet[ j + 1 ] = vet[ j ] ;
     		
     		j-- ;
		 }
		 
		 vet[ j + 1 ] = aux ;		 
		 
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
    
    insertionSort(vet, n); 
    
    printf("\n\n Vetor Ordenado: ");
 
	mostrar(vet, n);    
    
	return(0);
}

