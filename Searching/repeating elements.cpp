#include<iostream>
using namespace std;
int repeating_element(int a[],int n){
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++){
        if(visited[a[i]])
            return a[i];
        visited[a[i]]=true;
    }
    return -1;
}
int repeat(int a[],int n){
    int slow=0;
    int fast=0;
    do{
        slow=a[slow]+1;
        fast=a[fast]+1;
        fast=a[fast]+1;
    }while(slow!=fast);
    slow=a[0]+1;
    while(slow!=fast){
        slow=a[slow]+1;
        fast=a[fast]+1;
    }
    return slow-1;
}
int main(){
    int a[]={1,2,3,0,3,4,5};
    cout<<repeating_element(a,7)<<endl<<repeat(a,7);
    return 0;
}
