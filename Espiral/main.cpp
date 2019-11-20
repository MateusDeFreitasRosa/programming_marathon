#include <bits/stdc++.h>

using namespace std;

void PrintaTab(int linha, int coluna, int tam) {
    for(int i=0; i<tam; i++) {
        for (int j=0; j<tam; j++) {
            if (i == linha && j == coluna)
                cout << "X";
            else
                cout << "O";
        }
        cout << endl;
    }
    cout << "@" << endl;
}

void movimento(int *linha, int *coluna, int direcao,int p,int tam) {
    for(int i=0; i<p; i++) {
        if (direcao == 1)
            (*coluna)+=1;
        else if (direcao == 2)
            (*linha)-=1;
        else if (direcao == 3)
            (*coluna)-=1;
        else if(direcao == 4)
            (*linha)+=1;
        PrintaTab(*linha,*coluna,tam);
    }
}

int main()
{
    int tam,linha,coluna;

    do {
        cin >> tam;
        if (tam != 0) {
            linha = int(tam/2);
            coluna = int(tam/2);
            char matriz[tam][tam];

            int P = 1,qnt=0,direcao = 1;

            PrintaTab(linha,coluna,tam);


            while(linha != tam-1 || coluna != tam-1) {
                movimento(&linha, &coluna, direcao,P,tam);
                qnt++;
                direcao++;
                if(direcao > 4)
                    direcao=1;
                if (qnt == 2) {
                    qnt=0;
                    P++;
                }
                if (P >= tam)
                    P = tam-1;
                //cout << P << endl;
                //cout <<"Linha: " << linha << endl;
                //cout <<"Coluna: " << coluna << endl;
                //system("pause");
            }
        }
    }while(tam != 0);

    return 0;
}
