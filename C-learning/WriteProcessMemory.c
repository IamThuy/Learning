#include <windows.h>
#include <stdio.h>

int main() {
    // Todos esses tipos são na verdade tipos existentes com apelidos via typedef.
    DWORD pid = ""; //DWORD é um unsigned 32-bit (long) inteiro definido pela API do Windows
                    // Ou seja, unsigned = apenas números positivos.
    
    // o "FALSE" diz que esse handle não ver ser herdado por processos filhos desse programa.
    HANDLE HProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); /*HANDLE é uma referência opaca para um objeto do kernel
     (como uma chave de acesso) que serve para acessar Threads, arquivos, etc.*/

     if (HProcess == NULL){
        printf("Null Process");
     }

     int CrackedValue = 999;

     // LPVOID é um tipo para ponteiros genéricos
     LPVOID endereco = (LPVOID)0x0; // Ponteiro da variavel que deseja mudar

     if (WriteProcessMemory(HProcess,
         endereco, // onde vamos escrever
         &CrackedValue, // Endereço do que vamos escrever
         sizeof(CrackedValue), NULL) // quantos Bytes eu quero copiar da minha variavel
         // Nesse caso, sizeof diz o valor que ela ocupa na memória, ou seja, queremos copiar o tamanho da propria variavel
        )
     {
        printf("Valor alterado");
     } else {
        printf("Erro ao escrever na memória");
     }

     CloseHandle(HProcess); // fechar o handle para liberar recursos do sistema.
}