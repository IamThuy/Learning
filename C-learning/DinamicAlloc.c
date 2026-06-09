#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*
    Com alocação dinamica de memória
    ela me permite reservar memória durante a
    execução do programa
    */


    //reseva uma quantidade de memória 

    int *numero = malloc(sizeof(int));


    // se n fizer isso, o valor vai ser o antigo ue estava na memória
    *numero = 2;

    printf("%d\n", *numero);

    free(numero); //libera recursos
    
    // agora, com calloc nós podemos reservar e
    // inicializar o valor colocando o valor como 0


                // definimos 5 instâncias (o mesmo tamanho para 5 ints)
    int *numero2 = calloc(5, sizeof(int));

    *numero2 = 67;

    printf("%d\n", *numero2);

    free(numero2);

    // Alocação da memória pode retornar valores como "null" se der errado na alocação

    /*
        Imagine que você criou um vetor com 5 espaços para int com malloc ou calloc,
        mas depois percebe que precisaria de mais epaço. Então você usa realloc

        int *vetor = malloc(3 * sizeof(int));
        vetor = realloc(vetor, 5 * sizeof(int));
    */


}
