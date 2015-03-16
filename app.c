#include <stdio.h>
#include <stdlib.h>

//Estrutura que irá armazenar os dados dos alunos
struct aluno{
	char nome[50];
	int matricula;
};

//Estrutura que irá armazenar a matricula e as notas dos alunos
struct nota{
	int matricula;
	float nota1;
	float nota2;
};


int main(int argc, char *argv[]){

	//Verifica se o número de parametros passados estão corretos
	if (argc != 2){
		fprintf(stderr, "Informe apenas o nome do aluno desejado \n");
	}




}
