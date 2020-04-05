#include <bits/stdc++.h>
using namespace std;


void merge (int array[], int aux[], int l, int m, int r) {
    int i, j, k;
    i = l;
    j = m +1;
    k = l;
    
    while (i <= m && j <= r) {
        if (abs(array[i]) < abs(array[j])) {
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
int main() {
    int cases, qt;
    cin>>cases;

    for (int y = 0; y < cases; y++) {
        
        cin>>qt;
        int array[qt], aux[qt];
        bool signal = true;
        int count;

        for (int q = 0; q < qt; q++) {
            cin>> array[q];
        }
        mergesort(array, aux, 0, qt-1);
       
        for (int t = 0; t < qt; t++) {

            if (array[t] >= 0) {

                if (signal) {
                    count++;
                }
                if(array[t+1] >= 0) {
                    signal = false;
                }
                else {
                    signal = true;
                }
            }
            else {
                if (signal) {
                    count++;
                }
                if(array[t+1] < 0) {
                    signal = false;
                }
                else {
                    signal = true;
                }
            }
        }
        cout << count<< endl;
        count = 0;
    }
    return 0;
}
