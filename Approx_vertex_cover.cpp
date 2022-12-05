#include<bits/stdc++.h>
using namespace std;

void printVertexCover(vector<vector<int>> &adj){

    int V = adj.size();
    vector<bool> visited(V,false);

    for(int u = 0; u < V; u++){
        if(!visited[u]){
            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < V; i++){
        if(visited[i]){
            cout << i << " ";
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n,e;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    for(int i = 0; i < e; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printVertexCover(adj);
    adj.clear();

}