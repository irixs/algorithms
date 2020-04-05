#include<bits/stdc++.h>
using namespace std;

void dfs(int v, bool vis[], vector<int> grafo[]){
	vis[v]=1;
	for(int i=0;i<grafo[v].size();i++){
		int prox = grafo[v][i];
		if(vis[prox]==0){
			dfs(prox, vis,grafo);
		} 
	}
}
int main(){
	int t,n,m;
	cin>>t;
	for (int i = 0; i < t; i++) {
			
			cin>>n>>m;
			vector<int> grafo[n+1];
			bool vis[n+1];
			for(int k=0;k<n+1;k++){
				vis[k]=0;
			}

			for(int j=0;j<m;j++){
				int a,b;
				cin>>a>>b;
				grafo[a].push_back(b);	
			}
			
			stack<int> k;
			for(int v=1; v<=n;v++){
				if(vis[v]==0){
					dfs(v,vis,grafo);
					k.push(v);
				}
			}
			for(int p=0;p<n+1;p++){
				vis[p]=0;
			}

			int cont = 0;
			while(k.size()>0){
				int v = k.top();
				k.pop();
				if(vis[v]==0){
					cont++;
					dfs(v,vis,grafo);
				}
			}

			cout<<cont<<endl;
	}
}