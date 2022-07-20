#include<iostream>
#include<stack>
using namespace std;
int minimum=-1;
stack<int> s;
void push(int x){
    if(s.empty()){
        minimum=x;
        s.push(x);
    }
    /*else if(minimum>x){
        s.push(x-minimum);
        minimum=x;
    }*/
    else if(x<=minimum){
        s.push(2*x-minimum);
        minimum=x;
    }
    else{
        s.push(x);
    }
}
int peek(){
    int t=s.top();
    return t<=minimum?minimum:t;
}
int pop(){
    int t=s.top();
    s.pop();
    if(t<=0){
        int res=minimum;
        minimum=2*minimum-t;
        return res;
    }
    else{
        return t;
    }
}
int getmin(){
    return minimum;
}
int main(){
    push(24);
    push(45);
    cout<<getmin();
    push(67);
    push(87);
    push(7);
    push(-1);
    cout<<getmin();
    return 0;
}
