#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reverse(queue<int> q){
    stack<int> aux_s;
    while(q.empty()==false){
        aux_s.push(q.front());
        q.pop();
    }
    while(aux_s.empty()==false){
        q.push(aux_s.top());
        aux_s.pop();
    }
    return q;
}

void reverse_recursive(queue<int> q){
    if(q.empty())
        return;
    int x=q.front();
    q.pop();
    reverse_recursive(q);
    cout<<x<<" ";
    q.push(x);
}
int main(){
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
//
//    while(q.empty()==false){
//        cout<<q.front()<<" ";
//        q.pop();
//    }
//    cout<<endl;
    q=reverse(q);
    while(q.empty()==false){
        cout<<q.front()<<" ";
        q.pop();
    }
    queue<int> q2;
    reverse_recursive(q2);
    q2.push(5);
    q2.push(6);
    q2.push(7);
    q2.push(8);
    reverse_recursive(q2);

    return 0;
}
