// N nodi
// M archi
// P partenza
// quanti nodi non sono raggiungibili?

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define MAXN 30

using namespace std;

int N, M;
vector<vector<int> > gr;
int padri[MAXN][2];
bool vis[MAXN][2];

void dfs(int nodo, int stato, int padre){
    vis[nodo][stato] = true;
    padri[nodo][stato] = padre;

    for(int u : gr[nodo]){
        int nstato = 1-stato;
        if(!vis[u][nstato]){
            dfs(u, nstato, nodo);
        }
    }
}

void stampa_cammino(int nodo, int stato, int lun){
    if(padri[nodo][stato] != -1){
        stampa_cammino(padri[nodo][stato], 1-stato, lun+1);
    } else{
        cout<<lun<<endl;
    }
    cout<< nodo << " ";
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> N >> M;
    gr.resize(N);

    for(int i=0,da,a;i<M;i++){
        cin>>da>>a;
        gr[da].push_back(a);
        gr[a].push_back(da);
    }

    //0 bleah, 1 slurp
    dfs(0, 0, -1);

    stampa_cammino(0, 1, 0);
    cout<<endl;
    return 0;
}
