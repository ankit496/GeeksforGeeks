#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<pair<int,int>> adj[],int u,int v,int weight,int *indegree){
    adj[u].push_back(make_pair(v,weight));
    indegree[v]++;
}
void print(vector<pair<int,int>> adj[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj[i])
            cout<<x.first<<" ";
        cout<<endl;
    }
}
void shortest_path(vector<pair<int,int>> adj[],int v,int *indegree){
    int dist[v];
    dist[0]=0;
    for(int i=1;i<v;i++)
        dist[i]=INT_MAX;
    queue<int> q;
    for(int i=0;i<v;i++)
        if(indegree[i]==0)
            q.push(i);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(indegree[x.first]>0)
                indegree[x.first]--;
            if(dist[x.first]>(dist[u]+x.second))
                dist[x.first]=dist[u]+x.second;
        }
        for(auto x:adj[u])
            if(indegree[x.first]==0)
                q.push(x.first);
    }
    for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
}
int main(){
    int v=6;
    vector<pair<int,int>> adj[v];
    int *indegree=new int(v);
    for(int i=0;i<v;i++)
        indegree[i]=0;
    addedge(adj,0,1,2,indegree);
    addedge(adj,0,4,1,indegree);
    addedge(adj,1,2,3,indegree);
    addedge(adj,2,3,6,indegree);
    addedge(adj,4,2,2,indegree);
    addedge(adj,4,5,4,indegree);
    addedge(adj,5,3,1,indegree);
    print(adj,v);
    shortest_path(adj,v,indegree);
    return 0;
}
