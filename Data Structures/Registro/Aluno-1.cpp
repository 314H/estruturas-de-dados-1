#include <stdio.h>
#include <locale.h>
#include <conio.h> // só para usar o getch()
typedef struct tipo_data{
	int dia, mes, ano;
};

typedef struct tipo_end{
	char rua[60], nr[10], bairro[30];
	char mun[60], uf[3], cep[11];
};

typedef struct tipo_aluno{
	char mat[10], nome[60], sexo, curso[30];
	tipo_data nasc;
	tipo_end end; 
};

int main() {
	setlocale(LC_ALL, "");
	
	tipo_aluno a1, a2;
	
	printf("\n\n ======= CADASTRANDO DADOS =======");
	
	printf("\n\n ****** ALUNO 1 ******");
	
	fflush(stdin);
	printf("\n\n Matrícula: ");
	gets(a1.mat);
	
	fflush(stdin);
	printf("\n\n Nome: ");
	gets(a1.nome);
	
	fflush(stdin);
	printf("\n\n sexo: ");
	a1.sexo = getchar();
	
	fflush(stdin);
	printf("\n\n Curso: ");
	gets(a1.curso);
	
	printf("\n\n Data de nascimento: ");
	
	printf("\n\t Dia: ");
	scanf("%d", &a1.nasc.dia);
	
	printf("\t Mês: ");
	scanf("%d", &a1.nasc.mes);
	
	printf("\t Ano: ");
	scanf("%d", &a1.nasc.ano);
	
	printf("\n\n Endereço: ");
	fflush(stdin);
	printf("\n\t Rua: ");
	gets(a1.end.rua);
	
	fflush(stdin);
	printf("\n\t Nr: ");
	gets(a1.end.nr);
	
	fflush(stdin);
	printf("\n\t Bairro: ");
	gets(a1.end.bairro);
	
	fflush(stdin);
	printf("\n\t Município: ");
	gets(a1.end.mun);
	
	fflush(stdin);
	printf("\n\t UF: ");
	gets(a1.end.uf);
	
	fflush(stdin);
	printf("\n\t CEP: ");
	gets(a1.end.cep);
	
	printf("\n\n DADOS CADASTRADOS COM SUCESSO !!!");
	
	getch();
	
	printf("\n\n ****** ALUNO 2 ******");
	
	fflush(stdin);
	printf("\n\n Matrícula: ");
	gets(a2.mat);
	
	fflush(stdin);
	printf("\n\n Nome: ");
	gets(a2.nome);
	
	fflush(stdin);
	printf("\n\n sexo: ");
	a2.sexo = getchar();
	
	fflush(stdin);
	printf("\n\n Curso: ");
	gets(a2.curso);
	
	printf("\n\n Data de nascimento: ");
	
	printf("\n\t Dia: ");
	scanf("%d", &a2.nasc.dia);
	
	printf("\t Mês: ");
	scanf("%d", &a2.nasc.mes);
	
	printf("\t Ano: ");
	scanf("%d", &a2.nasc.ano);
	
	printf("\n\n Endereço: ");
	fflush(stdin);
	printf("\n\t Rua: ");
	gets(a2.end.rua);
	
	fflush(stdin);
	printf("\n\t Nr: ");
	gets(a2.end.nr);
	
	fflush(stdin);
	printf("\n\t Bairro: ");
	gets(a2.end.bairro);
	
	fflush(stdin);
	printf("\n\t Município: ");
	gets(a2.end.mun);
	
	fflush(stdin);
	printf("\n\t UF: ");
	gets(a2.end.uf);
	
	fflush(stdin);
	printf("\n\t CEP: ");
	gets(a2.end.cep);
	
	printf("\n\n DADOS CADASTRADOS COM SUCESSO !!!");
	
	getch();
	
	
	printf("\n\n ======= MOSTRANDO DADOS =======");
	
	printf("\n\n ****** ALUNO 1 ******");	
	printf("\n Matrícula: %s", a1.mat);
	printf("\n Nome: %s", a1.nome);
	printf("\n Sexo: %c", a1.sexo);
	printf("\n Curso: %s", a1.curso);
	printf("\n Data de Nascimento: %d/%d/%d ", a1.nasc.dia, a1.nasc.mes, a1.nasc.ano);
	printf("\n Endereço: ");
	printf("\n\t Rua: %s", a1.end.rua);
	printf("\n\t Nr: %s", a1.end.nr);
	printf("\n\t Bairro: %s", a1.end.bairro);
	printf("\n\t Município: %s", a1.end.mun);
	printf("\n\t UF: %s", a1.end.uf);
	printf("\n\t CEP: %s", a1.end.cep);
	
	getch();
	
	printf("\n\n ****** ALUNO 2 ******");	
	printf("\n Matrícula: %s", a2.mat);
	printf("\n Nome: %s", a2.nome);
	printf("\n Sexo: %c", a2.sexo);
	printf("\n Curso: %s", a2.curso);
	printf("\n Data de Nascimento: %d/%d/%d ", a2.nasc.dia, a2.nasc.mes, a2.nasc.ano);
	printf("\n Endereço: ");
	printf("\n\t Rua: %s", a2.end.rua);
	printf("\n\t Nr: %s", a2.end.nr);
	printf("\n\t Bairro: %s", a2.end.bairro);
	printf("\n\t Município: %s", a2.end.mun);
	printf("\n\t UF: %s", a2.end.uf);
	printf("\n\t CEP: %s", a2.end.cep);

	return(0);
}
