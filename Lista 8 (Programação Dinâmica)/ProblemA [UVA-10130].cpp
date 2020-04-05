#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;

int main () {
    int cases;
    cin>> cases;
    for (int i = 0; i < cases; i++) { //cada caso
        int objects;
        cin>> objects;
        int pnw[objects+1][2];
        for (int j = 1; j <= objects; j++) { //salvar p e w dos objetos
            cin>> pnw[j][0] >> pnw[j][1]; //price and weight
        }
      	int matriz[objects +1][31];
        
        for (int j = 0; j <= objects; j++) {
          	for (int k = 0; k <= 30; k++) {
              	if (j == 0 || k == 0) {
                	matriz[j][k] = 0;
                }
              	else if (pnw[j][1] <= k) {
                    matriz[j][k] = max(pnw[j][0] + matriz[j -1][k - pnw[j][1]], matriz[j -1][k]);   
                }
                else {
                    matriz[j][k] = matriz[j -1][k];
                }
            }
        }
        int total = 0;
        int people;
        cin>> people;
        for (int j = 0; j < people; j++) {
            int p;
            cin>>p;
            total += matriz[objects][p];
        }
        cout<< total<<pl;
    }
    return 0;
}