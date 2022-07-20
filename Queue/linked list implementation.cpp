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
struct queue{
    node* front;
    node* rear;
    queue(){
        front=NULL;
        rear=NULL;
    }
    void enque(int x){
        node *newnode=new node(x);
        if(front==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }
    int deque(){
        if(front==NULL)
            return -1;
        else{
            node* temp=front;
            int x=temp->data;
            front=front->next;
            if(front==NULL){
                rear=NULL;
            }
            free(temp);
            return x;
        }
    }
    void display(){
        while(front!=rear){
            cout<<front->data;
            front=front->next;
        }
    }
};
int main(){
    queue q;
    q.enque(5);
    q.enque(6);
    q.enque(6);
    //q.enque(6);
    cout<<q.deque();
    cout<<q.deque();
    cout<<q.deque();
    cout<<q.deque();
    return 0;
}
