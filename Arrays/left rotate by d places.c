#include<iostream>
using namespace std;
void leftrotate(int a[],int n){
    int i=0,j=1;
    while(j<n){
        swap(a[i++],a[j++]);
    }

}
void leftrotatebyd(int a[],int n,int d){
    for(int i=1;i<=d;i++)
        leftrotate(a,n);
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
}
int main(){
    int a[]={1,2,3,4,5};
    int n;
    cin>>n;
    leftrotatebyd(a,5,n);
    return 0;
}
