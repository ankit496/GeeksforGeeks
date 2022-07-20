#include<iostream>
using namespace std;
int last_occurence(int a[],int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>x)
            high=mid-1;
        else if(a[mid]<x)
            low=mid+1;
        else{
            if(mid==n-1||a[mid+1]!=a[mid])
                return mid;
            else
                low=mid+1;
        }
    }
    return -1;
}
int first_occurence(int a[],int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>x)
            high=mid-1;
        else if(a[mid]<x)
            low=mid+1;
        else{
            if(mid==0||a[mid-1]!=a[mid])
                return mid;
            else
                high=mid-1;
        }
    }
    return -1;
}
int count(int a[],int n,int x){
    int first=first_occurence(a,n,x);
    if(first==-1)
        return 0;
    else
        return (last_occurence(a,n,x)-first+1);
}
int main(){
    int a[]={15,15,15};
    cout<<count(a,3,15);
    return 0;
}
