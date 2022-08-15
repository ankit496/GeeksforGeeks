#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<int> adj[],int *indegree,int u,int v){
    adj[u].push_back(v);
    indegree[v]++;
}
void topological_sort(vector<int> adj[],int *indegree,int v){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x:adj[u]){
            if(indegree[x]>0)
                indegree[x]--;
        }
        for(auto x:adj[u]){
            if(indegree[x]==0)
                q.push(x);
        }
    }
}
int main(){
    int v=5;
    vector<int> adj[v];
    int *indegree=new int[v];
    for(int i=0;i<v;i++)
        indegree[i]=0;
    addedge(adj,indegree,0,2);
    addedge(adj,indegree,0,3);
    addedge(adj,indegree,1,3);
    addedge(adj,indegree,1,4);
    addedge(adj,indegree,2,3);

    topological_sort(adj,indegree,v);
    return 0;
}
