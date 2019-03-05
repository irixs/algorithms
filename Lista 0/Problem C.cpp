#include <bits/stdc++.h>
using namespace std;

//questao c
int main () {
    string t, s;
    cin >> t >> s;
    int vt = t.length(), vs = s.length(), aux = min(vt, vs);
    for (;aux > 0; aux--) {
        if (t[vt-1] != s[vs-1]) {
            aux = 0;
        }
        else {
            vt--;
            vs--;
        }
    }
    cout << vt + vs;
    return 0;
}