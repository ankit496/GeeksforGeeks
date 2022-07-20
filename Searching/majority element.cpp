#include<iostream>
using namespace std;
int find_majority(int a[],int n){
    int count=1,res=0;
    //finding the majority element
    for(int i=1;i<n;i++){
        if(a[res]==a[0])
            count++;
        else
            count--;
        if(count==0){
            res=i;
            count=1;
        }
    }
    //checking whether the found element is majority or not
    count=0;
    for(int i=0;i<n;i++){
        if(a[res]==a[i])
            count++;
    }
    if(count<=n/2)
        return -1;
    else
        return res;
}
int main(){
    int a[]={8,3,4,8,8};
    cout<<find_majority(a,5);
    return 0;
}
