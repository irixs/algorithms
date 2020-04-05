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
    cin>>tA;
    int array[tA];
    int aux[tA];

    for (int b = 0; b < tA; b++) {
        cin>>array[b];
    }
    mergesort(array, aux, 0, tA-1);

    if (tA % 2 == 0) {
        for (int t = 0; t < tA; t += 2) {
            cout << array[t] << " ";
        }
        for (int o = tA - 1; o >= 0; o -= 2) {
            cout << array[o] << " ";
        }
    }
    else {
        for (int t = 0; t < tA; t += 2) {
            cout << array[t] << " ";
        }
        for (int o = tA - 2; o >= 0; o -= 2) {
            cout << array[o] << " ";
        }
    }
    return 0;
}