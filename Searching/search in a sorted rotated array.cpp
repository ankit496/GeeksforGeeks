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
int s_search(int a[],int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x)
            return mid;
        if(a[low]<a[mid]){
            if(x>=a[low]&&x<a[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        else{
            if(x>a[mid]&&x<=a[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}
int main(){
    int a[]={100,200,500,1000,2000,10,20};
    cout<<s_search(a,7,20);
    return 0;
}
