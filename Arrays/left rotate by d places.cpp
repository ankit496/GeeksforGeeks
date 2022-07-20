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
void lefrotate(int a[],int n,int d){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=a[i];
    }
    for(int i=d;i<n;i++){
        a[i-d]=a[i];
    }
    for(int i=0;i<d;i++){
        a[n-d+i]=temp[i];
    }
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
}
void reverse(int a[],int low,int high){
    while(low<high){
        swap(a[low],a[high]);
        low++;
        high--;
    }
}
void lrd(int a[],int n,int d){
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    int a[]={1,2,3,4,5};
    int n;
    cin>>n;
    leftrotatebyd(a,5,n);
    lefrotate(a,5,n);
    lrd(a,5,n);
    return 0;
}
