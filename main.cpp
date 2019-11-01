#include <bits/stdc++.h>
//letter (A-Z)
using namespace std;

string encrypt(string phrase, int key) {
    for(int i=0; i<phrase.size() ; i++) {
        if (isalpha(phrase[i]))
            phrase[i] = (((phrase[i]-65)+key)%26)+65;
    }
    return phrase;
}

int main()
{
    string phrase, r;
    int key;

    getline(cin, phrase);
    cin >> key;

    cout << encrypt(phrase, key) << endl;
    return 0;
}
