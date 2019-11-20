#include <iostream>

using namespace std;

int main()
{
    int c,n;
    string model1,model2,frase;
    char primary;
        while(cin >> c >> n ) {
            cin.ignore();
            getline(cin,model1);
            getline(cin,model2);
            for (int l=0; l<n; l++) {
                getline(cin,frase);
                primary = frase[0];
                for (int i=0; i<frase.size(); i++) {
                    for (int j=0; j<c; j++) {
                        if (tolower(frase[i]) == tolower(model1[j])) {
                            if (isupper(frase[i]))
                                frase[i] = toupper(model2[j]);
                            else
                                frase[i] = tolower(model2[j]);
                            break;
                        }
                        else if (tolower(frase[i]) == tolower(model2[j])) {
                            if (isupper(frase[i]))
                                frase[i] = toupper(model1[j]);
                            else
                                frase[i] = tolower(model1[j]);
                            break;
                        }
                    }
                }
            if (isupper(primary))
                frase[0] = toupper(frase[0]);
            cout << frase << endl;
        }
        cout << endl;
    }
    return 0;
}
