#include<iostream>
#include<stack>
using namespace std;
void previous_greater(int a[],int n){
    stack<int> s;
    cout<<"-1 ";
    s.push(a[0]);
    for(int i=1;i<n;i++){
        int x;
        if(a[i]<=s.top()){
            cout<<s.top()<<" ";
            s.push(a[i]);
        }
        else{
            while(s.empty()==false&&a[i]>s.top())
                s.pop();
            if(s.empty())
                cout<<"-1 ";
            else{
                cout<<s.top()<<" ";
            }
            s.push(a[i]);
        }
    }
}
int main(){
    int a[]={15,10,18,12,4,6,2,8};
    previous_greater(a,8);
    return 0;
}
