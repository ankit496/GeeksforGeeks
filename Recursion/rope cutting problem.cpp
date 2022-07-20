#include<iostream>
using namespace std;
int maximumcuts(int n,int a,int b,int c){
    if(n==0) return 0;
    if(n<0) return -1;
    int res=max(maximumcuts(n-a,a,b,c),maximumcuts(n-c,a,b,c));
    int res2=max(maximumcuts(n-a,a,b,c),maximumcuts(n-b,a,b,c));
    res=max(res,res2);
    if(res==-1)
        return -1;
    return res+1;
}
int main(){
    cout<<maximumcuts(23,11,9,12);
    return 0;
}
