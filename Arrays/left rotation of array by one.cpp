#include<iostream>
using namespace std;
void leftrotate(int a[],int n){
    int i=0,j=1;
    while(j<n){
        swap(a[i++],a[j++]);
    }
    for(int k=0;k<n;k++)
        printf("%d ",a[k]);
}
int main(){
    int a[]={1,2,3,4,5};
    leftrotate(a,5);
    return 0;
}
