#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
    struct node* prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
struct node* front=NULL;
struct node* rear=NULL;
void insertFront(int data){
    node* newnode=new node(data);
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        newnode->next=front;
        front->prev=newnode;
        front=newnode;
    }
}
void insertRear(int data){
    node* newnode=new node(data);
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
}
int getFront(){
    return front->data;
}
int getRear(){
    return rear->data;
}
int deleteFront(){
    int t=front->data;
    node* temp=front;
    front->next->prev=NULL;
    front=front->next;
    delete(temp);
    return t;
}
int deleteRear(){
    int t=rear->data;
    node* temp=rear;
    rear->prev->next=NULL;
    rear=rear->prev;
    delete(temp);
    return t;
}
int main(){
    insertFront(5);
    insertFront(6);
    insertFront(7);
    insertRear(8);
    insertRear(9);
    insertRear(10);
    cout<<getFront()<<" ";
    cout<<getRear()<<" ";

    return 0;
}


