#include <bits/stdc++.h>
using namespace std;

typedef struct  {
    int v1,v2;
}arestas;

typedef struct {
    int ant;
    int distancia;
    char cor;
}positions;


int criaLigacoes(arestas a[], positions p[][100]) {
    int k=0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            //Verificação vertical.
                //Para cima a direita.
            if (i > 1 && j < 7) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i-2)*10) + (j+1);
            }
                //Para cima a esquerda;
            if (i > 1 && j > 0 ) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i-2)*10) + (j-1);
            }
                //para baixo a direita.
            if (i < 6 && j < 7) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i+2)*10) + (j+1);
            }
                //para baixo a esquerda.
            if (i < 6 && j > 0) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i+2)*10) + (j-1);
            }

            //Verificação da horizontal.
                //para direita a cima.
            if (j < 6 && i > 0) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i-1)*10) + (j+2);
            }

                //para direita a baixo.
            if (j < 6 && i < 7) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i+1)*10) + (j+2);
            }

                //para esquerda a cima.
            if (j > 1 && i > 0) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i-1)*10) + (j-2);
            }
                //para esquerda a baixo
            if (j > 1 && i < 7) {
                a[k].v1 = (i*10) + j;

                a[k++].v2 = ((i+1)*10) + (j-2);
            }
        }
    }
    return k;
}

int WhereThrow(char a) {
    return (int) (a%97);
}


void mov_Cav(arestas a[], positions p[][100], string inicio, string fim, int tam) {

    for(int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            p[i][j].distancia = 0;
            p[i][j].cor = 'B';
        }
    }
    bool quit = false;
    queue<int> fila;


    int beginn,ennd;
    beginn = (int) ((inicio[1]-'0'-1)*10) + (WhereThrow(inicio[0]));
    ennd = (int) ((fim[1] -'0'-1)*10) + ( WhereThrow(fim[0]));
    int aux;

    fila.push(beginn);

    p[ fila.front()/10 ][ fila.front()%10 ].cor = 'C';

    while (fila.empty() == false && quit == false) {
        aux = fila.front();
        for(int i=0; i<tam; i++) {
            if (aux == a[i].v1) {
                if (p[ (a[i].v2/10) ][ (a[i].v2%10) ].cor == 'B') {
                    p[ (a[i].v2/10) ][ (a[i].v2%10) ].cor = 'C';
                    p[ (a[i].v2/10) ][ (a[i].v2%10) ].ant = aux;
                    p[ (a[i].v2/10) ][ (a[i].v2%10) ].distancia = p[aux/10][aux%10].distancia +1;
                    fila.push(a[i].v2);
                }
            }
        }
        p[(fila.front()/10)][(fila.front()%10)].cor = 'P';
        fila.pop();
        if (p[(ennd/10)][(ennd%10)].cor != 'B')
            quit = true;
    }

    cout << "To get from " << inicio << " to "<< fim << " takes " << p[(ennd/10)][(ennd%10)].distancia << " knight moves." << endl;
}

int main()
{
    arestas ar[10000];
    positions p[100][100];
    string inicio, fim;
    int tam = criaLigacoes(ar,p);

    while (cin >> inicio >>fim) {
        mov_Cav(ar,p,inicio,fim,tam);
    }
    return 0;
}
