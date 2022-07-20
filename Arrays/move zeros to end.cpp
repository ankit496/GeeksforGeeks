#include<iostream>
using namespace std;
void movend(int a[],int n){
    int temp[n];
    int index=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0)
            temp[index++]=a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==0)
            temp[index++]=a[i];
    }

    for(int i=0;i<n;i++)
    printf("%d ",temp[i]);
}
void movezeros(int a[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[count]);
            count++;
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
int main(){
    int a[]={10,0,15,10,0,20};
    movend(a,6);
    cout<<endl;
    movezeros(a,6);

    return 0;
}
