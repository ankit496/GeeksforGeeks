#include<iostream>
#include<stack>
using namespace std;
void stock_span(int a[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int count=1;
        while(a[i]>a[j]&&j>=0){
            count++;
            j--;
        }
        cout<<count<<" ";
    }
}
void stock_span2(int a[],int n){
    stack<int> s;
    s.push(0);
    int span;
    cout<<"1 ";
    for(int i=1;i<n;i++){
        while(s.empty()==false&&a[s.top()]<=a[i]){
            s.pop();
        }
        span=s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
    }
}
int main(){
    int a[]={60,70,80,140,130,100,120,130,140};
    for(int i=0;i<9;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    stock_span(a,9);
    cout<<endl;
    stock_span2(a,9);
    return 0;
}
