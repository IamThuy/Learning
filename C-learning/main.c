#include<stdio.h>

int main()
{
    int x = 0;
    int *p = &x;
    printf("X: %p\n", &x);
    printf("P: %p\n", p);
    printf("valor P: %d\n", *p);
    return 0;
}
