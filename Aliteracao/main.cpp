#include <bits/stdc++.h>
using namespace std;

int main() {

    string frase;
    int cont;
    char ant,prox;
    bool add;
    while (getline(cin,frase)) {
        ant = frase[0];
        add = false;
        cont++;
        for (int i=1; i<frase.size(), i++)
        {
            if (frase[i] == ' ' && i+1 < frase.size())
                prox = frase[i];
            if (add == true)
            {
                cont++;
            }
            else if (add == false && prox)
        }
    }

    return 0;
}
