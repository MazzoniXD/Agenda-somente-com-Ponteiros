#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDADE (0)
#define TELEFONE (sizeof(int))
#define NOME (sizeof(int) * 2)
#define ANTERIOR (sizeof(int) * 2 + sizeof(char) * 10)
#define PROXIMO (sizeof(int) * 2 + sizeof(char) * 10 + sizeof(void**))
#define CADA_PESSOA (sizeof(int) * 2 + (sizeof(char) * 10) + (sizeof(void**) * 2))

//int *totalPessoas;
//int *incrementador;


int main(){
	//void *pBuffer = malloc(sizeof(int) * 3 + sizeof(CADA_PESSOA) * 2);
	void *pBuffer = malloc(sizeof(int) * 3 + sizeof(void**) * 2);
	int *escolha = pBuffer;
	
	// totalPessoas não precisa ser global
	// quando for usar tu busca a variavel em pBuffer
	int *totalPessoas = (pBuffer + sizeof(int));
	
	// não precisa declarar incrementador aqui, o valor vai ta armazenando  
	// em pBuffer e tu pode pegar direto dele quando for usar
	int *incrementador = (pBuffer + sizeof(int) * 2);

	*escolha = 0;
	
	*totalPessoas = 0;

	//*incrementador = malloc(sizeof(int));

	printf("\nBEM-VINDO A AGENDA!!!");
	while (*escolha != 5){
		printf("\n\nPor favor escolhor o que pretende fazer!");
		printf("\n 1 - Incluir");
		printf("\n 2 - Apagar");
		printf("\n 3 - Buscar");
		printf("\n 4 - Listar");
		printf("\n 5 - Sair");
		printf("\nResposta: ");
		scanf("%d", escolha);

		switch (*escolha){
			case 1:
				incluir(pBuffer);
				break;
			
			case 2:
			printf("2");
				break;
			
			case 3:
			printf("3");
				break;
			
			case 4:
			printf("4");
				break;

			case 5:
				printf("Obrigado por ter usado a agenda :D");
				return 0;
				break;

			default:
				printf("Digitou nenhuma opcao :(\n");
				break;
		}
	}
}

void incluir(void *pBuffer) {
	void *pessoa = malloc(sizeof(CADA_PESSOA));
	int *idade = pessoa + IDADE;
	int *telefone = pessoa + TELEFONE;
	char *nome = pessoa + NOME;
	int *anterior = pessoa + ANTERIOR;
	int *proximo = pessoa + PROXIMO;
	
	/*
	baseado nas posições acima, estaria simulando uma struct organizada da seguinte maneira:
		typedef struct pessoa {
			int idade
			int telefone
			char nome[10]
			void ** anterior
			void ** proximo
		}
	*/
	

	printf("\nDigite o nome da Pessoa: ");
	scanf("%s", nome);
	printf("\nDigite a idade da Pessoa: ");
	scanf("%d", idade);
	printf("\nDigite o telefone da Pessoa: ");
	scanf("%d", telefone);

	printf("%s %d %d", nome, *idade, *telefone);

	int *totalPessoas = (int*) (pBuffer + sizeof(int));

	if(*totalPessoas == 0){
		pBuffer + (sizeof(int) * 3) = &pessoa;
		pBuffer + (sizeof(int) * 3 + sizeof(void**)) = &pessoa;
	}
	
	//testar se totalPessoas == 0
	//se sim, significa que não tem ninguem na lista
	//e portanto tu precisa salvar esses valores na cabeça da fila
	//ou seja, em pBuffer
	//os ponteiros de proximo e anterior recebem NULL, pois não
	//há ninguem pra apontar
	
	//se for diferente de 0, já tem alguem armazenado na cabeça
	//e tu vai precisar salvar o endereço de * pessoa
	//em (pBuffer + (sizeof(int) * 3) + pessoa + sizeof(char) * 10 + sizeof(int) * 2)
	//ou seja pBuffer + os três inteiros iniciais + deslocamento o suficiente 
	//pra estar no espaço da cabeça da fila, na variável PROXIMA
	
	//pra facilitar, tu pode declarar um ponteiro cabeça/head/start
	//que vai receber o endereço da cabeça
	
	//void * inicio = (pBuffer + sizeof(int) * 3);
	//seria como se inicio fosse o primeiro elemento da fila
	//e ele vai ter inicio.nome  --  inicio.idade  --  inicio.telefone
	//inicio.proximo --- inicio.anterior
	//mas tu vai ter que fazer isso com aritmetica de ponteiros, como lá em cima
	//quando declarou pessoa

	totalPessoas++;
	
	//tu não precisa fazer realloc, pois os elementos não vão estar armazeandos de 
	//forma continua na memória, mas sim um apontando pro outro
	/*  CABEÇA
	       > PESSOA1
		        > PESSOA2
				     > PESSOA 3
					      > ...
	*/
	
	/*fila = realloc(fila, (sizeof(int) * 2) + sizeof(CADA_PESSOA) * (*totalPessoas));
	
	//esse for vai ter que ser substituido por algo que te permita ir de pessoa em pessoa
	//tu vai pegar a cabeça da lista, 
	//se ela não for nula (totalPessoas != 0)
	//tu precisa pegar o proximo elemento
	//void * cabeça = pBuffer + deslocamento
	//void * aux = *(cabeça + deslocamento_até_ponteiro_proximo)
	for(*incrementador = 1; *incrementador <= *totalPessoas; *incrementador++)
	{
		fila = sizeof(int) * 2 + ((sizeof(CADA_PESSOA)) * *incrementador);
		if(*(int *)fila == NULL){
			*proximo = &pessoa;
			*(int *)fila = *proximo;
			fila += (sizeof(int));
			*(int *)fila = *anterior;
			fila += (sizeof(int));
			*(int *)fila = *idade;
			fila += (sizeof(int));
			*(int *)fila = *telefone;
			fila += (sizeof(int));
			*(char *)fila = *nome;
		} else {
			*anterior = *(int *)fila;
		}
	}*/
	
}
