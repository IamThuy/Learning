#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define TAM 50



void msg() {
    char sla[TAM] = "Texto legaaaaaaal";
    int tamanho = strlen(sla);

    // "033" é um caractere especial chamado "ESC"
    // ele só serve para avisar que o que vai vir a seguir 
    // é um comando especial 
    // [33 significa a cor amarela e o "m" significa 
    // mude o estilo/cor do texto
    printf("\033[33m");

    for (int i = 0; i < tamanho; i++) {
        printf("%c", sla[i]);
        fflush(stdout);
        Sleep(150);
    }

    printf("\033[0m");

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ".UTF-8");
    
    msg();
    return 0;
}