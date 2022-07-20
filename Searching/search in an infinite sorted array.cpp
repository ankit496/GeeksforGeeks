#include<iostream>
int b_index=0;
using namespace std;
int index(int a[],int x){
    int low=0;
    int high=1;
    while(true){
        int mid=(a[low]+a[high])/2;
        if(mid<x){
            low++;
            high++;
        }
        else{
            if(x==a[low])
                return low;
            else
                return -1;
        }
    }
}
bool flag=false;
int binary_search(int a[],int x,int starting_index,int final_index){
    int mid=(starting_index+final_index)/2;
    if(starting_index>final_index)
        return -1;
    if(a[mid]==x){
        b_index=mid;
        flag=true;
        return b_index;
    }
    else if(a[mid]>x)
        binary_search(a,x,starting_index,mid-1);
    else if(a[mid]<x)
        binary_search(a,x,mid+1,final_index);
}
int search_index(int a[],int x){
    if(a[0]==x)
        return 0;
    int i=1;
    while(a[i]<x)
        i=i*2;
    if(a[i]==x)
        return i;
    return binary_search(a,x,i/2+1,i);
}
int main(){
    int a[]={1,10,15,20,40,80,90,100,120,150};
    cout<<index(a,100);
    cout<<search_index(a,100);
    return 0;
}
