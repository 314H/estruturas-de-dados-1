#include <stdio.h>
#include <stdlib.h>

void inserir(int *vet, int n){
	
	int i;
	
	for( i = 0 ; i < n ; i++){
		
		printf("\n\n Digite o %d� nr: ", i + 1);
		
		scanf("%d", &vet[i]);
	}
}

void mostrar(int *vet, int n){
	
	int i;
	
	printf("\n\n Conte�do do vetor: ");
	
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

void insertsort(int *vet, int n){
	int i,j,aux;
	for(i = 1; i < n; i++){
		aux = vet[i];
		j = i - 1;
		
		while(j >=0 && aux < vet[j]){
			vet[j+1] = vet[j];
			j--;
		}
		
		vet[j+1] = aux;
	}
}

void shellsort(int *vet,int n){
	int i, j, gap, aux;
	
	for(gap = 1; gap < n; gap = 3*gap+1); /*Define automaticamento o tamanho da concha*/
	
	while(gap > 0){
		gap = (gap-1)/3;
		for(i = gap; i < n; i++){
			aux = vet[i];
			j = i;
			
			while(vet[j-gap]>aux){
				vet[j] = vet[j-gap];
				j = j - gap;
				
				if(j < gap) break;
			}
			
			vet[j] = aux;				
		}
	}
}

int main( ) { 
    
    
    int n, *vet;    
    printf("\n\n Digite o tamanho do vetor: ");    
    scanf("%d", &n);    
    
    vet = (int *) malloc(sizeof(int)); // vet definido dinamicamente    
    inserir(vet, n);
    
    printf("\n Vetor Original: ");    
    mostrar(vet, n);
    
    //bubbleSort(vet, n); algoritmo da bolha
    //insertsort(vet,n); 
    shellsort(vet,n);
    
    printf("\n Vetor Ordenado: "); 
	mostrar(vet, n);    
    
	return(0);
}
