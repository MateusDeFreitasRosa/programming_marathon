#include <bits/stdc++.h>

using namespace std;

int main ()
{

    char expressao[10010],expressaoAux[10010];
    int i,j,a,k;
    bool confirmacao;
    while (cin >> expressao)
    {
        confirmacao = true;
        while (expressao[0] != '\0')
        {
            i=0;
            while (expressao[i] != ')' && expressao[i] != '(' && expressao[i] != '\0' )
            {
                i++;
            }
            if (expressao[i] == ')')
            {
                confirmacao = false;
                expressao[0] = '\0';
            }
            else if (expressao[i] == '\0') {
                confirmacao = true;
                expressao[0] = '\0';
            }
            else
            {
                j = 0;
                while (expressao[i] != '\0')
                {
                    expressao[j] = expressao[i];
                    j++;
                    i++;
                }
                expressao[j] = '\0';
                i=0;
                k = -1;
                while (expressao[i] != ')' && expressao[i] != '\0')
                {
                    if (expressao[i] == '(')
                        k = i;
                    i++;
                }
                if (k == -1 )
                {
                    confirmacao = false;
                    expressao[0] = '\0';
                }
                else if (k != -1 && expressao[i] != ')')
                {
                    confirmacao = false;
                    expressao[0] = '\0';
                }
                else
                {
                    j=0;
                    a=0;
                    while (expressao[j] != '\0')
                    {
                        if (j < k || j > i)
                        {
                            expressaoAux[a] = expressao[j];
                            a++;
                        }
                        j++;
                    }
                    expressaoAux[a] = '\0';
                    j=0;
                    while (expressaoAux[j] != '\0') {
                        expressao[j] = expressaoAux[j];
                        j++;
                    }
                    expressao[j] = '\0';
                }
            }

        }
        if (confirmacao == true)
            cout << "correct" << endl;
        else
            cout << "incorrect" << endl;
    }

}
