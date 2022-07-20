#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
struct mystack{
    node* head;
    int size_of_stack;
    mystack(){
        head=NULL;
        size_of_stack=0;
    }
    void push(int x){
        node* newnode=new node(x);
        newnode->next=head;
        head=newnode;
        size_of_stack++;
    }
    int pop(){
        if(head==NULL)
            return -1;
        int res=head->data;
        node* del=head;
        head=head->next;
        delete(del);
        size_of_stack--;
        return res;
    }
    int size(){
        return size_of_stack;
    }
    bool isempty(){
        return size_of_stack==-1;
    }
    int peek(){
        if(head==NULL)
            return -1;
        return head->data;
    }
};
int main(){
    mystack s;
    s.push(34);
    s.push(35);
    s.push(36);
    s.push(37);
    cout<<s.pop();
    return 0;
}
