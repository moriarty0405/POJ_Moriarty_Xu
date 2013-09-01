#include <stdio.h>
#include <stdlib.h>

struct Node
{
    double data;
    int other;
}s[100];

int Comp(const void *p1,const void *p2)
{
    return ((Node *)p2)->data - ((Node *)p1)->data;
}

int main(void)
{
    puts("≈≈–Ú«∞£∫");
    //code
    printf("\n");

    qsort(s, 100, sizeof(s[0]), Comp);
    system("pause");

    puts("≈≈–Ú∫Û£∫");
    //code
    printf("\n");

    return 0;
}
