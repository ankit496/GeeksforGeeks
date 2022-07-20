#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
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
        if(s.empty())
            s.push(x);
        else if(x<s.top()){
            s.push(x);
        }
    }
    int pop(){
        int res=arr[top];
        if(res==s.top()){
            //pop both the element of the stack
            s.pop();
            top--;
        }
        else
            top--;
        return res;
    }
    int getmin(){
        return s.top();
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

int main(){
    mystack st(5);
    st.push(20);
    st.push(10);
    st.push(30);
    st.push(50);
    cout<<st.getmin()<<endl;
    st.push(5);
    cout<<st.getmin()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.getmin()<<endl;
    return 0;
}
