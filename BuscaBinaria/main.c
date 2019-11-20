#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int busca, int v[],int n) {
    int right = n-1,left = 0;
    int middle;

    if (busca < left || busca > right)
        return -1;

    while (v[right] != busca) {
        middle = (right+left)/2;
        if (busca <= v[middle])
            right = middle;
        else if (busca > v[middle])
            left = middle;
    }
    return right;
}

int main()
{
    int n, tam=10;
    int v[tam];
    int i;
    for(i=0; i<tam; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &n);
    printf("Where are number in array? It's in -> : %d", BuscaBinaria(n, v, tam));


    return 0;
}
