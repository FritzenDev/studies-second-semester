#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
8. Fa�a um programa de criptografia de dados, ou seja, um programa capaz de ler um 
arquivo texto, codificar este arquivo atrav�s de alguma t�cnica de altera��o do 
c�digo ASCII (exemplo: somar 1 ao valor ASCII de cada caracter), e escrever em 
um arquivo texto codificado.
*/

#define CHAVE 1 // Valor a ser adicionado ao c�digo ASCII de cada caractere

int main() {
    setlocale(LC_ALL, "Portuguese");
    char continuar;

    do {
        FILE *arq_original, *arq_criptografado;
        char path_original[50], path_criptografado[50];
        char ch;

        printf("Digite o nome do arquivo a ser criptografado: ");
        scanf("%s", path_original);
        
        printf("Digite o nome do arquivo criptografado: ");
        scanf("%s", path_criptografado);

        arq_original = fopen(path_original, "r");
        if (arq_original == NULL) {
            printf("Erro ao abrir o arquivo original.\n");
            return 0;
        }

        arq_criptografado = fopen(path_criptografado, "w");
        if (arq_criptografado == NULL) {
            printf("Erro ao criar o arquivo criptografado.\n");
            fclose(arq_original);
            return 0;
        }

        while ((ch = fgetc(arq_original)) != EOF) {
            // Adicionar a chave ao c�digo ASCII de cada caractere
            ch = ch + CHAVE;

            // Escrever o caractere criptografado no arquivo
            fputc(ch, arq_criptografado);
        }

        printf("\nArquivo criptografado com sucesso.\n");

        fclose(arq_original);
        fclose(arq_criptografado);

        scanf("%s", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}

