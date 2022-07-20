#include<iostream>
#include<stack>
using namespace std;
void next_greater_element(int a[],int n){
    for(int i=0;i<n-1;i++){
        int l=i+1;
        while(a[i]>=a[l]&&l<n)
            l++;
        if(l>=n)
            cout<<"-1 ";
        else{
            cout<<a[l]<<" ";
        }
    }
    cout<<"-1 ";
}
void nextgreater(int a[],int n){
    stack<int> s;
    s.push(a[n-1]);
    cout<<"-1 ";
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false&&a[i]>=s.top())
            s.pop();
        int nextg=(s.empty())?(-1):s.top();
        cout<<nextg<<" ";
        s.push(a[i]);
    }
}
int main(){
    int a[]={5,15,10,8,6,12,9,18};
    next_greater_element(a,8);
    cout<<endl;
    nextgreater(a,8);
    return 0;
}
