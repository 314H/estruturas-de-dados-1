#include <stdio.h>

int potencia(int base, int exp){
    if (exp == 0)
        return 1;
    return (base*potencia(base,exp-1));
}

int main(){

    int x,n;
    printf("\n Informe a base: ");
    scanf("%d",&x);
    printf("\nInforme o expoente: ");
    scanf("%d",&n);
    printf("\n %d ^ %d = %d\n",x,n,potencia(x,n));   

    return 0;
}