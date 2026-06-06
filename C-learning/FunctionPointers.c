#include <stdio.h>

int sla(int a, int b){
    int z = a + b;
    return z;
}


int main()
{
    int (*p)(int, int);

    p = sla;

    printf("%d", p(1, 1));
    return 0;
}
