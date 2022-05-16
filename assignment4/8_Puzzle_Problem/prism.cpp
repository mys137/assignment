#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>m>>n;
    vector<pair<int,int>> adj[n];

    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }

    int parent[n];
    bool mst[n];
    int key[n];

    memset(mst,false,sizeof(mst));
    memset(key,INT_MAX,sizeof(key));
    memset(parent,-1,sizeof(parent));

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        int u = temp.second;

        mst[u]=true;

        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
                pq.push({key[v],v});
            }
        }
    }

    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }


    return 0;
}