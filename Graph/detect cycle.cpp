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
bool dfs(vector<int> adj[],int s,bool visited[],int parent){
    visited[s]=true;
    for(auto u:adj[s]){
        if(visited[u]==false){
            if(dfs(adj,u,visited,s)==true)
                return true;
            else
                if(u!=parent)
                    return true;
        }
    }
    return false;
}
bool cdfs(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false)
            if(dfs(adj,i,visited,-1)==true)
                return true;
    }
    return false;
}
int main(){
    int v=4;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,3);
    //addedge(adj,2,3);
    print(adj,v);
    cout<<cdfs(adj,v);
    return 0;
}
