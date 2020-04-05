#include<bits/stdc++.h>
using namespace std;
const int mod = 10000;
int main() {
    int l, u, r;
    bool loop = true;
    int cont = 0;

    while (cin>>l>>u>>r && loop) {
        if (l == 0 && u == 0 && r == 0) {
            loop = false;
        }
        else {
            int array[r];
            for (int i = 0; i< r; i++) {
                cin>>array[i];
            }
            int distancia[mod];
            for (int y = 0; y < mod; y++) {
                distancia[y] = -1;
            } 
            distancia[l] = 0;
            queue<int> fila;
            fila.push(l);

            while(!fila.empty()) {
                int pai = fila.front();
                fila.pop();
                for (int m = 0; m < r; m++) {
                    int filho = (pai + array[m])% mod;
                    if (distancia[filho] == -1) {
                        distancia[filho] = distancia[pai] + 1;
                        fila.push(filho);
                    }
                }
            }
            cont++;
            if (distancia[u] != -1) {
                cout<< "Case "<< cont <<": "<< distancia[u] <<endl;
            }
            else {
                cout<< "Case "<< cont <<": Permanently Locked" << endl;
            }
        }
    }
    return 0;
}