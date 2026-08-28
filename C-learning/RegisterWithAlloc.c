#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct user
{
    char *nickname;
    int id;
} User;


// o retorno é um ponteiro para User pq nós alocamos self com o malloc e o retorno de malloc é um endereço
User *createUser(char *name, int id)
{
    User *self = malloc(sizeof(User));

    self->id = id;
    self->nickname = malloc(strlen(name) + 1); // aloca o tamanho exato do nome

    strcpy(self->nickname, name); //copia o valor do argumento pro nickname

    return self;
}


int main()
{
    char escolha1[TAM];
    int escolha2;

    fgets(escolha1, sizeof(escolha1), stdin);
    scanf("%d", &escolha2);

    User *NewUser = createUser(escolha1, escolha2);

    printf("&s\n", NewUser->nickname);
    printf("%d\n", NewUser->id);

}
