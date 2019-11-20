#include <bits/stdc++.h>
using namespace std;

int fibbonaci(int x) {
    int firt = 0, second = 1,aux;
    if (x == 0)
        second = 0;
    for (int i=1; i<x; i++) {
        aux = second;
        second += firt;
        firt = aux;
        second%=1000;
    }
    return second;
}


int main () {
    char number[10100];
    int casos;
    cin >> casos;

    for (int i=0; i<casos; i++) {
        cin >> number;
        int ciclo = 1500;
        int ans = 0;
        for (int j = 0; j < strlen(number); j++) {
            ans *= 2;
            ans += (number[j] - '0');
            ans %= ciclo;
        }
        ans = fibbonaci(ans);
        if (ans<10) {
            cout << "00"<< ans << endl;
        }
        else if (ans>=10 && ans<100) {
            cout << "0"<< ans << endl;
        }
        else {
            cout <<ans << endl;
        }
    }
    return 0;
}
