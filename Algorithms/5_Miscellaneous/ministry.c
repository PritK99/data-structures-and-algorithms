#include <stdio.h>

int q = 500;

void func(int **p)
{
    *p = &q;
}

int main ()
{
    int* p ;
    func(&p);
    printf("%d", *p);
    return 0;
}