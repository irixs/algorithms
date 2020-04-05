#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;

int contRespostas = 1;

bool safe(int tabela[][10], int l, int c){
    //confere a linha
    for(int m = 1; m < 9; m++) {
        if (m != c) {
            if (tabela[l][m] == 1) {
                return false;
            }
        }
    }
    //confere a coluna
    for(int m = 1; m < 9; m++) {
        if (m != l) {
            if (tabela[m][c] == 1) {
                return false;
            }
        }
    }
    //confere a diagonal esquerda pra cima
    int ll = l -1;
    int cc = c -1;
    while (ll>=1 && cc>=1){
        if (tabela[ll][cc] == 1) {
            return false;
        }
        ll--;
        cc--;
    }
    //confere a diagonal esquerda pra baixo
    ll = l +1;
    cc = c -1;
    while (ll<=8 && cc>=1){
        if (tabela[ll][cc] == 1) {
            return false;
        }
        ll++;
        cc--;
    }
    //confere a diagonal direita pra cima
    ll = l -1;
    cc = c +1;
    while (ll>=1 && cc<=8){
        if (tabela[ll][cc] == 1) {
            return false;
        }
        ll--;
        cc++;
    }
    //confere a diagonal direita pra baixo
    ll = l +1;
    cc = c +1;
    while (ll<=8 && cc<=8){
        if (tabela[ll][cc] == 1) {
            return false;
        }
        ll++;
        cc++;
    }
	return true;
}

void bt(int linha, int coluna, int tabuleiro[][10], int respostas[], int poscoluna){
	
    if (poscoluna == 9){
		//tenho solucao
		if (contRespostas > 9) {
		    cout<< contRespostas<< "      ";
		}
		else {
		    cout<< " "<< contRespostas<< "      ";
		}
		contRespostas++;
		
        for (int y = 1; y <= 8; y++) {
            if (y == 8) {
                cout<< respostas[y];
            }
            else{
                cout<< respostas[y]<< sp;
            }
        }
        cout<<pl;
	}
    else {
        if (coluna == poscoluna) { //coluna marcada
            bt(linha, coluna, tabuleiro, respostas, poscoluna+1);//bt do proximo
        }
        else {
            for (int u = 1; u < 9; u++){ //acessando as linhas de poscoluna
		        if (safe(tabuleiro, u, poscoluna)){ //tenta colocar em uma posição
			        respostas[poscoluna] = u; //salvou a rainha
                    tabuleiro[u][poscoluna] = 1; //linha que não entra em xeque

			        bt(linha, coluna, tabuleiro, respostas, poscoluna+1); //bt pra proxima coluna

			        respostas[poscoluna] = 0; //tira rainha
                    tabuleiro[u][poscoluna] = 0;
		        }
	        }
        }
    }
}

int main() {
    int casos;
    cin>> casos;
    for (int i = 0; i < casos; i++) {//rodar todos os casos
        int linha, coluna;
        int contcoluna = 1;
        cin>> linha>> coluna;
        int respostas[8];
        for (int y = 1; y <= 8; y++) {
            respostas[y] = 0;
        }
        
        int tabuleiro[10][10];
        for (int y = 1; y <= 8; y++) {
            for (int f = 1; f <= 8; f++) {
                tabuleiro[y][f] = 0;
            }
        }
        tabuleiro[linha][coluna] = 1; //marcada por padrão
        respostas[coluna] = linha;
        int poscoluna = 1;
        
        cout<< "SOLN       COLUMN"<<pl;
        cout<<" #      1 2 3 4 5 6 7 8"<<pl<<pl;
        
        bt(linha, coluna, tabuleiro, respostas, poscoluna);
        
        if (i != casos -1) {
            cout<<pl;
        }
      	contRespostas = 1;
    }
    //printf(" ");
    return 0;
}