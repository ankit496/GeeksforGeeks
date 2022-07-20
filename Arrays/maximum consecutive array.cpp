#include<iostream>
using namespace std;
bool allone(int a[],int low,int high){
    for(int i=low;i<=high;i++){
        if(a[i]!=1)
            return false;
    }
    return true;
}
int maxone(int a[],int n){
    int max1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(allone(a,i,j)){
                max1=max(max1,j-i+1);
            }
        }
    }
    return max1;
}
int maxconsecutiveone(int a[],int n){
    int res=0;
    int cur=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
            cur=0;
        else{
            cur++;
            res=max(res,cur);
        }
    }
    return res;
}
int main(){
    int a[]={1,1,1,1,1,1,0};
    cout<<maxone(a,7)<<endl;
    cout<<maxconsecutiveone(a,7);
    return 0;
}
