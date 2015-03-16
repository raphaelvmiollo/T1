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

	FILE *notas, *alunos;
	int c, n_linhas = 0, i;
	struct nota vetor_nota[50];
	struct aluno vetor_aluno[50];

	//Verifica se o número de parametros passados estão corretos
	if (argc != 2){
		fprintf(stderr, "Informe apenas o nome do aluno desejado \n");
		return 0;
	}

	//Abre o arquivo de alunos e verifica se o arquivo foi aberto corretamente
	alunos = fopen("alunos.txt", "r");
	if(alunos == NULL){
		fprintf(stderr, "Arquivo de alunos não está acessivel! \n" );
		return 0;
	}

	//Conta as linhas do arquivo de alunos para saber quantos registros exsitem 
	while(!feof(alunos)){
		c = fgetc(alunos);
        if( c == '\n')
            n_linhas++;
	}




}
