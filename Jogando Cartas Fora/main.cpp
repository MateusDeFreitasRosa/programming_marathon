#include <bits/stdc++.h>

using namespace std;

struct card {

    int carta[50];
    int topo;
};

void iniciaCard(struct card *c) {
    (*c).topo = -1;
}

void push(struct card *c, int x) {
    if ((*c).topo != -1 || (*c).topo != 50) {
        (*c).topo++;
        (*c).carta[(*c).topo] = x;
    }
}

int pop(struct card *c) {
    if ((*c).topo != -1)
        return (*c).carta[(*c).topo--];
    else
        return 0;
}
int tamvetor(int v[]) {
    return sizeof(v);
}

int main()
{
    struct card cartas,cartasAux;
    iniciaCard(&cartas);
    iniciaCard(&cartasAux);
    int guarda,n = 1,segura,amazing[51],k;
    while (n != 0) {
        k=0;
        cin >> n;
        for (int i=n;i>0;i--) {
                push(&cartas,i);
            }
        do {
            amazing[k++] = pop(&cartas);
            guarda = pop(&cartas);
            if (cartas.topo != -1) {
                for (int i=cartas.topo;i>=0;i--) {
                    segura = pop(&cartas);
                    push(&cartasAux,segura);
                }
                push(&cartas,guarda);
                for (int i=cartasAux.topo;i>=0;i--) {
                    segura = pop(&cartasAux);
                    push(&cartas,segura);
                }
            }
        } while (cartas.topo != -1);
        if (n != 0) {
            cout << "Discarded cards: ";
            for (int i=0;i<k;i++) {
                if (i == 0)
                    cout << amazing[i] ;
                else
                    cout << ", " << amazing[i];
            }
            cout << endl << "Remaining card: " << guarda << endl;
        }
    }

    return 0;
}
