#include<iostream>
using namespace std;
int index=-1;
bool flag=false;
int search(int a[],int x,int starting_index,int final_index){
    int mid=(starting_index+final_index)/2;
    if(starting_index>final_index)
        return -1;
    if(a[mid]==x){
        index=mid;
        flag=true;
        return index;
    }
    else if(a[mid]>x)
        search(a,x,starting_index,mid-1);
    else if(a[mid]<x)
        search(a,x,mid+1,final_index);
}
//iterative approach
int search_iterative(int a[],int x,int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x){
            low=0;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int a[]={10,20,30,40,50,60,70};
    cout<<search(a,100,0,6);
    cout<<" "<<search_iterative(a,60,7);
}
