#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define FILA 5

struct tcad_atividades {
	int RA[FILA];
	char nome_arquivo[STR];
	char extensao_arquivo[STR];
	int matricula_responsavel[FILA]; //numero da matricula do professor responsável pela correção
};

struct tfila {
	tcad_atividades dados;
	int ini;
	int fim;
};

struct tmatriculas fila;

menu(){
	printf("******************************************\n");
	printf("*                                        *\n");
	printf("*                                        *\n");
	printf("*       GERENCIAMENTO DE ATIVIDADES      *\n");
	printf("*                                        *\n");
	printf("*                                        *\n");
	printf("******************************************\n");
}
opcoes(){
	printf("\n1 - Matricular\n");
}

void fila_matricular(){
	if(fila.fim == FILA){
		printf("\n Numero total de matriculas atingido!\n\n");
		system("pause");
	}
	else{
		printf("Digite o RA: ");
		scanf("%d", &fila.RA[fila.fim]);
		fila.fim++;
		printf("Escreva o nome do Arquivo: ");
		scanf("%s", &fila.nome_arquivo[fila.fim]);
		fila.fim++;
		printf("Escreva a extensão do arquivo: ");
		scanf("%s", &fila.extensao_arquivo[fila.fim]);
		fila.fim++;
		printf("Digite a Matricula do professor reponsável pela correção: ");
		scanf("%d", &fila.matricula_responsavel[fila.fim]);
		fila.fim++;
	}
}

void imprimir(){
	int i;
	
	if(fila.ini == fila.fim){
		printf("Não há atividades para mostrar!\n");
	}
	else{
		for(i = 0; i < FILA; i++){
			printf("%d", fila.RA[i]);
			printf("%s", fila.nome_arquivo[i]);
			printf("%s", fila.extensao_arquivo[i]);
			printf("%d", fila.matricula_responsavel[i]);
			printf("-----------------\n");
		}
	}
}

main(){
	int opcao;
	setlocale(LC_ALL, "Portuguese");
	
	do{
		menu();
		imprimir();
		opcoes();
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				fila_matricular();
		}	
	}while(opcao != 5);
}

