#include <stdio.h>
#include <math.h>

int main(){
    int escolha;
    int idade;
    int telefone;
    char nome[30];

    do{
        printf("\n\nDigite o que voce pretende fazer\n 1 - Inserir\n 2 - Remover\n 3 - Buscar\n 4 - Listar\n X - Sair\nResposta: ");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            printf("\nDigite o nome: ");
            scanf("%c", &nome);
            printf("\nDigite a idade: ");
            scanf("%i", &idade);
            printf("\nDigite o telefone: ");
            scanf("%i", &telefone);
            // Lista Encadeada
            break;
        
        case 2:
            printf("\nDigite o nome da pessoa que pretendo remover: ");
            scanf("%c", &nome);
            // Lista Encadeada
            break;

        case 3:
            printf("\nDigite o nome da pessoa que voce pretende buscar: ");
            scanf("%c", &nome);
            // Lista Encadeada
            break;

        case 4:
            // Lista Encadeada
            break;
    
        default:
            printf("\nSaindo...");
            break;
        }
    }while (escolha > 0 && escolha < 5);

    return 0;
}