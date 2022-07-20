#include<iostream>
using namespace std;
int getwater(int a[],int n){
    int res=0;
    for(int i=1;i<n-1;i++){
        int lmax=a[i];
        //finding the lmax and rmax
        for(int j=0;j<i;j++){
            lmax=max(lmax,a[j]);
        }
        int rmax=a[i];
        for(int k=i+1;k<n;k++){
            rmax=max(rmax,a[k]);
        }
        res=res+(min(lmax,rmax) -a[i]);
    }
    return res;
}
int getwa(int a[],int n){
    int res2=0;
    int lmax[n],rmax[n];
    lmax[0]=a[0];
    for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i],a[i]);
    rmax[n-1]=a[n-1];
    for(int j=n-1;j>=0;j--)
        rmax[j]=max(lmax[j],a[j]);
    for(int i=1;i<n-1;i++)
        res2=res2+(min(lmax[i],rmax[i]))-a[i];
    return res2;
}
int main(){
    int a[]={5,0,6,2,3};
    cout<<getwater(a,5)<<endl;
    cout<<getwa(a,5);
    return 0;
}
