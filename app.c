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

	//Verifica se o número de registros não excede o permitido
	if(n_linhas > 50){
		fprintf(stderr, "Número de registros do arquivo de alunos doi excedido! \n");
		return 0;
	}

	//Lê os registros de alunos para o vetor_alunos
	/*fseek(alunos, 0, SEEK_SET); 
	for(i=0; i<= n_linhas; i++){
		fscanf(alunos, "%d", &vetor_aluno[i] );

	}*/


	//Abre o arquivo de notas e arvazena em no vetor_notas
	notas = fopen("notas.txt", "r");
	if(notas == NULL){
		fprintf(stderr, "Arquivo de notas não está acessivel \n");
		return 0;
	}

	while(!feof(alunos)){
		c = fgetc(alunos);
		if( c == '\n')
			n_linhas++;
	}

	fseek(notas, 0, SEEK_SET);
	for(i=0; i<=n_linhas; i++){
		fscanf(notas, "%d ", &vetor_nota[i].matricula);
		fscanf(notas, "%f ", &vetor_nota[i].nota1);
		fscanf(notas, "%f", &vetor_nota[i].nota2);
	}

	printf("%d", vetor_nota[1].matricula);

}

//Criar função para exibir medias;

