#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int graos;
    int passos,casos;

    cin >> casos;

    for (int i=0; i<casos; i++) {
        cin >> passos;
        if (passos < 64) {
        for (int j=1; j<=passos+1; j++) {
            if (j==1)
                graos = 1;
            else
                graos = 2*graos;
        }
        graos = (graos/12)/1000;

        cout << graos << " kg" << endl;
        }
        else if (passos == 64)
            cout << "1537228672809129" << " kg" << endl;
    }



    return 0;
}
