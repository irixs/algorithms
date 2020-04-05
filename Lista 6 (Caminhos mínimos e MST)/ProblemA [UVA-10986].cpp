#include<bits/stdc++.h>
using namespace std;

int d (int distancia[], vector<pair<int,int>> grafo[], int s, int t) {
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    minheap.push( {0,s} );
	while(minheap.size()){
		pair<int, int> aux = minheap.top(); 
        minheap.pop();

		int u = aux.second;

		for(auto child : grafo[u]) {
			int w = child.first, v = child.second;
				
			if (distancia[u] + w < distancia[v]) {            
				distancia[v] = distancia[u] + w;
				minheap.push( {distancia[v],v} );
			}
		}
	}
	return distancia[t];
}

int main () {
    int nn;
    cin>>nn; //n de casos
    for (int i = 0; i < nn; i++) { //cada caso
        int n, m, s, t;
        cin>> n>> m>> s>> t;
        //criar o grafo
        vector<pair<int,int>> grafo[n];
        int distancia[n];
        for(int e = 0; e < n; e++) {
            distancia[e] = INT_MAX;
        }
        distancia[s] = 0;

        for(int e = 0; e < m; e++) { 
            int serve1, serve2, peso;
            cin>> serve1 >>serve2 >>peso;
            grafo[serve1].push_back({peso, serve2});
            grafo[serve2].push_back({peso, serve1});
        }
        int dst = d(distancia, grafo, s, t);

        if(dst == INT_MAX) {
            cout << "Case #"<<i+1 <<": unreachable"<< endl;
        }
        else {
            cout << "Case #"<<i+1 <<": "<< dst<< endl;
        }
    }
    return 0;
}