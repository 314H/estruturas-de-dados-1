#include <stdio.h>
#include <locale.h>
#include <conio.h> // s� para usar o getch()
#include <stdlib.h> // s� para usar o system("cls")
struct tipo_data{
	int dia, mes, ano;
};

struct tipo_end{
	char rua[60], nr[10], bairro[30];
	char mun[60], uf[3], cep[11];
};

struct tipo_aluno{
	char mat[10], nome[60], sexo, curso[30];
	tipo_data nasc;
	tipo_end end; 
};

tipo_aluno cadastrar(){
	
	system("cls"); // limpa a tela
	
	tipo_aluno a;
	
	printf("\n\n ======= CADASTRANDO DADOS =======");
	
	printf("\n\n ****** ALUNO ******");
	
	fflush(stdin);
	printf("\n\n Matr�cula: ");
	gets(a.mat);
	
	fflush(stdin);
	printf("\n\n Nome: ");
	gets(a.nome);
	
	fflush(stdin);
	printf("\n\n sexo: ");
	a.sexo = getchar();
	
	fflush(stdin);
	printf("\n\n Curso: ");
	gets(a.curso);
	
	printf("\n\n Data de nascimento: ");
	
	printf("\n\t Dia: ");
	scanf("%d", &a.nasc.dia);
	
	printf("\t M�s: ");
	scanf("%d", &a.nasc.mes);
	
	printf("\t Ano: ");
	scanf("%d", &a.nasc.ano);
	
	printf("\n\n Endere�o: ");
	fflush(stdin);
	printf("\n\t Rua: ");
	gets(a.end.rua);
	
	fflush(stdin);
	printf("\n\t Nr: ");
	gets(a.end.nr);
	
	fflush(stdin);
	printf("\n\t Bairro: ");
	gets(a.end.bairro);
	
	fflush(stdin);
	printf("\n\t Munic�pio: ");
	gets(a.end.mun);
	
	fflush(stdin);
	printf("\n\t UF: ");
	gets(a.end.uf);
	
	fflush(stdin);
	printf("\n\t CEP: ");
	gets(a.end.cep);
	
	printf("\n\n DADOS CADASTRADOS COM SUCESSO !!!");	
	getch();
	
	return(a);
}

void mostrar(tipo_aluno *a){
	
	system("cls"); // limpa a tela
			
	printf("\n\n ======= MOSTRANDO DADOS =======");
	
	printf("\n\n ****** ALUNO ******");	
	printf("\n Matr�cula: %s", a->mat);
	printf("\n Nome: %s", a->nome);
	printf("\n Sexo: %c", a->sexo);
	printf("\n Curso: %s", a->curso);
	printf("\n Data de Nascimento: %d/%d/%d ", a->nasc.dia, a->nasc.mes, a->nasc.ano);
	printf("\n Endere�o: ");
	printf("\n\t Rua: %s", a->end.rua);
	printf("\n\t Nr: %s", a->end.nr);
	printf("\n\t Bairro: %s", a->end.bairro);
	printf("\n\t Munic�pio: %s", a->end.mun);
	printf("\n\t UF: %s", a->end.uf);
	printf("\n\t CEP: %s", a->end.cep);	
	getch();	
}

int main() {
	setlocale(LC_ALL, "");
	
	tipo_aluno a1, a2;
	
	a1 = cadastrar();
	
	a2 = cadastrar();
	
	mostrar(&a1);
	
	mostrar(&a2);	

	return(0);
}
