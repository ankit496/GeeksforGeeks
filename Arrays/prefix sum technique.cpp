#include<iostream>
using namespace std;
int getsum(int prefix_sum[],int l,int r){
    if(r!=0)
        return prefix_sum[r]-prefix_sum[l-1];
    else
        return prefix_sum[0];
}
//it takes O(n) extra space and O(n) time complexity
int equilibrium(int prefix_sum[],int n){
    for(int i=1;i<n;i++){
        if(getsum(prefix_sum,0,i-1)==getsum(prefix_sum,i+1,n-1))
            return i;
    }
    return -1;
}
bool isequilibrium(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    int l_sum=0;
    for(int i=0;i<n;i++){
        if(l_sum==(sum-a[i]))
            return true;
        else
            l_sum+=a[i];
    }
    return false;
}
int main(){
    int a[]={3,4,8,-9,20,6};
    int n=sizeof(a)/sizeof(int);
    int prefix_sum[n];
    prefix_sum[0]=a[0];
    for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+a[i];
    }
    //cout<<getsum(prefix_sum,0,5);
    cout<<equilibrium(prefix_sum,n);
    cout<<isequilibrium(a,n);
    return 0;
}
