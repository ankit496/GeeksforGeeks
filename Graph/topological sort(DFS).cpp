#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}
void print(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj[i]);
    }
}
stack<int> st;
void dfs(vector<int> adj[],bool visited[],int u){
    visited[u]=true;
    for(auto x:adj[u]){
        if(visited[x]==false)
            dfs(adj,visited,x);
    }
    st.push(u);
}
void topological_sort(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    for(int i=0;i<v;i++){
        if(visited[i]==false)
            dfs(adj,visited,i);
    }
    while(st.empty()==false){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,2,4);
    print(adj,v);
    topological_sort(adj,v);
    return 0;
}
