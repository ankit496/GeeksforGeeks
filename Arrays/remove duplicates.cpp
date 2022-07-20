#include<iostream>
using namespace std;
int main(){
    int a[]={10,20,20,40,40};
    int temp[6];
    temp[0]=a[0];
    int res=1;
    for(int i=1;i<5;i++){
        if(temp[res-1]!=a[i]){
            temp[res]=a[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        a[i]=temp[i];
        printf("%d ",a[i]);
    }
    return 0;
}
