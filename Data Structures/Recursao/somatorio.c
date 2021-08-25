# include <stdio.h>

int somatorio(int n){
    if (n == 1) return 1;
    else return somatorio(n-1)+n;
}

int main(){
    int num;
    printf("\n Informe o número: ");
    scanf("%d",&num);
    printf("\n Somatorio de %d = %d\n",num,somatorio(num));
    
    return 0;
}