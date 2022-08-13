#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[]){
    for(int i=0;i<7;i++){
        for(auto x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void bfs(vector<int> adj[],int v,int s,bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void bfsDis(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    int noc=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            visited[i]=true;
            noc++;
            bfs(adj,v,i,visited);
        }
    }
    cout<<endl<<noc;//no of connected components
}
int main(){
    int v=7;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,4,5);
    addedge(adj,4,6);
    addedge(adj,5,6);
    print(adj);
    bfsDis(adj,v);
    return 0;
}
