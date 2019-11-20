#include <bits/stdc++.h>
using namespace std;

bool PrimoMaisRapido(int n) {
    if (n > 3) {
        if (n%2 == 0)
            return true;
        else {
            for (int i=3; i<=sqrt(n); i+=2) {
                if (n%i == 0)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int c,n;
    clock_t timeI;
    cin >> c;
    for (int i=0; i<c; i++) {
        cin >> n;
        timeI = clock();
        if (PrimoMaisRapido(n))
            cout << "Not Prime\n";
        else
            cout << "Prime\n";
        cout << "Time: Crivo." << (double)(clock() - timeI) *1000 / CLOCKS_PER_SEC << " ms." << endl;
    }

    return 0;
}
