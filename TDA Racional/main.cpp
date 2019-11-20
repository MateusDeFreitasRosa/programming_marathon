#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,N1,N2,D1,D2,n3,d3;
    char b1,b2,sinal;


    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> N1;
        cin >> b1;
        cin >> D1;
        cin >> sinal;
        cin >> N2;
        cin >> b2;
        cin >> D2;

        if (sinal == '+') {
            n3 = (N1*D2 + N2*D1);
            d3 = (D1*D2);
        }
        else if (sinal == '-') {
            n3 = (N1*D2 - N2*D1);
            d3 = (D1*D2);
        }
        else if (sinal == '*') {
            n3 = (N1*N2);
            d3 = (D1*D2);
        }
        else if (sinal == '/') {
            n3 = (N1*D2);
            d3 = (N2*D1);
        }
        cout << n3 << "/" << d3 << " = ";
        for (int k=2; k<=abs(n3); k++) {
            if (n3%k == 0) {
                if (d3%k == 0) {
                    d3 = d3/k;
                    n3 = n3/k;
                    k--;
                }
            }
        }
        cout << n3 << "/" << d3 << endl;
    }
    return 0;
}
