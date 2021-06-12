#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILA 5

struct tatividades {
	int RA;
	char nome_arquivo[50];
	char extensao_arquivo[10];
	int matricula_responsavel; 
};

struct tfila {
	struct tatividades dados[FILA];
	int ini;
	int fim;
};

struct tfila fila;

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
	printf("2 - Remover Atividade\n");
}

void fila_matricular(){
	if(fila.fim == FILA){
		printf("\n Numero total de atividades registradas atingidas!\n\n");
		system("pause");
	}
	else{
		printf("Digite o RA: ");
		scanf("%d", &fila.dados[fila.fim].RA);
		printf("Escreva o nome do Arquivo: ");
		scanf("%s", fila.dados[fila.fim].nome_arquivo);
		printf("Escreva a extensão do arquivo: ");
		scanf("%s", fila.dados[fila.fim].extensao_arquivo);
		printf("Digite a Matricula do professor reponsável pela correção: ");
		scanf("%d", &fila.dados[fila.fim].matricula_responsavel);
		fila.fim++;
		system("cls");
	}
}

void imprimir(){
	int i;
	
	if(fila.ini == fila.fim){
		printf("Não há atividades para mostrar!\n");
	}
	else{
		for(i = 0; i < fila.fim; i++){
			printf("%d \n", fila.dados[i].RA);
			printf("%s \n", fila.dados[i].nome_arquivo);
			printf("%s \n", fila.dados[i].extensao_arquivo);
			printf("%d \n", fila.dados[i].matricula_responsavel);
			printf("-----------------\n");
		}
	}
}

remover(){
	int i;
	
	if(fila.ini == fila.fim){
		printf("Não existe atividades para remover!\n\n");
		system("pause");
		system("cls");
	}
	else{
		for(i = 0; i < fila.fim; i++) {
			fila.dados[i] = fila.dados[i + 1];
			strcpy(fila.dados[i].nome_arquivo, fila.dados[i + 1].nome_arquivo);
			strcpy(fila.dados[i].extensao_arquivo, fila.dados[i + 1].extensao_arquivo);
		}
		fila.dados[fila.fim].RA = 0;
		strcpy(fila.dados[fila.fim].nome_arquivo, "");
		strcpy(fila.dados[fila.fim].extensao_arquivo, "");
		fila.dados[fila.fim].matricula_responsavel = 0;
		fila.fim--;
		system("cls");
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
				break;
			
			case 2:
				remover();
				break;
		}	
	}while(opcao != 5);
}

