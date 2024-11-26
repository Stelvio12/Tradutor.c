#include <stdio.h>
#include <string.h>
typedef struct {
    char portugues[50];
    char nyaneka[50];
} Dicionario;

void traduzir(const char *entrada, Dicionario *dicionario, int tamanho, int paraNyaneka) {
    for (int i = 0; i < tamanho; i++) {
        if ((paraNyaneka && strcmp(entrada, dicionario[i].portugues) == 0) ||
            (!paraNyaneka && strcmp(entrada, dicionario[i].nyaneka) == 0)) {
            printf("%s\n", paraNyaneka ? dicionario[i].nyaneka : dicionario[i].portugues);
            return;
        }
    }
    printf("Palavra não encontrada no dicionário.\n");
}

int main() {
    
    Dicionario dicionario[] = {
        {"olá", "mbote"},
        {"como", "nangi"},
        {"você", "we"},
        {"está", "okulile"},
        {"bem", "nali"},
        {"adeus", "kwaheri"}
    };
    int tamanhoDicionario = sizeof(dicionario) / sizeof(Dicionario);

    char palavra[50];
    int opcao;

    printf("Tradutor Português - Nyaneka\n");
    printf("Escolha uma opção:\n");
    printf("1. Português para Nyaneka\n");
    printf("2. Nyaneka para Português\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    if (opcao == 1) {
        traduzir(palavra, dicionario, tamanhoDicionario, 1);
    } else if (opcao == 2) {
        traduzir(palavra, dicionario, tamanhoDicionario, 0);
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
    }
