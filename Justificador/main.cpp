#include <bits/stdc++.h>
using namespace std;

string espaco(int n,int comp)
{
    string sp;

    for (int i=0; i<n-comp; i++)
    {
        sp +=" ";
    }
    return sp;
}

int main() {

    vector<string> nomes;
    int casos,big;
    int k=0;
    string n;
    do
    {
        cin >> casos;
        if (casos != 0)
        {

            big = 0;
            for (int j=0; j<casos; j++)
            {
                cin >> n;
                nomes.push_back(n);
                if (n.size() > big)
                    big = n.size();
            }
            if (k> 0)
                cout << endl;
            for(int j=0; j<casos; j++)
            {
                cout << espaco(big,nomes.at(j).size()) << nomes.at(j) << endl;
            }
            nomes.clear();
            k++;
        }
    }while(casos != 0);

    return 0;
}
