#include<iostream>
#include<vector>
using namespace std;
struct mystack{
    int *arr;
    int cap;
    int top;
    mystack(int c){
        cap=c;//here cap means capacity
        arr=new int[cap];
        top=-1;
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int pop(){
        int res=arr[top];
        top--;
        return res;
    }
    int peek(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return (top==-1);
    }
};
struct vec_stack{
    vector<int> v;
    void push_back(int x){
        v.push_back(x);
    }
    int pop(){
        int res=v.back();
        v.pop_back();
        return res;
    }
};
class stack{
public:
    stack(int x){
        arr=new int(x);
        top=-1;
    }
    void push(int data);
    int pop();

private:
    int top;
    int *arr;
    int cap;
};
void stack::push(int data){
    top++;
    arr[top]=data;
}
int stack::pop(){
    int x=arr[top];
    top--;
    return x;
}
int main(){
    mystack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    stack s2(5);
    s2.push(5);
    s2.push(51);
    s2.push(55);
    cout<<s2.pop();
    vec_stack s3;
    s3.push_back(3);
    s3.push_back(5);
    s3.push_back(6);
    cout<<s3.pop();
    return 0;
}
