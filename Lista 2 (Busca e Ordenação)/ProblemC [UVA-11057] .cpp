#include <bits/stdc++.h>
using namespace std;


void merge (int array[], int aux[], int l, int m, int r) {
    int i, j, k;
    i = l;
    j = m +1;
    k = l;
    
    while (i <= m && j <= r) {
        if (array[i] < array[j]) {
            aux[k] = array[i];
            i++;
        }
        else {
            aux[k] = array [j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        aux[k] = array[i];
        i++;
        k++;
    }
    while (j <= r) {
        aux[k] = array[j];
        j++;
        k++;
    }
    for (int a = l; a <= r; a++) {
        array[a] = aux[a];
    }
}
void mergesort( int array[], int aux[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergesort(array, aux, l, m);
        mergesort(array, aux, m+1, r);
        merge(array, aux, l, m , r);
    }
}
int main () {
    int tA;
    int cont = 0;
    while (cin>> tA) {
        int array[tA];
        int aux[tA];

        for (int b = 0; b < tA; b++) {
                cin>>array[b];
        }
        mergesort(array, aux, 0, tA-1);
        int taokeis;
        cin>> taokeis;
        int i;
        int j;

        for (int c = 0; c < tA; c++) {

            if (taokeis-array[c] >= array[c]) {
                int aux = taokeis - array[c];
                int l = c+1;
                int r = tA-1;
                    
                while (r-l > 1) {
                    //cout<<"A";
                    int m = (l + r)/2;
                    if (aux == array[m]) {
                        //cout<<"ACHOUU";
                        i = array[c];
                        j = aux;
                        break;
                    }
                    else if (aux < array[m]) {
                        r = m ;
                    }
                    else {
                        l = m ;
                    }
                }
                if (array[l] == aux || array[r] == aux ) {
                    i = array[c];
                    j = aux;
                }

            }
            else {
                c = tA;
            }
        }
       
        cout << "Peter should buy books whose prices are "<< i <<" and "<< j <<"."<< endl;     
            cout << endl;
        cont++;
    }
    return 0;
}