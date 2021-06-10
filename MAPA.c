#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define STR 30
#define FILA 5

struct tmatriculas {
	int RA[FILA];
	char nome_arquivo[FILA];
	char extensao_arquivo[FILA];
	int matricula_responsavel[FILA]; //numero da matricula do professor respons�vel pela corre��o
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
		printf("Escreva o nome do Arquivo: ");
		scanf("%s", &fila.nome_arquivo[fila.fim]);
		printf("Escreva a extens�o do arquivo: ");
		scanf("%s", &fila.extensao_arquivo[fila.fim]);
		printf("Digite a Matricula do professor repons�vel pela corre��o: ");
		scanf("%d", &fila.matricula_responsavel[fila.fim]);
		fila.fim++;
	}
}

void imprimir(){
	int i;
	
	if(fila.ini == NULL){
		printf("N�o h� atividades para mostrar!\n");
	}
	else{
		for(i = 0; i < FILA; i++){
			printf("%d", fila.RA[i], "\n");
			printf("%s", fila.nome_arquivo[i], "\n");
			printf("%s", fila.extensao_arquivo[i], "\n");
			printf("%d", fila.matricula_responsavel[i], "\n");
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
		printf("Escolha uma op��o: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				fila_matricular();
		}	
	}while(opcao != 5);
}

