#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int l;
    int distancia, atualMD;
    string rua;
    char anterior;
    while (cin>>l) {
        distancia = 0;
        atualMD = 2000001;
        anterior = '~';
        if (l == 0) {
            break;
        }
        cin>>rua;
        for (int w = 0; w < l; w++) {
            if (rua[w] == 'R' || rua[w] == 'D') {
                if (anterior == '~') {
                    anterior = rua[w];
                    distancia = 0;
                }
                else if (anterior == rua[w]) {
                    distancia = 0;
                }
                else {
                    if (distancia < atualMD) {
                        atualMD = distancia;
                    }
                    anterior = rua[w];
                    distancia = 0;
                }
            }
            else if (rua[w] == 'Z') {
                atualMD = 0;
                w = l;
            }
            distancia++;
        }
        cout << atualMD << endl;
    }
    return 0;
}