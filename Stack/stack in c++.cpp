#include<iostream>
#include<stack>
using namespace std;
//the functions in the library are:-
//push
//pop
//top
//size
//empty
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(35);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    return 0;
}
