#include<iostream>
using namespace std;
int last_occurence(int a[],int x,int low,int high){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(x>a[mid])
        return last_occurence(a,x,mid+1,high);
    else if(x<a[mid])
        return last_occurence(a,x,low,mid-1);
    else{
        if(mid==0||a[mid+1]!=a[mid])
            return mid;
        else
            return last_occurence(a,x,mid+1,high);
    }
}
//iteratve approach
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
int main(){
    int a[]={15,15,15};
    cout<<last_occurence(a,15,0,2)<<endl;
    cout<<last_occurence(a,3,15);
    return 0;
}
