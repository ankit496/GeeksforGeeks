#include<iostream>
using namespace std;
//1.searching
int s(int a[],int n,int x){
    for(int i=0;i<n;i++)
        if(a[i]==x)
            return i;
    return -1;
}
//2.insertion
void inst(int a[],int n,int pos,int x){
    int index=pos-1;
    for(int i=n-1;i>=index;i--)
        a[i+1]=a[i];
    a[index]=x;
    for(int i=0;i<n+1;i++)
        cout<<a[i]<<" ";
}
//3.deletion
void del(int a[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        if(a[i]==x)
            break;
    for(int j=i;j<n-1;j++)
        a[i]=a[i+1];
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[6]={2,4,5,1,6};
    int x=5;
    cout<<s(a,5,x);
    inst(a,5,2,7);
    del(a,5,4);
    return 0;
}
