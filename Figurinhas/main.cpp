#include <bits/stdc++.h>

using namespace std;

int main()
{
    int caso;
    int n1,n2;
    int r;
    int mmc;

    cin >> caso;

    for (int i=0; i<caso; i++) {
        cin >> n1 >> n2;

        if (n1 < n2) {
            r = n1;
            n1 = n2;
            n2 = r;
        }
        do {
            r = n1%n2;
            mmc = n2;
            n1 = n2;
            n2 = r;
        }while (r != 0);
        cout << mmc << endl;
    }
    return 0;
}
