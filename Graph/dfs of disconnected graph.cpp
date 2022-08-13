#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> adj[],bool visited[],int s){
        visited[s]=true;
        cout<<s<<" ";
        for(auto x:adj[s])
            if(visited[s]==false)
                print(adj,visited,x);
}
void DFS(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false)
            print(adj,visited,i);
    }
}
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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

    cout<<endl;
    DFS(adj,v);
    return 0;
}
