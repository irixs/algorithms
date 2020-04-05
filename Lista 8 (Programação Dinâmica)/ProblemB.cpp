#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;

int main () {
    string frase1;
    while (getline(cin, frase1)) {
        string frase2;
        getline(cin, frase2);
        
        int matriz[frase1.length() +1][frase2.length() +1];
        for (int i = 0; i <= frase1.length(); i++) {
            for (int j = 0; j <= frase2.length(); j++) {
                if (i == 0 || j == 0) {
                    matriz[i][j] = 0;
                }
                else if (frase1[i -1] == frase2[j -1]) {
                    matriz[i][j] = matriz[i -1][j -1] +1;
                }
                else {
                    matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
                }
            }
        }
        cout<< matriz[frase1.length()][frase2.length()]<< pl;
    }
    return 0;
}