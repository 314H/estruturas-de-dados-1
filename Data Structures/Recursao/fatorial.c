#include <stdio.h>

int fat(int n){
    if (n==0) return 1;
    else return fat(n-1)*n;
}

int main(){

    int nr;
    printf("\n Informe o número: ");
    scanf("%d",&nr);

    printf("%d! = %d\n",nr,fat(nr));    

    return 0;
}