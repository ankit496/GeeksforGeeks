#include<iostream>
using namespace std;
int second_largest(int a[],int n){
    int res=-1,largest=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[largest]){
            res=largest;
            largest=i;
        }
        else if(a[i]!=a[largest]){
            if(res==-1||a[i]>a[res])
                res=i;
        }
    }
    return res;
}
int main(){
    int a[]={1,2,3,4,5};
    cout<<second_largest(a,5);
    return 0;
}
