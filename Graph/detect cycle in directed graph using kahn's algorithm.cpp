#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<int> adj[],int *indegree,int u,int v){
    adj[u].push_back(v);
    indegree[v]++;
}
bool cycle(vector<int> adj[],int *indegree,int v){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int count=0;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        count++;
        for(auto x:adj[u]){
            if(indegree[x]>0)
                indegree[x]--;
        }
        for(auto x:adj[u]){
            if(indegree[x]==0)
                q.push(x);
        }
    }
    if(count==v)
        return false;
    return true;
}
int main(){
    int v=5;
    vector<int> adj[v];
    int *indegree=new int[v];
    for(int i=0;i<v;i++)
        indegree[i]=0;
    addedge(adj,indegree,0,1);
    addedge(adj,indegree,1,2);
    addedge(adj,indegree,2,3);
    addedge(adj,indegree,3,1);
    addedge(adj,indegree,4,1);

    cout<<cycle(adj,indegree,v);
    return 0;
}

