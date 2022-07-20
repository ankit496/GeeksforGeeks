#include<iostream>
#include<queue>
using namespace std;
struct stack{
    queue<int> q;
    queue<int> aux_q;
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
    int pop(){
        int x=q.front();
        int flag=1;
        q.pop();
        while(q.empty()==false){
            aux_q.push(q.front());
            q.pop();
        }
        while(aux_q.empty()==false){
            q.push(aux_q.front());
            aux_q.pop();
        }
        return x;
    }
    void push(int x){
        while(q.empty()==false){
            aux_q.push(q.front());
            q.pop();
        }
        q.push(x);
        while(aux_q.empty()==false){
            q.push(aux_q.front());
            aux_q.pop();
        }
    }
};
int main(){
    stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<s.pop();
    cout<<s.pop();
    return 0;
}
