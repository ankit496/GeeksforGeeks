#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void shortest_path(vector<int> adj[],int v,int s){
    queue<int> q;
    q.push(s);
    int dist[v];
    dist[0]=0;
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    visited[s]=true;
    while(q.empty()==false){
        int path_length=0;
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
                dist[v]=dist[u]+1;//distance of that node=distance of previous adjacent node+1;
            }
        }
    }
    for(int i:dist)
        cout<<i<<" ";
}
int main(){
    int v=4;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    print(adj,v);
    shortest_path(adj,v,0);
    return 0;
}
