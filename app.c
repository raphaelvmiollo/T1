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

float calculaMedia(struct nota *vetor_nota, int notas_tam, int matricula);

int main(int argc, char *argv[]){

	FILE *notas, *alunos;
	int c, alunos_tam = 0, notas_tam = 0, i;
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
			alunos_tam++;
	}

	//Verifica se o número de registros não excede o permitido
	if(alunos_tam > 50){
		fprintf(stderr, "Número de registros do arquivo de alunos foi excedido! \n");
		return 0;
	}

	notas = fopen("notas.txt", "r");
	if(notas == NULL){
		fprintf(stderr, "Arquivo de notas não está acessivel \n");
		return 0;
	}

	while(!feof(notas)){
		c = fgetc(notas);
		if( c == '\n')
			notas_tam++;
	}

	//Verifica se o número de registros não excede o permitido
	if(notas_tam > 50){
		fprintf(stderr, "Número de registros do arquivo de notas foi excedido! \n");
		return 0;
	}

	fseek(notas, 0, SEEK_SET);
	for(i=0; i<notas_tam; i++){
		fscanf(notas, "%d ", &vetor_nota[i].matricula);
		fscanf(notas, "%f ", &vetor_nota[i].nota1);
		fscanf(notas, "%f", &vetor_nota[i].nota2);
	}
	
	//BUSCAR POR NOME AQUI

}


//Função recebe uma matricula e retorna a media
float calculaMedia(struct nota *vetor_nota, int notas_tam, int matricula){
	int i = 0;
	float media = 0;
	for (i = 0; i < notas_tam; ++i)	{
		if(vetor_nota[i].matricula == matricula){
			media = vetor_nota[i].nota1 + vetor_nota[i].nota2;
			media = media/2;
		}	
	}
	return media;
}


