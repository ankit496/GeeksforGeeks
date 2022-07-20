#include<iostream>
using namespace std;
int maxevenodd(int a[],int n){
    int res=1;
    for(int i=0;i<n;i++){
        int crr=1;
        for(int j=i+1;j<n;j++){
            if((a[j]%2==0&&a[j-1]%2!=0)||(a[j]%2==0&&a[j-1]%2!=0)){
                crr++;
            }
            else{
                break;
            }
        }
        res=max(res ,crr);
    }
    return res;
}
int maxalternate(int a[],int n){
    int res=1;
    int cur=1;
    for(int i=1;i<n;i++){
        if((a[i]%2==0&&a[i-1]%2!=0)||(a[i]%2==0&&a[i-1]%2!=0))
            cur++;
        else
            cur=1;
        res=max(res,cur);
    }
    return res;
}
int main(){
    int a[]={5,10,20,6,3,8};
    cout<<maxevenodd(a,6)<<endl;
    cout<<maxalternate(a,6);
    return 0;
}
