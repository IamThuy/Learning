#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int erros = 0;
    char tentativas[50];
    while (1)
    {   
        // escreve as coisas na tela 
        char *cabeca = (erros >= 1) ? "\\0/": " ";
        char *tronco = (erros >= 2) ? "()" : " ";
        char *pernas = (erros >= 3) ? "_||_" : "";
        
        printf("\n%s\n%s\n%s\n", cabeca, tronco, pernas);

        if (erros == 3){
            printf("Você perdeu\n");
            break;
        } 
        

        printf("Digite a palavra que você quer tentar: ");
        fgets(tentativas, 50, stdin);
        
        // strcspn serve pra procurar um caractere em uma string
        // pega a posição do "\n" e coloca como 0 (final da string)
        tentativas[strcspn(tentativas, "\n")] = 0;

        // compara
        if (strcmp(tentativas, "Batata") == 0){
            printf("Você Ganhou!\n");
            break;
        } else {
            erros++;
        }
    }
    return 0;
}
