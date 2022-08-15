#include<iostream>
using namespace std;
void print(int g[][4],int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
}
int primMST(int g[][4],int v){
    int key[v];
    int res=0;
    key[0]=0;
    bool mSet[v];
    mSet[0]=false;
    for(int i=1;i<v;i++){
        key[i]=INT_MAX;
        mSet[i]=false;
    }
    for(int count=0;count<v;count++){
        int u=-1;
        for(int i=0;i<v;i++)
            if(mSet[i]==false&&(u==-1||key[i]<key[u]))
                u=i;
        mSet[u]=true;
        res=res+key[u];
        cout<<key[u]<<" ";
        for(int j=0;j<v;j++){
            if(g[u][j]!=0&&mSet[j]==false){
                key[j]=min(key[j],g[u][j]);
            }
        }
    }
    return res;
}
int main(){
    int v=4;
    int g[4][4]={{0,5,8,0},{5,0,10,0},{8,10,0,20},{0,15,20,0}};
    print(g,v);
    cout<<primMST(g,v);
    return 0;
}

