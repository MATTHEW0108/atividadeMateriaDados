#define MAX 50
#include <string.h>
#include <stdio.h>


typedef struct{
	char titulo[30];
	char data[10];
	char hora[5];
	char plataforma[15];
	char apresentador[30];
	char artista[30];
} LIVE;

void inicializar(void);
void cadastrar (int, char *, char *, char *, char *, char *, char *);
void excluir (int);
void pesquisa (char *);
void exibirTodos (void);



LIVE live[MAX];


void inicializar(){
	int pos;
	for (pos = 0; pos < MAX; pos++){
		strcpy(live[pos].titulo, "");
		strcpy(live[pos].data, "");
		strcpy(live[pos].hora, "");
		strcpy(live[pos].plataforma, "");
		strcpy(live[pos].apresentador, "");
		strcpy(live[pos].artista, "");
	}
}

void cadastrar(int posicao, char *titulo, char *data, char *hora, char *plataforma, char *apresentador, char *artista){
	
	if (posicao > MAX || ( strcmp(live[posicao].titulo, "") != 0 ) || ( strcmp(live[posicao].data, "") != 0 ) || ( strcmp(live[posicao].hora, "") != 0 ) || ( strcmp(live[posicao].plataforma, "") != 0 ) || ( strcmp(live[posicao].apresentador, "") != 0 ) || ( strcmp(live[posicao].artista, "") != 0 )){
		printf("Posição fora do limite do vetor ou contem dados!");
	}else if (posicao < 0){
		printf("Posição menor que 0 -> ERRO");
	}else{
		strcpy(live[posicao].titulo, titulo);
		strcpy(live[posicao].data, data);
		strcpy(live[posicao].hora, hora);
		strcpy(live[posicao].plataforma, plataforma);
		strcpy(live[posicao].apresentador, apresentador);
		strcpy(live[posicao].artista, artista);	
	}
}

void excluir(int posicao){
	strcpy(live[posicao].titulo, "");
	strcpy(live[posicao].data, "");
	strcpy(live[posicao].hora, "");
	strcpy(live[posicao].plataforma, "");
	strcpy(live[posicao].apresentador, "");
	strcpy(live[posicao].artista, "");
}

void pesquisa(char *artista){
	int pos;
	for (pos = 0; pos < MAX; pos++){
		if (strcmp(live[pos].artista, artista) == 0){
			printf("\nTitulo: %s\nData: %s\nHora: %s\nPlataforma: %s\nApresentador: %s\nArtista: %s\n", live[pos].titulo, live[pos].data, live[pos].hora, live[pos].plataforma, live[pos].apresentador, live[pos].artista);
		}
	}

}

void exibirTodos(){
	int pos;
	for (pos = 0; pos < MAX; pos++){
		printf("\nPosicao: %d\nTitulo: %s\nData: %s\nHora: %s\nPlataforma: %s\nApresentador: %s\nArtista: %s\n", pos, live[pos].titulo, live[pos].data, live[pos].hora, live[pos].plataforma, live[pos].apresentador, live[pos].artista);
	}
}


int main(){
	//inicializando o array
  	inicializar();
  	
	//a) cadastrandov uma live
	cadastrar(0, "LIVE 1", "18/05/2015", "15:15", "YouTube", "Matheus Ribeiro", "Artista 1");
	
	//b) testando a pesquisa por artisra (cadastrando mais lives antes para testar a funcionalidade
	cadastrar(1, "LIVE 1", "18/05/2015", "15:15", "YouTube", "Matheus Ribeiro", "Artista 1");
	cadastrar(2, "LIVE 2", "25/08/2018", "19:14", "YouTube", "Matheus Ribeiro 2", "Artista 29");
	cadastrar(3, "LIVE 3", "05/02/2020", "09:02", "YouTube", "Matheus Ribeiro 3", "Artista 408");
	char *artista = "Artista 408";
	pesquisa(artista);
	
	//c) exibindo todas as lives
	exibirTodos();

}



