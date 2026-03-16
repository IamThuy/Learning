#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 50

//structs

struct pessoa {
    int idade;
    float peso;
    char nome[TAM];
};
// redefinir esse "novo tipo" para n precisar ficar usando 
// "struct" toda hora no inicio da linha
typedef struct pessoa pessoa;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    /* muda a codepage pra evitar problemas de acentuação no windows
     mas isso faz com que o programa rode apenas no windows

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    */
    system("chcp 1252 > nul");

    // isso imprime o valor de "a" na tabela ASCII (97)

    /*    
    %c    caractere
    %p    endereço (ponteiro)
    %d    valor numérico (ASCII)
    */
    char sla = 'a';
    printf("%d\n", sla);
    // imprime o valor de "sla"
    printf("%c\n", sla);

    /*
     array:

    int a[3] = { 1, 2, 3 };
                     2
    printf("%d\n", a[1]);
    muda o indice
    a[0] = 1;
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    */

    int a[4] = { 1, 2, 3, 4 };
    //a[0] = 1;
    int size = 4;
    // printf("%d\n", a[0]);
    printf("valor float: %f\n", 12.42342342);
    printf("valor float com apenas duas casas: %.2f\n", 12.42342342);
    printf("valor decimal/int: %d\n", 12432);
    //printf("valor decimal/int: %i\n", 12432);
    printf("Uma unica letra (char): %c\n", 'a');
    printf("imprimir texto (string): %s\n", "Palavragrandelegal");


    int idade = 0;
    int ano = 0;
    printf("valor inicial da idade: %d\n", idade);

    printf("Digite um novo valor para a idade:\n");
    scanf("%d", &idade);
    printf("nova idade atribuida: %d\n", idade);

    /* Uma string em C naturalmente não são "nativas", aqui você
    você precisa fazer um array de caracteres pra emuular isso.
    */
    char stringrandom[50] = "sasasasasasasasasa";
        // struct parte 2
    
    pessoa pes = { 0, 0.0, "teste" };

    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("pes.nome: %s\n", pes.nome);
    // atribuindo valores
    pes.idade = 16;
    pes.peso = 30;
    strcpy(pes.nome, "Luís Arthur");

    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("pes.nome: %s\n", pes.nome);

    //atribuindo com o usuario
    printf("Idade: \n");
    scanf(" %d", &pes.idade);
    printf("Peso: \n");
    scanf(" %f", &pes.peso);
    printf("Nome: \n");
    fflush(stdin);
    scanf(" %50[^\n]", pes.nome);

    printf("%d %.2f %s\n", pes.idade, pes.peso, pes.nome);

    
    //  MATRIZ (array dentro de array)

    /*
    Aqui eu falo que o array vai ter mais 2 arrays dentro dele
    (matriz) e falo que cada matriz vai ter 3 espaços.
    
     arrays e espaços      */
    int mat[2][3];

    // mudo o primeiro numero do primeiro array:
    mat[0][0] = 1;
    printf("MATRIZES:\n");
    printf("valor da matriz: %d\n", mat[0][0]);
}