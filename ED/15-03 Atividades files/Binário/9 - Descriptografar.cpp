#include <stdio.h>
#include <string.h>
#include <locale.h>

#define CHAVE 1 // Valor a ser adicionado ao código ASCII de cada caractere

int main() {
    setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
        FILE *arq_original, *arq_descriptografado;
        char path_original[50], path_descriptografado[50];
        char ch;

        printf("Digite o nome do arquivo criptografado: ");
        scanf("%s", path_original);
        
        printf("Digite o nome do arquivo descriptografado: ");
        scanf("%s", path_descriptografado);

        arq_original = fopen(path_original, "rb");
        if (arq_original == NULL) {
            printf("Erro ao abrir o arquivo original.\n");
            return 0;
        }

        arq_descriptografado = fopen(path_descriptografado, "wb");
        if (arq_descriptografado == NULL) {
            printf("Erro ao criar o arquivo criptografado.\n");
            fclose(arq_original);
            return 0;
        }

        while (fread(&ch, sizeof(char), 1, arq_original)) {
            // Adicionar a chave ao código ASCII de cada caractere
            ch = ch - CHAVE;

            // Escrever o caractere criptografado no arquivo
            fwrite(&ch, sizeof(char), 1, arq_descriptografado);
        }

        printf("\nArquivo descriptografado com sucesso.\n");

        fclose(arq_original);
        fclose(arq_descriptografado);

        scanf("%s", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}

