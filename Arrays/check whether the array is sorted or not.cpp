#include<iostream>
using namespace std;
bool sorted(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1])
            return 0;
    }
    return 1;
}
int main(){
    int a[]={1,2,3,4,5};
    cout<<sorted(a,5);
    return 0;
}
