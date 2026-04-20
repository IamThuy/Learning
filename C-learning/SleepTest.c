#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define TAM 50
int main()
{
    setlocale(LC_ALL, ".UTF8");
    char message[TAM];
    printf("Digite algo: ");
    // use caso queira detectar espaços
    fgets(message, TAM, stdin);

    for (int i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
        Sleep(100);
    }
}
