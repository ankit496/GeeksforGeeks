#include<iostream>
using namespace std;
bool isleader(int a[],int index,int n){
    for(int i=index;i<n;i++){
        if(a[index]<=a[i])
            return false;
    }
    return true;
}
void leader(int a[],int n){
    int cur_leader=a[n-1];
    cout<<cur_leader<<" ";
    for(int i=n-2;i>=0;i--){
        if(cur_leader<a[i]){
            cur_leader=a[i];
            cout<<cur_leader<<" ";
        }
    }
}
int main(){
    int a[]={7,10,4,3,6,5,2};
    int n=8;
    /*for(int i=0;i<n;i++){
        if(isleader(a,i,n))
           cout<<a[i]<<" ";
    }
    */
    leader(a,n);
    return 0;
}
