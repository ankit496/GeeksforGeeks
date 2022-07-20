#include<iostream>
using namespace std;
int last_occurence(int a[],int n){
    int x=1;
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
int first_occurence(int a[],int n){
    int x=1;
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
int count(int a[],int n){
    int first=first_occurence(a,n);
    if(first==-1)
        return 0;
    else
        return (last_occurence(a,n)-first+1);
}
int count_ones(int a[],int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==0)
            low=mid+1;
        else
            if(mid==0||a[mid-1]!=a[mid])
                return n-mid;
            else
                high=mid-1;
    }
}
int main(){
    int a[]={0,0,0,1,1,1,1};
    cout<<count(a,7);
    cout<<endl<<count_ones(a,7);
    return 0;
}

