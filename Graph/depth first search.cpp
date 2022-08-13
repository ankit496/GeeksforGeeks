#include<iostream>
#include<vector>
#include<stack>
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
void dfs(vector<int> adj[],int v,int s){
    stack<int> st;
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    st.push(s);
    visited[s]=true;
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
        for(auto x:adj[u]){
            if(visited[x]==false){
                visited[x]=true;
                st.push(x);
            }
        }
    }
}

void DFS(vector<int> adj[],bool visited[],int s){
    if(visited[s]==true)
        return;
    else{
        visited[s]=true;
        cout<<s<<" ";
        for(auto x:adj[s])
            DFS(adj,visited,x);
    }
}
int main(){
    int v=7;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,4,5);
    addedge(adj,4,6);
    addedge(adj,5,6);
    bool visited[7];
    for(int i=0;i<7;i++){
        visited[i]=false;
    }
    dfs(adj,v,0);
    cout<<endl;
    DFS(adj,visited,0);
    return 0;
}
