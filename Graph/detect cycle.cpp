#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
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
bool dfsrec(vector<int> adj[],int s,int parent,bool visited[]){
        visited[s]=true;
        for(int u:adj[s]){
            if(visited[u]==false){
                if(dfsrec(adj,u,s,visited))
                    return true;
            }
            else if(u!=parent)
                return true;
        }
        return false;
    }
bool isCycle(int v, vector<int> adj[]) {
        bool visited[v];
        for(int i=0;i<v;i++)
            visited[i]=false;
        for(int j=0;j<v;j++){
            if(visited[j]==false){
                if(dfsrec(adj,j,-1,visited))
                    return true;
            }
        }
        return false;
}
int main(){
    int v=5;
    vector<int> adj[v];
    addEdge(adj,1, 0);
    //addEdge(adj,0, 2);
    //addEdge(adj,2, 1);
    //addEdge(adj,0, 3);
    //addEdge(adj,3, 4);
    print(adj,v);
    cout<<isCycle(v,adj);
    return 0;
}
