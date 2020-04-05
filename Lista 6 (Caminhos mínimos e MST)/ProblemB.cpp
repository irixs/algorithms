#include<bits/stdc++.h>
using namespace std;
int ds[10001];
void makeset(){
	for(int i=0;i<10001;i++){ ds[i]=i;}//ds[u] = conjunto ao qual u pertence
}

int find(int i){//find
	if(ds[i]==i) return i;
	return ds[i]=find(ds[i]);
}

void uni(int a, int b){//union
	int x=find(a), y=find(b);
	ds[x]=y;
}

int main () {
	int t;
	cin>>t; //n de casos
	for (int i = 0; i < t; i++) { //cada caso
		int n, m, a;
		cin>> n>> m>> a;
		makeset();
		//criar o grafo   {int, {int,int}}
		vector<pair<int,pair<int,int>>> listaArestas;

		for(int e = 0; e < m; e++) { 
			int city1, city2, peso;
			cin>> city1 >>city2 >>peso;
			listaArestas.push_back({peso,{city1,city2}});
		}
		sort(listaArestas.begin(),listaArestas.end());
		int custo=0, numAero=0;

		for(auto aresta : listaArestas){
			int peso = aresta.first, v1 = aresta.second.first, v2= aresta.second.second;
			int x=find(v1), y=find(v2);
			if(x==y) continue;

			if(peso < a){
				custo+=peso;
				uni(v1,v2);
			}          

		}
		set<int> aer;
		for(int j=1;j<=n;j++){
			aer.insert(find(j));
		}
		numAero =  aer.size();
		custo+=a*numAero;


		cout << "Case #"<<i+1 <<": "<<custo<<' '<<numAero<< endl;
	}
	return 0;
}	