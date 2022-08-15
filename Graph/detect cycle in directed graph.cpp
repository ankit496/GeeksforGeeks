#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}
bool dfsrec(vector<int> adj[],int s,bool rec[],bool visited[]){
        visited[s]=true;
        rec[s]=true;
        for(int u:adj[s]){
            if(visited[u]==false){
                if(dfsrec(adj,u,rec,visited))
                    return true;
            }
            else if(rec[u]==true)
                return true;
        }
        rec[s]=false;
        return false;
    }
bool isCycle(int v, vector<int> adj[]) {
        bool visited[v];
        bool rec[v];
        for(int i=0;i<v;i++){
            visited[i]=false;
            rec[i]=false;
        }
        for(int j=0;j<v;j++){
            if(visited[j]==false){
                if(dfsrec(adj,j,rec,visited))
                    return true;
            }
        }
        return false;
}
void print(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj[i]);
    }
}
int main(){
    int v=4;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    //addedge(adj,3,1);
    print(adj,v);
    cout<<isCycle(v,adj);
    return 0;
}
