#include<iostream>
using namespace std;
/*int minimumgroup(int a[],int n){
    int countzero=0,reszero=0;
    int beg_index=-1,final_index=-1;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            countzero=0;
        }
        else{
            countzero++;
        }
        final_index=i;
        reszero=max(countzero,reszero);
    }
    cout<<beg_index<<" "<<final_index;
    int countone=0,resone=0;
    for(int j=0;j<n;j++){
        if(a[j]!=1)
            countone=0;
        else{
            countone++;
        }
        resone=max(countone,resone);
    }
    int maxm=0;
    maxm=max(reszero,resone);
    return reszero;
}*/
void printGroups(bool a[],int n){
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            if(a[i]!=a[0])
                cout<<"from "<<i<<" to ";
            else
                cout<<(i-i)<<endl;
        }
    }
    if(a[n-1]!=a[0])
        cout<<(n-1)<<endl;
}

int main(){
    bool a[]={0,0,1,1,0,0,1,1,0};
    printGroups(a,9);
    return 0;
}
